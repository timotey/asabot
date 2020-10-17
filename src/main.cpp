#include <experimental/coroutine>
#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>
#include <filesystem>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/asio/error.hpp>

namespace ip   = boost::asio::ip;
namespace asio = boost::asio;
namespace fs   = std::filesystem;

std::mutex global_cout_mutex;

///
///@brief this coroutine retrieves main page of site and outputs it into stdout
///
asio::awaitable<void>
http_query_task(ip::tcp::socket sock // programming sock, need another
)
{
	//	{
	//		std::lock_guard g{global_cout_mutex};
	//		std::cout << "this is coroutine print\n";
	//	}
	asio::streambuf request;
	asio::streambuf response;
	std::ostream	request_stream {&request};
	request_stream << "GET / HTTP/1.0\r\n";
	request_stream << "Accept: */*\r\n";
	request_stream << "Connection: close\r\n\r\n";

	//	{
	//		std::lock_guard g{global_cout_mutex};
	//		std::cout << "request constructed\n";
	//	}

	using buffer_iterator = boost::asio::buffers_iterator<
		boost::asio::streambuf::const_buffers_type>;
	co_await asio::async_write(sock, request, boost::asio::use_awaitable);
	//	{
	//		std::lock_guard g{global_cout_mutex};
	//		std::cout << "write\n";
	//	}

	// this could be co_await asio::async_read, but it cannot
	// accept asio::use_awaitable as a completion handler,
	// so you need to use asio::async_read_until with
	// condition which matches stream end
	auto match_end =
		+[](buffer_iterator begin,
			buffer_iterator end) -> std::pair<buffer_iterator, bool> {
		return std::make_pair(end, false);
	};
	while (true)
	{
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
			{
				throw e;
			}
			else
			{
				break;
			}
		}
	}
	//	{
	//		std::lock_guard g{global_cout_mutex};
	//		std::cout << "read\n";
	//	}

	std::istream response_stream {&response};
	// the output to stdout part
	{
		std::string line(std::istreambuf_iterator<char>(response_stream), {});
		std::lock_guard g {global_cout_mutex};
		std::cout << line << "\n";
	}
	//	{
	//		std::lock_guard g{global_cout_mutex};
	//		std::cout << "coroutine control finish\n";
	//	}
}

int
main(int argc, char* argv[])
{
	asio::io_context		 context;
	ip::tcp::resolver		 resolver(context);
	ip::tcp::resolver::query query("example.com", "http");
	ip::tcp::socket			 sock(context);

	// try to connect to server
	try
	{
		asio::connect(sock, resolver.resolve(query));
	}
	catch (const boost::system::system_error& e)
	{
		std::lock_guard g {global_cout_mutex};
		std::cout << e.what() << '\n';
		throw e;
	}

	// launching the coroutine
	asio::co_spawn(
		context,
		[socket = std::move(sock)]() mutable {
			return http_query_task(std::move(socket));
		},
		asio::detached);

	// making a thread which will run the asio context
	auto a = std::thread([&context]() {
		while (true)
		{
			try
			{
				context.run();
				break;
			}
			catch (const boost::system::system_error& e)
			{
				std::lock_guard g {global_cout_mutex};
				std::cout << "[" << boost::this_thread::get_id()
						  << "] exception caught: " << e.what() << '\n';
			}
		}
	});
	{
		std::lock_guard g {global_cout_mutex};
		std::cout << "this prints first\n";
	}
	context.run();
	std::cin.ignore();
	context.stop();
	a.join();
}
