#include <string>
#include <string_view>
#include <variant>
#include <optional>
#include <memory>

namespace obl
{

	namespace tgbot
	{

	using int_type = std::int_fast64_t;

	struct user
	{
		int_type id;
		bool is_bot;
		std::string first_name;
		std::string last_name;
		std::string username;
		std::string language_code;
	};
	
	struct me: user
	{
		bool can_join_groups;
		bool can_trad_all_group_messages;
		bool supports_inline_queries;
	};
	
	struct photo_size
	{
		std::string file_id;
		std::string file_unique_id;
		int_type width;
		int_type height;
		std::optional<int_type> file_size;
	};
	
	struct chat_photo
	{
		std::string small_file_id;
		std::string small_file_unique_id;
		std::string big_file_id;
		std::string big_file_unique_id;
	};
	
	struct message;
	
#ifndef OBL_TGBOT_PREFER_VARIANT
	struct chat_private
	{
		int_type id;
		constexpr static std::string_view type = "private";
		std::string	username;
		std::string	first_name;
		std::string	last_name;
		chat_photo	photo;
	};
	
	struct chat_group
	{
		int_type id;
		constexpr static std::string_view type = "group";
		std::string			title;
		chat_photo			photo;
		std::string			description;
		std::string			invite_link;
		message&			pinned_message;
		chat_permissions	permissions;
	};
	
	struct chat_supergroup
	{
		int_type id;
		constexpr static std::string_view type = "supergroup";
		std::string				title;
		std::string				username;
		chat_photo				photo;
		std::string				description;
		std::string				invite_link;
		message&				pinned_message;
		chat_permissions		permissions;
		std::optional<int_type>	slow_mode_delay;
		std::string				sticker_set_name;
		bool					can_set_sticker_set;
	};
	
	struct chat_channel
	{
		int_type id;
		constexpr static std::string_view type = "private";
		std::string			title;
		std::string			username;
		chat_photo			photo;
		std::string			description;
		std::string			invite_link;
		message&			pinned_message;
		chat_permissions	permissions;
	};
	
	using chat = std::variant<chat_channel, chat_group, chat_supergroup, chat_private>;
	
#else
#endif
	
	struct message
	{
		int_type					message_id;
		user						from;
		int_type					date;
		chat						chat;
		
		std::optional<std::unique_ptr<user>>	forward_from;
		std::optional<std::unique_ptr<chat>>	forward_from_chat;
		std::optional<int_type>		forward_from_message_id;
		std::string					forward_signature;
		std::string					forward_sender_name;
		std::optional<int_type>		forward_date;
		std::optional<std::unique_ptr<message>>	reply_to_message;
		
		std::optional<std::unique_ptr<user>>	via_bot;
		std::optional<int_type>		edit_date;
		std::string
	};
	
	}
	
}
