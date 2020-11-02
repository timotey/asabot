#include "types.hpp"

namespace asabot::tg

{

struct get_updates
{
	using response_type = asabot::tg::array<asabot::tg::update>;
	constexpr static std::string_view name = "getUpdates";
	std::optional<int_type> offset;
	int_type limit = 100;
	int_type timeout = 0;
	std::vector<std::string_view> allowed_updates;
};

}
