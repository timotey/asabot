#include <boost/asio.hpp>
#include <functional>
#include <iostream>
#include "core/resource_pool.hpp"

class on_scope_exit
{
	std::function<void()> f;

	public:
	on_scope_exit(std::function<void()> _f): f(_f)
	{
	}
	~on_scope_exit()
	{
		f();
	}
};

namespace asabot
{
namespace asio = boost::asio;

template<class bot_type, class request_type>
std::future<typename request_type::response_type>
perform_request(bot_type & bot, request_type request)
{
	std::promise<typename request_type::response_type> coro_promise {};
	auto return_future = coro_promise.get_future();
	asio::co_spawn(
	    bot.io_context,
	    [&bot, &request, coro_promise = std::move(coro_promise)]() mutable {
		    return bot_type::perform_request(
		        bot,
		        request,
		        std::move(coro_promise));
	    },
	    asio::detached);
	return return_future;
}

template<class bot_type>
void
start(bot_type & bot, std::size_t thread_count)
{
	if (!bot.threads.size())
		for (size_t i = 0; i < thread_count; ++i)
			bot.threads.push_back(std::thread {[&bot]() {
				// on_scope_exit g {[]() {
				//	std::cout << "[" << std::this_thread::get_id()
				//			  << "] spin down\n";
				//}};
				while (true)
				{
					try
					{
						bot.io_context.run();
						break;
					}
					catch (const boost::system::system_error & e)
					{
						std::cerr << "[" << std::this_thread::get_id()
						          << "] exception caught: " << e.what() << '\n';
					}
					catch (...)
					{
						std::cerr << "[" << std::this_thread::get_id()
						          << "] unknown exception\n";
						throw;
					}
				}
			}});
}

template<class bot_type>
void
stop(bot_type & bot)
{
	bot.io_context.stop();
}

template<class bot_type>
void
join(bot_type & bot)
{
	for (auto & t : bot.threads)
		if (t.joinable())
			t.join();
}

} // namespace asabot
