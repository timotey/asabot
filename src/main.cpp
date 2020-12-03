#include <iostream>
#include <fstream>
#include <string_view>
#include "asabot/tg.hpp"

namespace ip   = boost::asio::ip;
namespace asio = boost::asio;
namespace fs   = std::filesystem;

std::mutex global_cout_mutex;

struct mock_request
{
	struct response_type
	{
		std::string payload;
		friend std::istream &
		operator>>(std::istream & s, response_type & t)
		{
			t.payload = std::string {std::istreambuf_iterator<char>(s), {}};
			return s;
		}
	};
	static constexpr std::string_view name = "getUpdates";
	std::string                       payload;
	friend std::ostream &
	operator<<(std::ostream & s, const mock_request & t)
	{
		return s << t.payload;
	}
};

int
main(int, char *[])
{
	asabot::tg::longpoll_bot bot {[](std::string_view file) {
		std::ifstream keyfile {file};
		std::string   key;
		keyfile >> key;
		return key;
	}("key")};

	mock_request req {.payload = "{\"timeout\" : 100}"};

	std::cin.ignore();
	asabot::start(bot, 2);
	auto ret_future = asabot::perform_request(bot, req);
	try
	{
		auto r = ret_future.get();
		std::cout << "\r\n" << r.payload << "\n\r\n\r";
	}
	catch (const boost::system::system_error & e)
	{
		std::cout << e.code().message() << "\n" << e.what() << "\n";
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	auto ret_future2 = asabot::perform_request(bot, req);
	try
	{
		auto r2 = ret_future2.get();
		std::cout << "\r\n" << r2.payload << "\n\r\n\r";
	}
	catch (const boost::system::system_error & e)
	{
		std::cout << e.code().message() << "\n" << e.what() << "\n";
	}
	std::cin.ignore();
	asabot::stop(bot);
	asabot::join(bot);
}
