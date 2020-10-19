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
		friend std::istream&
		operator>>(std::istream& s, response_type t)
		{
			t.payload = std::string {std::istreambuf_iterator<char>(s), {}};
			return s;
		}
	};
	static constexpr std::string_view name = "getMe";
	std::string						  payload;
	friend std::ostream&
	operator<<(std::ostream& s, mock_request t)
	{
		return s << t.payload;
	}
};

int
main(int argc, char* argv[])
{
	asabot::tg::longpoll_bot bot {[](std::string_view file) {
		std::ifstream keyfile {file};
		std::string	  key;
		keyfile >> key;
		return key;
	}("key")};

	mock_request r;

	auto ret_future =
		asabot::perform_request<asabot::tg::longpoll_bot, mock_request>(bot, r);
	asabot::start(bot, 2);
	try
	{
		std::cout << ret_future.get().payload << '\n';
	}
	catch(...)
	{}
	std::cin.ignore();
	asabot::stop(bot);
	asabot::join(bot);
}
