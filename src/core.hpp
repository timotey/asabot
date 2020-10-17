#include <string_view>
#include <future>
#include <boost/asio.hpp>

namespace asabot::tg
{
///
///@brief the main bot class which handles the communication to telegram
///
///
///
///
class longpoll_bot
{
	using asio = boost::asio;

	const std::string		token;
	asio::io_context		io_context;
	asio::ssl::context		ssl_cintext;
	asio::ip::tcp::resolver reslover;
	asio::ip::tcp::query	query;

	template <class request_type>
	friend asio::awaitable<request_type::response_type>
	internal::perform_request(longpoll_bot&, const request_type request);

	public:
	///
	///@brief the constructor
	///@param[in]	token	telegram bot token used for api authentication
	///
	longpoll_bot(std::string_view token);
}

namespace internal
{
	using asio = boost::asio;

	template <class request_type>
	asio::awaitable<request_type::response_type> perform_request(
		longpoll_bot & bot,
		const request_type request)
	{
		namespace ssl		= asio::ssl;
		namespace tcp		= asio::ip::tcp;
		using ssl_socket	= ssl::stream<asio::ip::tcp::socket>;
		using response_type = request_type::response_type;

		ssl_socket sock {bot.io_context, bot.ssl_context};
		co_await asio::async_connect(
			sock.lowest_layer(),
			bot.resolver.resolve(bot.query),
			asio::use_awaitable);

		/* construct the HTTP request */
		asio::streambuf request;
		std::ostream	request_stream(&request);
		request_stream << "GET /" << bot.token() << "/" << request::name
					   << " HTTP/1.0\r\n";
		request_stream << "Connection: close\r\n\r\n";
		request_stream << request;

		/* send the HTTP request */
		co_await asio::async_write(sock, request, asio::use_awaitable);

		/* recieve the HTTP request */
		// this could be co_await asio::async_read, but it cannot
		// accept asio::use_awaitable as a completion handler,
		// so you need to use asio::async_read_until with
		// condition which matches stream end
		auto match_end =
			+[](buffer_iterator begin,
				buffer_iterator end) -> std::pair<buffer_iterator, bool> {
			return std::make_pair(end, false);
		};
		asio::streambuf response;
		std::istream	response_stream(*response);
		try
		{
			co_await asio::async_read_until(
				sock,
				response,
				match_end,
				boost::asio::use_awaitable);
		}
		catch (const boost::system::system_error& e)
		{
			if (e.code() != asio::error::eof)
				throw e; // rethrow if it's really an exception
		}
		/* end of recieve the HTTP request */

		/* deserealization of the HTTP request */
		// TODO: implement deserialization part
		{
			std::string line(
				std::istreambuf_iterator<char>(response_stream),
				{});
			std::lock_guard g {global_cout_mutex};
			std::cout << line << "\n";
		}
		co_return response_type {};
	}
}

} // namespace asabot::tg
