#ifdef ASABOT_TG_USE_VARIANT
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "types-variant.hpp"

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
	for (auto const& val : )
	{
	}

	switch (std::hash<std::string> {}(type))
	{
		case std::hash<std::string_view> {}("animation"):
		{
			asabot::tg::message::animation m;
			deserialize(m, t_src.get_child("animation"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("audio"):
		{
			asabot::tg::message::audio m;
			deserialize(m, t_src.get_child("audio"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("photo"):
		{
			asabot::tg::message::photo m;
			deserialize(m, t_src.get_child("photo"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("sticker"):
		{
			asabot::tg::message::sticker m;
			deserialize(m, t_src.get_child("sticker"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("video"):
		{
			asabot::tg::message::video m;
			deserialize(m, t_src.get_child("video"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("video_note"):
		{
			asabot::tg::message::video_note m;
			deserialize(m, t_src.get_child("video_note"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("voice"):
		{
			asabot::tg::message::voice m;
			deserialize(m, t_src.get_child("voice"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("contact"):
		{
			asabot::tg::message::contact m;
			deserialize(m, t_src.get_child("contact"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("dice"):
		{
			asabot::tg::message::dice m;
			deserialize(m, t_src.get_child("dice"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("game"):
		{
			asabot::tg::message::game m;
			deserialize(m, t_src.get_child("game"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("poll"):
		{
			asabot::tg::message::poll m;
			deserialize(m, t_src.get_child("poll"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("venue"):
		{
			asabot::tg::message::venue m;
			deserialize(m, t_src.get_child("venue"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("location"):
		{
			asabot::tg::message::location m;
			deserialize(m, t_src.get_child("location"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("new_chat_members"):
		{
			asabot::tg::message::new_chat_members m;
			deserialize(m, t_src.get_child("new_chat_members"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("left_chat_member"):
		{
			asabot::tg::message::left_chat_member m;
			deserialize(m, t_src.get_child("left_chat_member"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("new_chat_title"):
		{
			asabot::tg::message::new_chat_title m;
			deserialize(m, t_src.get_child("new_chat_title"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("new_chat_photo"):
		{
			asabot::tg::message::new_chat_photo m;
			deserialize(m, t_src.get_child("new_chat_photo"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("delete_chat_photo"):
		{
			asabot::tg::message::delete_chat_photo m;
			deserialize(m, t_src.get_child("delete_chat_photo"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("group_chat_created"):
		{
			asabot::tg::message::group_chat_created m;
			deserialize(m, t_src.get_child("group_chat_created"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("supergroup_chat_created"):
		{
			asabot::tg::message::supergroup_chat_created m;
			deserialize(m, t_src.get_child("supergroup_chat_created"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("channel_chat_created"):
		{
			asabot::tg::message::channel_chat_created m;
			deserialize(m, t_src.get_child("channel_chat_created"));
			t_message.msg = std::move(m);
		}
		break;
		//case std::hash<std::string_view> {}("migrate_to_chat_id"):
		//{
		//	asabot::tg::message::audio m;
		//	deserialize(m, t_src.get_child("migrate_to_chat_id"));
		//	t_message.msg = std::move(m);
		//}
		break;
		case std::hash<std::string_view> {}("pinned_message"):
		{
			asabot::tg::message::pinned_message m;
			deserialize(m, t_src.get_child("pinned_message"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("successful_payment"):
		{
			asabot::tg::message::invoice m;
			deserialize(m, t_src.get_child("successful_payment"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("connected_website"):
		{
			asabot::tg::message::connected_website m;
			deserialize(m, t_src.get_child("connected_website"));
			t_message.msg = std::move(m);
		}
		break;
		case std::hash<std::string_view> {}("passport_data"):
		{
			asabot::tg::message::passport_data m;
			deserialize(m, t_src.get_child("passport_data"));
			t_message.msg = std::move(m);
		}
		break;
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

#endif
