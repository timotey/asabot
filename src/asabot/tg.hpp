#include <string_view>
#include <future>
#include <thread>
#include <exception>
#include <experimental/coroutine>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include "core.hpp"

namespace asabot
{
namespace tg
{
namespace asio = boost::asio;

///
///@brief the main bot class which handles the communication to telegram
///
///
///
///
class longpoll_bot
{
	public:
	const std::string			   token;
	asio::io_context			   io_context;
	asio::ssl::context			   ssl_context;
	asio::ip::tcp::resolver		   resolver;
	asio::ip::tcp::resolver::query query;
	std::vector<std::thread>	   threads;

	template <class bot_type>
	friend void
	asabot::start(bot_type&, std::size_t);
	template <class bot_type>
	friend void
	asabot::stop(bot_type&);
	template <class bot_type>
	friend void
	asabot::join(bot_type&);
	template <class bot_type, class request_type>
	friend std::future<typename request_type::response_type>
	perform_request(bot_type& bot, request_type&& request);

	template <class request_type>
	static asio::awaitable<void>
	perform_request(
		longpoll_bot&									   bot,
		const request_type								   request,
		std::promise<typename request_type::response_type> result)
	{
		namespace ssl		= asio::ssl;
		using ssl_socket	= ssl::stream<asio::ip::tcp::socket>;
		using response_type = typename request_type::response_type;

		try
		{
			/* connect to the host */
			ssl_socket sock {bot.io_context, bot.ssl_context};
			co_await asio::async_connect(
				sock.lowest_layer(),
				bot.resolver.resolve(bot.query),
				asio::use_awaitable);

			/* perform tls handshake */
			sock.lowest_layer().set_option(asio::ip::tcp::no_delay(true));
			sock.set_verify_mode(ssl::verify_peer);
			sock.set_verify_callback(
				ssl::host_name_verification("api.telegram.org"));
			co_await sock.async_handshake(
				ssl_socket::client,
				asio::use_awaitable);

			/* construct the HTTP request */
			asio::streambuf request_buf;
			std::ostream	request_stream(&request_buf);
			request_stream << "GET /bot" << bot.token << "/" << request_type::name
						   << " HTTP/1.1\r\n";
			request_stream << "Host: api.telegram.org\r\n";
			request_stream << "Connection: close\r\n\r\n";
			request_stream << request;

			/* send the HTTP request */
			co_await asio::async_write(sock, request_buf, asio::use_awaitable);

			/* recieve the HTTP request */
			// this could be co_await asio::async_read, but it cannot
			// accept asio::use_awaitable as a completion handler,
			// so you need to use asio::async_read_until with
			// condition which matches stream end
			using buffer_iterator = boost::asio::buffers_iterator<
				boost::asio::streambuf::const_buffers_type>;
			auto match_end =
				+[](buffer_iterator begin,
					buffer_iterator end) -> std::pair<buffer_iterator, bool> {
				return std::make_pair(end, false);
			};
			asio::streambuf response_buf;
			std::istream	response_stream(&response_buf);
			try
			{
				co_await asio::async_read_until(
					sock,
					response_buf,
					match_end,
					boost::asio::use_awaitable);
			}
			catch (const boost::system::system_error& e)
			{
				if (e.code() == ssl::error::stream_errors::stream_truncated)
				{
					std::cout << e.what();
				}
				else
				if (e.code() != asio::error::eof)
					throw; // rethrow if it's really an exception
			}
			/* end of recieve the HTTP request */

			/* deserealization of the HTTP request */
			// TODO: implement deserialization part
			response_type response;
			response_stream >> response;
			result.set_value(response);
			sock.shutdown();
			co_return;
		}
		catch (...)
		{
			result.set_exception(std::current_exception());
		}
	}

	public:
	///
	///@brief the constructor
	///@param[in]	token	telegram bot token used for api authentication
	///
	longpoll_bot(std::string_view _token):
		token(_token), io_context(), ssl_context(asio::ssl::context::tls),
		resolver(this->io_context), query("api.telegram.org", "https")
	{
		this->ssl_context.set_default_verify_paths();
	}
};

} // namespace tg

} // namespace asabot
