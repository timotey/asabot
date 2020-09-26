#include "types.hpp"
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	std::cout << sizeof(obl::tgbot::message);
}

