#include <string_view>
#include <future>
#include <exception>
#include <experimental/coroutine>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include "core.hpp"
#include "tg/types.hpp"

namespace asabot
{
namespace tg
{
namespace asio = boost::asio;
namespace http = boost::beast::http;

///
///@brief the main bot class which handles the communication to telegram
///
///
///
///
class longpoll_bot
{
	struct request_context
	{
		asio::ssl::stream<asio::ip::tcp::socket> sock;
		// asio::ssl::context						 ctx;
	};

	struct common_settings
	{
		asio::ip::tcp::resolver::query query;
	};

	public:
	std::string const                                          token;
	asio::io_context                                           io_context;
	asio::ssl::context                                         ssl_context;
	asio::ip::tcp::resolver                                    resolver;
	std::vector<std::thread>                                   threads;
	resource_repo<request_context>                             socks;
	asio::executor_work_guard<asio::io_context::executor_type> work;

	static common_settings const &
	get_common_settings()
	{
		static common_settings const s {{"api.telegram.org", "https"}};
		return s;
	}

	public:
	template<class bot_type>
	friend void
	asabot::start(bot_type &, std::size_t);

	template<class bot_type>
	friend void
	asabot::stop(bot_type &);

	template<class bot_type>
	friend void
	asabot::join(bot_type &);

	template<class bot_type, class request_type>
	friend std::future<typename request_type::response_type>
	perform_request(bot_type & bot, request_type && request);

	template<class request_type>
	static asio::awaitable<void>
	perform_request(
	    longpoll_bot &                                     t_bot,
	    const request_type                                 t_request,
	    std::promise<typename request_type::response_type> t_result)
	{
		namespace ssl       = asio::ssl;
		using response_type = typename request_type::response_type;

		try
		{
			/* connect to the host */
			auto sock = t_bot.socks.lock();

			/* construct the HTTP request */
			std::stringstream body_stream;
			body_stream << t_request;

			http::request<http::string_body> request;
			request.method(http::verb::get);
			request.keep_alive(true);
			{
				using namespace std::string_literals;
				request.target(
				    "/bot"s + t_bot.token + "/"s +
				    static_cast<std::string>(request_type::name));
			}
			request.set(
			    http::field::host,
			    longpoll_bot::get_common_settings().query.host_name());
			request.set(http::field::content_type, "application/json");
			request.body() = body_stream.str();
			request.prepare_payload();

			/* send the HTTP request */
			co_await http::async_write(
			    sock->sock,
			    request,
			    asio::use_awaitable);

			/* recieve the HTTP request */
			http::response<http::string_body> http_response;
			boost::beast::flat_buffer         buf;
			co_await http::async_read(
			    sock->sock,
			    buf,
			    http_response,
			    boost::asio::use_awaitable);
			/* end of recieve the HTTP request */

			/* deserealization of the HTTP request */
			std::istringstream response_stream {http_response.body()};
			response_type      response;
			response_stream >> response;
			t_result.set_value(response);
			co_return;
		}
		catch (...)
		{
			t_result.set_exception(std::current_exception());
		}
	}

	public:
	///
	///@brief the constructor
	///@param[in]	token	telegram bot token used for api authentication
	///
	explicit longpoll_bot(std::string_view _token):
	    token(_token), io_context(), ssl_context(asio::ssl::context::tls),
	    resolver(this->io_context), // query("api.telegram.org", "https")

	    /* initializing our request context container with a factory function
	       which will produce ready to use sockets */
	    // TODO: make this function asynchronyous
	    socks([this]() -> request_context {
		    using ssl_socket = asio::ssl::stream<asio::ip::tcp::socket>;
		    longpoll_bot::request_context sock {
		        {this->io_context, this->ssl_context}};

		    /* attempting to connect to the server */
		    asio::connect(
		        sock.sock.lowest_layer(),
		        this->resolver.resolve(
		            longpoll_bot::get_common_settings().query));

		    /* perform tls handshake */
		    sock.sock.lowest_layer().set_option(asio::ip::tcp::no_delay(true));
		    sock.sock.set_verify_mode(asio::ssl::verify_peer);
		    sock.sock.set_verify_callback(asio::ssl::host_name_verification(
		        longpoll_bot::get_common_settings().query.host_name()));
		    sock.sock.handshake(ssl_socket::client);
		    return sock;
	    }),

	    work(this->io_context.get_executor())
	{
		this->ssl_context.set_default_verify_paths();
	}
};

} // namespace tg

} // namespace asabot
