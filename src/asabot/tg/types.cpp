#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "types.hpp"

namespace pt = boost::property_tree;

void
deserialize(asabot::tg::chat& t_chat, pt::ptree const& t_src)
{
}
void
deserialize(asabot::tg::message& t_message, pt::ptree const& t_src)
{
	t_message.message_id = t_src.get<asabot::tg::int_type>("message_id");
	t_message.date		 = t_src.get<asabot::tg::int_type>("date");
	auto chat			 = std::make_unique<asabot::tg::chat>();
	deserialize(*chat, t_src.get_child("chat"));
	t_message.chat = std::move(chat);
	if (auto const& a = t_src.get_child_optional(""))
	{
	//	asabot::tg::message::animation m;
	//	deserialize(m, a);
	//	t_message.msg = std::move(m);
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
	else if (auto const& a = t_src.get_child_optional(""))
	{
	}
}

void
deserialize(asabot::tg::update& t_update, pt::ptree const& t_src)
{
	t_update.update_id = t_src.get<asabot::tg::int_type>("update_id");
	if (auto const& a = t_src.get_child_optional("message"))
	{
		asabot::tg::update::message m;
		deserialize(m.m, a.get());
		t_update.update = std::move(m);
	}
	else if (auto const& a = t_src.get_child_optional("edited_message"))
	{
		asabot::tg::update::message m;
		deserialize(m.m, a.get());
		t_update.update = std::move(m);
	}
	else if (auto const& a = t_src.get_child_optional("channel_post"))
	{
		asabot::tg::update::message m;
		deserialize(m.m, a.get());
		t_update.update = std::move(m);
	}
	else if (auto const& a = t_src.get_child_optional("edited_channel_post"))
	{
		asabot::tg::update::message m;
		deserialize(m.m, a.get());
		t_update.update = std::move(m);
	}
	// else if(auto const& a = t_src.get_child_optional("inline_query"))
	//{
	//	asabot::tg::update::message m;
	//	deserialize(m.m, a.get());
	//	t_update.update = std::move(m);
	//}
	// else if(auto const& a = t_src.get_child_optional("chosen_inline_query"))
	//{
	//	asabot::tg::update::message m;
	//	deserialize(m.m, a.get());
	//	t_update.update = std::move(m);
	//}
	// else if(auto const& a = t_src.get_child_optional("callback_query"))
	//{
	//	asabot::tg::update::message m;
	//	deserialize(m.m, a.get());
	//	t_update.update = std::move(m);
	//}
	// else if(auto const& a = t_src.get_child_optional("shipping_query"))
	//{
	//	asabot::tg::update::message m;
	//	deserialize(m.m, a.get());
	//	t_update.update = std::move(m);
	//}
	// else if(auto const& a = t_src.get_child_optional("poll"))
	//{
	//	asabot::tg::update::message m;
	//	deserialize(m.m, a.get());
	//	t_update.update = std::move(m);
	//}
	// else if(auto const& a = t_src.get_child_optional("poll_answer"))
	//{
	//	asabot::tg::update::message m;
	//	deserialize(m.m, a.get());
	//	t_update.update = std::move(m);
	//}
}

template <class T>
void
deserialize(std::vector<T>& t_vals, pt::ptree const& t_src)
{
	T val;
	for (auto const& src : t_src)
	{
		deserialize(val, src.second);
		t_vals.push_back(std::move(val));
	}
}

std::istream&
operator>>(std::istream& s, std::vector<asabot::tg::update>& t_updates)
{
	pt::ptree pt;
	pt::read_json(s, pt);
	deserialize(t_updates, pt);
	return s;
}
