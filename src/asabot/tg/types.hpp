#include <string>
#include <string_view>
#include <vector>
#include <variant>
#include <optional>
#include <memory>
#include <iostream>

namespace asabot::tg
{

using int_type = std::int_fast64_t;

class serialize
{
	template <>
	serialize()
}

struct user
{
	int_type	id;
	bool		is_bot;
	std::string first_name;
	std::string last_name;
	std::string username;
	std::string language_code;
	//friend std::ostream&
	//operator<<(std::ostream&, const user&);
	//friend std::istream&
	//operator>>(std::istream&, user&);
};

struct me
{
	user user;
	bool can_join_groups;
	bool can_trad_all_group_messages;
	bool supports_inline_queries;
	//friend std::ostream&
	//operator<<(std::ostream&, const me&);
	//friend std::istream&
	//operator>>(std::istream&, me&);
};

struct photo_size
{
	std::string				file_id;
	std::string				file_unique_id;
	int_type				width;
	int_type				height;
	std::optional<int_type> file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const photo_size&);
	//friend std::istream&
	//operator>>(std::istream&, photo_size&);
};

struct chat_photo
{
	std::string small_file_id;
	std::string small_file_unique_id;
	std::string big_file_id;
	std::string big_file_unique_id;
	//friend std::ostream&
	//operator<<(std::ostream&, const chat_photo&);
	//friend std::istream&
	//operator>>(std::istream&, chat_photo&);
};

struct animation
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const animation&);
	//friend std::istream&
	//operator>>(std::istream&, animation&);
};

struct audio
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const audio&);
	//friend std::istream&
	//operator>>(std::istream&, audio&);
};

struct document
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const document&);
	//friend std::istream&
	//operator>>(std::istream&, document&);
};

struct video
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const video&);
	//friend std::istream&
	//operator>>(std::istream&, video&);
};

struct video_note
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const video_note&);
	//friend std::istream&
	//operator>>(std::istream&, video_note&);
};

struct voice
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const voice&);
	//friend std::istream&
	//operator>>(std::istream&, voice&);
};

struct contact
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const contact&);
	//friend std::istream&
	//operator>>(std::istream&, contact&);
};

struct dice
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const dice&);
	//friend std::istream&
	//operator>>(std::istream&, dice&);
};

struct poll_option
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const poll_option&);
	//friend std::istream&
	//operator>>(std::istream&, poll_option&);
};

struct poll_answer
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const poll_answer&);
	//friend std::istream&
	//operator>>(std::istream&, poll_answer&);
};

struct poll
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const poll&);
	//friend std::istream&
	//operator>>(std::istream&, poll&);
};

struct location
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const location&);
	//friend std::istream&
	//operator>>(std::istream&, location&);
};

struct venue
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const venue&);
	//friend std::istream&
	//operator>>(std::istream&, venue&);
};

struct user_profile_photos
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const user_profile_photos&);
	//friend std::istream&
	//operator>>(std::istream&, user_profile_photos&);
};

struct file
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const file&);
	//friend std::istream&
	//operator>>(std::istream&, file&);
};

struct reply_keyboard_markup
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type	file_size;
	//friend std::ostream&
	//operator<<(std::ostream&, const reply_keyboard_markup&);
	//friend std::istream&
	//operator>>(std::istream&, reply_keyboard_markup&);
};

struct chat_channel;
struct chat_group;
struct chat_supergroup;
struct chat_private;
using chat =
	std::variant<chat_channel, chat_group, chat_supergroup, chat_private>;

struct message_entity
{
};

struct chat_permissions
{
};

struct message
{
	using text			   = std::string;
	using text_entities	   = std::vector<asabot::tg::message_entity>;
	using caption		   = text;
	using caption_entities = text_entities;
	using animation =
		std::tuple<asabot::tg::animation, caption, caption_entities>;
	using audio = std::tuple<asabot::tg::animation, caption, caption_entities>;
	using document =
		std::tuple<asabot::tg::animation, caption, caption_entities>;
	using photo = std::tuple<asabot::tg::animation, caption, caption_entities>;
	//	using sticker					= asabot::tg::sticker;
	using video = std::tuple<asabot::tg::animation, caption, caption_entities>;
	using video_note = asabot::tg::video_note;
	using voice = std::tuple<asabot::tg::animation, caption, caption_entities>;
	using contact = asabot::tg::contact;
	//	using dice						= asabot::tg::dice;
	//	using game						= asabot::tg::game;
	using poll = asabot::tg::poll;
	//	using venue						= asabot::tg::venue;
	//	using location					= asabot::tg::location;
	using new_chat_members		  = std::vector<asabot::tg::user>;
	using left_chat_member		  = asabot::tg::user;
	using new_chat_title		  = std::string;
	using new_chat_photo		  = std::vector<asabot::tg::photo_size>;
	using delete_chat_photo		  = std::true_type;
	using group_chat_created	  = std::true_type;
	using supergroup_chat_created = std::true_type;
	using channel_chat_created	  = std::true_type;
	using migrate_to_chat_id	  = asabot::tg::int_type;
	using migrate_from_chat_id	  = asabot::tg::int_type;
	using pinned_message		  = std::unique_ptr<asabot::tg::message>;
	//	using invoice					= asabot::tg::invoice;
	//	using successful_payment		= asabot::tg::successful_payment;
	//	using connected_website			= asabot::tg::connected_website;
	//	using passport_data				= asabot::tg::passport_data;

	int_type			  message_id;
	int_type			  date;
	std::unique_ptr<chat> chat;
	std::variant<
		asabot::tg::message::animation,
		asabot::tg::message::audio,
		asabot::tg::message::document,
		asabot::tg::message::photo,
		//			asabot::tg::message::sticker,
		asabot::tg::message::video,
		asabot::tg::message::video_note,
		asabot::tg::message::voice,
		asabot::tg::message::contact,
		//			asabot::tg::message::dice,
		//			asabot::tg::message::game,
		asabot::tg::message::poll,
		//			asabot::tg::message::venue,
		//			asabot::tg::message::location,
		asabot::tg::message::new_chat_members,
		asabot::tg::message::left_chat_member,
		asabot::tg::message::new_chat_title,
		asabot::tg::message::new_chat_photo,
		asabot::tg::message::delete_chat_photo,
		asabot::tg::message::group_chat_created,
		asabot::tg::message::supergroup_chat_created,
		asabot::tg::message::channel_chat_created,
		asabot::tg::message::migrate_to_chat_id,
		asabot::tg::message::migrate_from_chat_id,
		asabot::tg::message::pinned_message
		//			asabot::tg::message::invoice,
		//			asabot::tg::message::successful_payment,
		//			asabot::tg::message::connected_website,
		//			asabot::tg::message::passport_data
		>
		message;
	//friend std::ostream&
	//operator<<(std::ostream&, const asabot::tg::message&);
	//friend std::istream&
	//operator>>(std::istream&, asabot::tg::message&);
};

struct chat_private
{
	int_type						  id;
	constexpr static std::string_view type = "private";
	std::string						  username;
	std::string						  first_name;
	std::string						  last_name;
	chat_photo						  photo;
	//friend std::ostream&
	//operator<<(std::ostream&, const chat_private&);
	//friend std::istream&
	//operator>>(std::istream&, chat_private&);
};

struct chat_group
{
	int_type						  id;
	constexpr static std::string_view type = "group";
	std::string						  title;
	chat_photo						  photo;
	std::string						  description;
	std::string						  invite_link;
	message							  pinned_message;
	chat_permissions				  permissions;
	//friend std::ostream&
	//operator<<(std::ostream&, const chat_group&);
	//friend std::istream&
	//operator>>(std::istream&, chat_group&);
};

struct chat_supergroup
{
	int_type						  id;
	constexpr static std::string_view type = "supergroup";
	std::string						  title;
	std::string						  username;
	chat_photo						  photo;
	std::string						  description;
	std::string						  invite_link;
	message							  pinned_message;
	chat_permissions				  permissions;
	std::optional<int_type>			  slow_mode_delay;
	std::string						  sticker_set_name;
	bool							  can_set_sticker_set;
	//friend std::ostream&
	//operator<<(std::ostream&, const chat_supergroup&);
	//friend std::istream&
	//operator>>(std::istream&, chat_supergroup&);
};

struct chat_channel
{
	int_type						  id;
	constexpr static std::string_view type = "private";
	std::string						  title;
	std::string						  username;
	chat_photo						  photo;
	std::string						  description;
	std::string						  invite_link;
	message							  pinned_message;
	chat_permissions				  permissions;
	//friend std::ostream&
	//operator<<(std::ostream&, const chat_channel&);
	//friend std::istream&
	//operator>>(std::istream&, chat_channel&);
};

using chat =
	std::variant<chat_channel, chat_group, chat_supergroup, chat_private>;

struct update
{
	struct message
	{
		asabot::tg::message m;
	};

	struct edited_message
	{
		asabot::tg::message m;
	};

	struct channel_post
	{
		asabot::tg::message m;
	};

	struct edited_channel_post
	{
		asabot::tg::message m;
	};

	int_type update_id;
	std::variant<message, edited_message, channel_post, edited_channel_post> update;

};

} // namespace asabot::tg
