#ifdef ASABOT_TG_USE_VARIANT

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

struct user
{
	int_type    id;
	bool        is_bot;
	std::string first_name;
	std::string last_name;
	std::string username;
	std::string language_code;
	friend std::ostream &
	operator<<(std::ostream &, const user &);
	friend std::istream &
	operator>>(std::istream &, user &);
};

struct me
{
	user user;
	bool can_join_groups;
	bool can_trad_all_group_messages;
	bool supports_inline_queries;
	friend std::ostream &
	operator<<(std::ostream &, const me &);
	friend std::istream &
	operator>>(std::istream &, me &);
};

struct photo_size
{
	std::string             file_id;
	std::string             file_unique_id;
	int_type                width;
	int_type                height;
	std::optional<int_type> file_size;
	friend std::ostream &
	operator<<(std::ostream &, const photo_size &);
	friend std::istream &
	operator>>(std::istream &, photo_size &);
};

struct chat_photo
{
	std::string small_file_id;
	std::string small_file_unique_id;
	std::string big_file_id;
	std::string big_file_unique_id;
	friend std::ostream &
	operator<<(std::ostream &, const chat_photo &);
	friend std::istream &
	operator>>(std::istream &, chat_photo &);
};

struct animation
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const animation &);
	friend std::istream &
	operator>>(std::istream &, animation &);
};

struct audio
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const audio &);
	friend std::istream &
	operator>>(std::istream &, audio &);
};

struct document
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const document &);
	friend std::istream &
	operator>>(std::istream &, document &);
};

struct video
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const video &);
	friend std::istream &
	operator>>(std::istream &, video &);
};

struct video_note
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const video_note &);
	friend std::istream &
	operator>>(std::istream &, video_note &);
};

struct voice
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const voice &);
	friend std::istream &
	operator>>(std::istream &, voice &);
};

struct contact
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const contact &);
	friend std::istream &
	operator>>(std::istream &, contact &);
};

struct dice
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const dice &);
	friend std::istream &
	operator>>(std::istream &, dice &);
};

struct poll_option
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const poll_option &);
	friend std::istream &
	operator>>(std::istream &, poll_option &);
};

struct poll_answer
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const poll_answer &);
	friend std::istream &
	operator>>(std::istream &, poll_answer &);
};

struct poll
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const poll &);
	friend std::istream &
	operator>>(std::istream &, poll &);
};

struct location
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const location &);
	friend std::istream &
	operator>>(std::istream &, location &);
};

struct venue
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const venue &);
	friend std::istream &
	operator>>(std::istream &, venue &);
};

struct user_profile_photos
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const user_profile_photos &);
	friend std::istream &
	operator>>(std::istream &, user_profile_photos &);
};

struct file
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const file &);
	friend std::istream &
	operator>>(std::istream &, file &);
};

struct reply_keyboard_markup
{
	std::string file_id;
	std::string file_unique_id;

	std::string file_name;
	std::string mime_type;
	int_type    file_size;
	friend std::ostream &
	operator<<(std::ostream &, const reply_keyboard_markup &);
	friend std::istream &
	operator>>(std::istream &, reply_keyboard_markup &);
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
	int_type                            message_id;
	int_type                            date;
	std::unique_ptr<chat>               chat;
	asabot::tg::animation               a01;
	asabot::tg::audio                   a02;
	asabot::tg::document                a03;
	asabot::tg::photo                   a04;
	asabot::tg::sticker                 a05;
	asabot::tg::video                   a06;
	asabot::tg::video_note              a07;
	asabot::tg::voice                   a08;
	asabot::tg::contact                 a09;
	asabot::tg::dice                    a10;
	asabot::tg::game                    a11;
	asabot::tg::poll                    a12;
	asabot::tg::venue                   a13;
	asabot::tg::location                a14;
	asabot::tg::new_chat_members        a15;
	asabot::tg::left_chat_member        a16;
	asabot::tg::new_chat_title          a17;
	asabot::tg::new_chat_photo          a18;
	asabot::tg::delete_chat_photo       a19;
	asabot::tg::group_chat_created      a20;
	asabot::tg::supergroup_chat_created a21;
	asabot::tg::channel_chat_created    a22;
	asabot::tg::migrate_to_chat_id      a23;
	asabot::tg::migrate_from_chat_id    a24;
	asabot::tg::pinned_message          a25;
	asabot::tg::invoice                 a26;
	asabot::tg::successful_payment      a27;
	asabot::tg::connected_website       a28;
	asabot::tg::passport_data           a29;
	msg;
	friend std::ostream &
	operator<<(std::ostream &, const asabot::tg::message &);
	friend std::istream &
	operator>>(std::istream &, asabot::tg::message &);
};

struct chat_private
{
	int_type                          id;
	constexpr static std::string_view type = "private";
	std::string                       username;
	std::string                       first_name;
	std::string                       last_name;
	chat_photo                        photo;
	friend std::ostream &
	operator<<(std::ostream &, const chat_private &);
	friend std::istream &
	operator>>(std::istream &, chat_private &);
};

struct chat_group
{
	int_type                          id;
	constexpr static std::string_view type = "group";
	std::string                       title;
	chat_photo                        photo;
	std::string                       description;
	std::string                       invite_link;
	message                           pinned_message;
	chat_permissions                  permissions;
	friend std::ostream &
	operator<<(std::ostream &, const chat_group &);
	friend std::istream &
	operator>>(std::istream &, chat_group &);
};

struct chat_supergroup
{
	int_type                          id;
	constexpr static std::string_view type = "supergroup";
	std::string                       title;
	std::string                       username;
	chat_photo                        photo;
	std::string                       description;
	std::string                       invite_link;
	message                           pinned_message;
	chat_permissions                  permissions;
	std::optional<int_type>           slow_mode_delay;
	std::string                       sticker_set_name;
	bool                              can_set_sticker_set;
	friend std::ostream &
	operator<<(std::ostream &, const chat_supergroup &);
	friend std::istream &
	operator>>(std::istream &, chat_supergroup &);
};

struct chat_channel
{
	int_type                          id;
	constexpr static std::string_view type = "private";
	std::string                       title;
	std::string                       username;
	chat_photo                        photo;
	std::string                       description;
	std::string                       invite_link;
	message                           pinned_message;
	chat_permissions                  permissions;
	friend std::ostream &
	operator<<(std::ostream &, const chat_channel &);
	friend std::istream &
	operator>>(std::istream &, chat_channel &);
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
	std::variant<message, edited_message, channel_post, edited_channel_post>
	    update;

	friend std::ostream &
	operator<<(std::ostream &, const chat_channel &);
	friend std::istream &
	operator>>(std::istream &, chat_channel &);
};

} // namespace asabot::tg

#endif
