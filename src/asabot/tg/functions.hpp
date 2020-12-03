#include "types.hpp"

namespace asabot::tg

{
struct get_updates
{
	using result_type                      = std::vector<asabot::tg::update>;
	constexpr static std::string_view name = "getUpdates";
	int_type              offset;
	int_type              limit;
	duration_type timeout = duration_type::zero();
	std::vector<std::string>  allowed_updates;
};

} // namespace asabot::tg
