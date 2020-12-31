#include <string>
#include <string_view>
#include <vector>
#include <variant>
#include <optional>
#include <memory>
#include <iostream>
#include <chrono>

namespace asabot::tg
{
using int_type      = std::int_fast64_t;
using id_type       = std::int_fast64_t;
using size_type     = std::int_fast64_t;
using duration_type = std::chrono::duration<std::chrono::system_clock>;
using time_type     = std::chrono::time_point<std::chrono::system_clock>;
class tag{};

struct message;

struct user
{
	using tag = tag;

	id_type     id;
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
	using tag = tag;

	user user;
	bool can_join_groups;
	bool can_trad_all_group_messages;
	bool supports_inline_queries;
	friend std::ostream &
	operator<<(std::ostream &, const me &);
	friend std::istream &
	operator>>(std::istream &, me &);
};

struct message_entity
{
	using tag = tag;

	std::string           type;
	int_type              offset;
	int_type              length;
	std::string           url;
	std::unique_ptr<user> user;
	std::string           language;
};

struct photo_size
{
	using tag = tag;

	std::string              file_id;
	std::string              file_unique_id;
	size_type                width;
	size_type                height;
	std::optional<size_type> file_size;
	friend std::ostream &
	operator<<(std::ostream &, const photo_size &);
	friend std::istream &
	operator>>(std::istream &, photo_size &);
};

struct chat_photo
{
	using tag = tag;

	std::string small_file_id;
	std::string small_file_unique_id;
	std::string big_file_id;
	std::string big_file_unique_id;
	friend std::ostream &
	operator<<(std::ostream &, const chat_photo &);
	friend std::istream &
	operator>>(std::istream &, chat_photo &);
};

struct labeled_price
{
	using tag = tag;

	std::string label;
	int_type    amount;
	friend std::ostream &
	operator<<(std::ostream &, const labeled_price &);
	friend std::istream &
	operator>>(std::istream &, labeled_price &);
};

struct invoice
{
	using tag = tag;

	std::string title;
	std::string description;
	std::string start_parameter;
	std::string currency;
	int_type    total_amount;
	friend std::ostream &
	operator<<(std::ostream &, const invoice &);
	friend std::istream &
	operator>>(std::istream &, invoice &);
};

struct shipping_address
{
	using tag = tag;

	std::string country_code;
	std::string state;
	std::string city;
	std::string street_line1;
	std::string street_line2;
	std::string post_code;
	friend std::ostream &
	operator<<(std::ostream &, const shipping_address &);
	friend std::istream &
	operator>>(std::istream &, shipping_address &);
};

struct order_info
{
	using tag = tag;

	std::string                       name;
	std::string                       phone_number;
	std::string                       email;
	std::unique_ptr<shipping_address> shipping_address;
	friend std::ostream &
	operator<<(std::ostream &, const order_info &);
	friend std::istream &
	operator>>(std::istream &, order_info &);
};

struct shipping_option
{
	using tag = tag;

	std::string                id;
	std::string                title;
	std::vector<labeled_price> prices;
	friend std::ostream &
	operator<<(std::ostream &, const shipping_option &);
	friend std::istream &
	operator>>(std::istream &, shipping_option &);
};

struct successful_payment
{
	using tag = tag;

	std::string                 currency;
	int_type                    total_amount;
	std::string                 invoice_payload;
	std::string                 shipping_option_id;
	std::unique_ptr<order_info> order_info;
	std::string                 telegram_payment_charge_id;
	std::string                 provider_payment_charge_id;
	friend std::ostream &
	operator<<(std::ostream &, const successful_payment &);
	friend std::istream &
	operator>>(std::istream &, successful_payment &);
};

struct shipping_query
{
	using tag = tag;

	std::string                       id;
	std::unique_ptr<user>             from;
	std::string                       invoice_payload;
	std::unique_ptr<shipping_address> shipping_address;
	friend std::ostream &
	operator<<(std::ostream &, const shipping_query &);
	friend std::istream &
	operator>>(std::istream &, shipping_query &);
};

struct pre_checkout_query
{
	using tag = tag;

	std::string                 id;
	std::unique_ptr<user>       from;
	std::string                 currency;
	int_type                    total_amount;
	std::string                 invoice_payload;
	std::string                 shipping_option_id;
	std::unique_ptr<order_info> order_info;
	friend std::ostream &
	operator<<(std::ostream &, const shipping_query &);
	friend std::istream &
	operator>>(std::istream &, shipping_query &);
};

struct mask_position
{
	using tag = tag;

	std::string point;
	float       x_shift;
	float       y_shift;
	float       scale;
	friend std::ostream &
	operator<<(std::ostream &, const mask_position &);
	friend std::istream &
	operator>>(std::istream &, mask_position &);
};

struct sticker
{
	using tag = tag;

	std::string                  file_id;
	std::string                  file_unique_id;
	size_type                    width;
	size_type                    height;
	bool                         is_animated;
	std::optional<photo_size>    thumb;
	std::string                  emoji;
	std::string                  set_name;
	std::optional<mask_position> mask_position;
	std::optional<size_type>     file_size;
	friend std::ostream &
	operator<<(std::ostream &, const sticker &);
	friend std::istream &
	operator>>(std::istream &, sticker &);
};

struct sticker_set
{
	using tag = tag;

	std::string               name;
	std::string               title;
	bool                      is_animated;
	bool                      contains_masks;
	std::optional<photo_size> thumb;
	std::vector<sticker>      stickers;
	std::optional<size_type>  file_size;
	friend std::ostream &
	operator<<(std::ostream &, const sticker_set &);
	friend std::istream &
	operator>>(std::istream &, sticker_set &);
};

struct animation;

struct game
{
	using tag = tag;

	std::string                 title;
	std::string                 description;
	std::vector<photo_size>     photo;
	std::string                 text;
	std::vector<message_entity> text_entities;
	std::unique_ptr<animation>  animation;
};

struct callback_game
{
	using tag = tag;

};

struct animation
{
	using tag = tag;

	std::string               file_id;
	std::string               file_unique_id;
	size_type                 width;
	size_type                 height;
	duration_type             duration;
	std::optional<photo_size> thumb;
	std::string               file_name;
	std::string               mime_type;
	std::optional<size_type>  file_size;
	friend std::ostream &
	operator<<(std::ostream &, const animation &);
	friend std::istream &
	operator>>(std::istream &, animation &);
};

struct audio
{
	using tag = tag;

	std::string               file_id;
	std::string               file_unique_id;
	duration_type             duration;
	std::string               performer;
	std::string               title;
	std::string               file_name;
	std::string               mime_type;
	std::optional<size_type>  file_size;
	std::optional<photo_size> thumb;
	friend std::ostream &
	operator<<(std::ostream &, const audio &);
	friend std::istream &
	operator>>(std::istream &, audio &);
};

struct document
{
	using tag = tag;

	std::string               file_id;
	std::string               file_unique_id;
	std::optional<photo_size> thumb;
	std::string               file_name;
	std::string               mime_type;
	std::optional<size_type>  file_size;
	friend std::ostream &
	operator<<(std::ostream &, const document &);
	friend std::istream &
	operator>>(std::istream &, document &);
};

struct video
{
	using tag = tag;

	std::string               file_id;
	std::string               file_unique_id;
	size_type                 width;
	size_type                 height;
	duration_type             duration;
	std::optional<photo_size> thumb;
	std::string               file_name;
	std::string               mime_type;
	std::optional<size_type>  file_size;
	friend std::ostream &
	operator<<(std::ostream &, const video &);
	friend std::istream &
	operator>>(std::istream &, video &);
};

struct video_note
{
	using tag = tag;

	std::string               file_id;
	std::string               file_unique_id;
	size_type                 length;
	duration_type             duration;
	std::optional<photo_size> thumb;
	std::optional<size_type>  file_size;
	friend std::ostream &
	operator<<(std::ostream &, const video_note &);
	friend std::istream &
	operator>>(std::istream &, video_note &);
};

struct voice
{
	using tag = tag;

	std::string              file_id;
	std::string              file_unique_id;
	duration_type            duration;
	std::optional<size_type> file_size;
	friend std::ostream &
	operator<<(std::ostream &, const voice &);
	friend std::istream &
	operator>>(std::istream &, voice &);
};

struct contact
{
	using tag = tag;

	std::string            phone_number;
	std::string            first_name;
	std::string            last_name;
	std::optional<id_type> user_id;
	std::string            vcard;
	friend std::ostream &
	operator<<(std::ostream &, const contact &);
	friend std::istream &
	operator>>(std::istream &, contact &);
};

struct dice
{
	using tag = tag;

	std::string file_id;
	int_type    value;
	friend std::ostream &
	operator<<(std::ostream &, const dice &);
	friend std::istream &
	operator>>(std::istream &, dice &);
};

struct poll_option
{
	using tag = tag;

	std::string text;
	int_type    voter_count;
	friend std::ostream &
	operator<<(std::ostream &, const poll_option &);
	friend std::istream &
	operator>>(std::istream &, poll_option &);
};

struct poll_answer
{
	using tag = tag;

	std::string           poll_id;
	std::unique_ptr<user> user;
	std::vector<int_type> option_ids;
	friend std::ostream &
	operator<<(std::ostream &, const poll_answer &);
	friend std::istream &
	operator>>(std::istream &, poll_answer &);
};

struct poll
{
	using tag = tag;

	std::string                  id;
	std::string                  question;
	std::vector<poll_option>     options;
	int_type                     total_voter_count;
	bool                         is_closed;
	bool                         is_anonymous;
	int_type                     type;
	bool                         allows_multiple_answers;
	std::optional<int>           correct_option_id;
	std::string                  explanation;
	std::vector<message_entity>  explanation_entities;
	std::optional<duration_type> open_period;
	std::optional<time_type>     close_date;
	friend std::ostream &
	operator<<(std::ostream &, const poll &);
	friend std::istream &
	operator>>(std::istream &, poll &);
};

struct location
{
	using tag = tag;

	float                        longtitude;
	float                        latitude;
	std::optional<float>         horizontal_accuracy;
	std::optional<duration_type> live_period;
	std::optional<int_type>      heading;
	std::optional<int_type>      proximity_alert_radius;
	friend std::ostream &
	operator<<(std::ostream &, const location &);
	friend std::istream &
	operator>>(std::istream &, location &);
};

struct venue
{
	using tag = tag;

	location    location;
	std::string title;
	std::string address;
	std::string foursquare_id;
	std::string foursquare_type;
	std::string google_place_id;
	std::string google_place_type;
	friend std::ostream &
	operator<<(std::ostream &, const venue &);
	friend std::istream &
	operator>>(std::istream &, venue &);
};

struct proximity_alert_triggered
{
	using tag = tag;

	std::unique_ptr<user> traveler;
	std::unique_ptr<user> watcher;
	int_type              distance;
};

struct user_profile_photos
{
	using tag = tag;

	int_type                total_count;
	std::vector<photo_size> photos;
	friend std::ostream &
	operator<<(std::ostream &, const user_profile_photos &);
	friend std::istream &
	operator>>(std::istream &, user_profile_photos &);
};

struct file
{
	using tag = tag;

	std::string file_id;
	std::string file_unique_id;
	size_type   file_size;
	std::string file_path;
	friend std::ostream &
	operator<<(std::ostream &, const file &);
	friend std::istream &
	operator>>(std::istream &, file &);
};

using keyboard_button_poll_type = std::string;

struct keyboard_button
{
	using tag = tag;

	std::string                              text;
	bool                                     request_contact;
	bool                                     request_location;
	std::optional<keyboard_button_poll_type> request_poll;
	friend std::ostream &
	operator<<(std::ostream &, const keyboard_button &);
	friend std::istream &
	operator>>(std::istream &, keyboard_button &);
};

struct reply_keyboard_markup
{
	using tag = tag;

	std::vector<std::vector<keyboard_button>> keyboard;
	bool                                      resize_keyboard;
	bool                                      one_time_keyboard;
	bool                                      selective;
	friend std::ostream &
	operator<<(std::ostream &, const reply_keyboard_markup &);
	friend std::istream &
	operator>>(std::istream &, reply_keyboard_markup &);
};

struct reply_keyboard_remove
{
	using tag = tag;

	bool selective;
	friend std::ostream &
	operator<<(std::ostream &, const reply_keyboard_remove &);
	friend std::istream &
	operator>>(std::istream &, reply_keyboard_remove &);
};

struct login_url
{
	using tag = tag;

	std::string url;
	std::string forward_text;
	std::string bot_username;
	bool        request_write_access;
	friend std::ostream &
	operator<<(std::ostream &, const login_url &);
	friend std::istream &
	operator>>(std::istream &, login_url &);
};

struct callback_query
{
	using tag = tag;

	std::string              id;
	std::unique_ptr<user>    from;
	std::unique_ptr<message> message;
	friend std::ostream &
	operator<<(std::ostream &, const callback_query &);
	friend std::istream &
	operator>>(std::istream &, callback_query &);
};

struct inline_keyboard_button
{
	using tag = tag;

	std::string                  text;
	std::string                  url;
	std::optional<login_url>     login_url;
	std::string                  callback_data;
	std::string                  switch_inline_query;
	std::string                  switch_inline_query_current_chat;
	std::optional<callback_game> callback_game;
	bool                         pay;
	friend std::ostream &
	operator<<(std::ostream &, const inline_keyboard_button &);
	friend std::istream &
	operator>>(std::istream &, inline_keyboard_button &);
};

struct inline_keyboard_markup
{
	using tag = tag;

	std::vector<inline_keyboard_button> inline_keyboard;
	friend std::ostream &
	operator<<(std::ostream &, const inline_keyboard_markup &);
	friend std::istream &
	operator>>(std::istream &, inline_keyboard_markup &);
};

struct force_reply
{
	using tag = tag;

	bool selective;
	friend std::ostream &
	operator<<(std::ostream &, const force_reply &);
	friend std::istream &
	operator>>(std::istream &, force_reply &);
};

struct chat_member
{
	using tag = tag;

	std::unique_ptr<user>    user;
	std::string              status;
	std::string              custom_title;
	std::optional<bool>      is_anonymous;
	std::optional<bool>      can_be_edited;
	std::optional<bool>      can_post_messages;
	std::optional<bool>      can_edit_messages;
	std::optional<bool>      can_delete_messages;
	std::optional<bool>      can_restrict_members;
	std::optional<bool>      can_promote_members;
	std::optional<bool>      can_change_info;
	std::optional<bool>      can_invite_users;
	std::optional<bool>      can_pin_messages;
	std::optional<bool>      is_member;
	std::optional<bool>      can_send_messages;
	std::optional<bool>      can_send_media_messages;
	std::optional<bool>      can_send_polls;
	std::optional<bool>      can_send_other_messages;
	std::optional<bool>      can_add_web_page_previews;
	std::optional<time_type> until_date;
	friend std::ostream &
	operator<<(std::ostream &, const chat_member &);
	friend std::istream &
	operator>>(std::istream &, chat_member &);
};

struct chat_permissions
{
	using tag = tag;

	std::optional<bool> can_send_messages;
	std::optional<bool> can_send_media_messages;
	std::optional<bool> can_send_polls;
	std::optional<bool> can_send_other_messages;
	std::optional<bool> can_add_web_page_previews;
	std::optional<bool> can_change_info;
	std::optional<bool> can_invite_users;
	std::optional<bool> can_pin_messages;
	friend std::ostream &
	operator<<(std::ostream &, const chat_permissions &);
	friend std::istream &
	operator>>(std::istream &, chat_permissions &);
};

struct chat_location
{
	using tag = tag;

	std::unique_ptr<location> location;
	std::string               address;
	friend std::ostream &
	operator<<(std::ostream &, const chat_location &);
	friend std::istream &
	operator>>(std::istream &, chat_location &);
};

struct bot_command
{
	using tag = tag;

	std::string command;
	std::string description;
	friend std::ostream &
	operator<<(std::ostream &, const bot_command &);
	friend std::istream &
	operator>>(std::istream &, bot_command &);
};

struct response_parameters
{
	using tag = tag;

	std::optional<id_type>       migrate_to_chat_id;
	std::optional<duration_type> retry_after;
	friend std::ostream &
	operator<<(std::ostream &, const response_parameters &);
	friend std::istream &
	operator>>(std::istream &, response_parameters &);
};

struct inline_query
{
	using tag = tag;

	std::string               id;
	std::unique_ptr<user>     user;
	std::unique_ptr<location> location;
	std::string               query;
	std::string               offset;
	friend std::ostream &
	operator<<(std::ostream &, const inline_query &);
	friend std::istream &
	operator>>(std::istream &, inline_query &);
};

struct chat;

struct message
{
	using tag = tag;

	id_type                              message_id;
	std::unique_ptr<asabot::tg::user>    from;
	std::unique_ptr<asabot::tg::chat>    sender_chat;
	time_type                            date;
	std::unique_ptr<asabot::tg::chat>    chat;
	std::unique_ptr<asabot::tg::user>    forward_from;
	std::unique_ptr<asabot::tg::chat>    forward_from_chat;
	std::optional<id_type>               forward_from_message_id;
	std::string                          forward_signature;
	std::string                          forward_sender_name;
	std::optional<time_type>             forward_date;
	std::unique_ptr<asabot::tg::message> reply_to_message;
	std::unique_ptr<asabot::tg::user>    via_bot;
	std::optional<time_type>             edit_date;
	std::string                          media_group_id;
	std::string                          author_signature;

	std::string                                     text;
	std::vector<asabot::tg::message_entity>         entities;
	std::unique_ptr<asabot::tg::animation>          animation;
	std::unique_ptr<asabot::tg::audio>              audio;
	std::unique_ptr<asabot::tg::document>           document;
	std::vector<asabot::tg::photo_size>             photo;
	std::unique_ptr<asabot::tg::sticker>            sticker;
	std::unique_ptr<asabot::tg::video>              video;
	std::unique_ptr<asabot::tg::video_note>         video_note;
	std::unique_ptr<asabot::tg::voice>              voice;
	std::string                                     caption;
	std::vector<asabot::tg::message_entity>         caption_entities;
	std::unique_ptr<asabot::tg::contact>            contact;
	std::unique_ptr<asabot::tg::dice>               dice;
	std::unique_ptr<asabot::tg::game>               game;
	std::unique_ptr<asabot::tg::poll>               poll;
	std::unique_ptr<asabot::tg::venue>              venue;
	std::unique_ptr<asabot::tg::location>           location;
	std::vector<asabot::tg::user>                   new_chat_members;
	std::unique_ptr<asabot::tg::user>               left_chat_member;
	std::string                                     new_chat_title;
	std::vector<asabot::tg::photo_size>             new_chat_photo;
	bool                                            delete_chat_photo;
	bool                                            group_chat_created;
	bool                                            supergroup_chat_created;
	bool                                            channel_chat_created;
	std::optional<id_type>                          migrate_to_chat_id;
	std::optional<id_type>                          migrate_from_chat_id;
	std::unique_ptr<asabot::tg::message>            pinned_message;
	std::unique_ptr<asabot::tg::invoice>            invoice;
	std::unique_ptr<asabot::tg::successful_payment> successful_payment;
	std::string                                     connected_website;
	std::unique_ptr<asabot::tg::proximity_alert_triggered>
	    proximity_alert_triggered;
	std::unique_ptr<asabot::tg::reply_keyboard_markup> reply_markup;

	friend std::ostream &
	operator<<(std::ostream &, const asabot::tg::message &);
	friend std::istream &
	operator>>(std::istream &, asabot::tg::message &);
};

struct chat
{
	using tag = tag;

	id_type                      id;
	std::string                  type;
	std::string                  title;
	std::string                  username;
	chat_photo                   photo;
	std::string                  description;
	std::string                  invite_link;
	message                      pinned_message;
	chat_permissions             permissions;
	std::optional<duration_type> slow_mode_delay;
	std::string                  sticker_set_name;
	bool                         can_set_sticker_set;
	friend std::ostream &
	operator<<(std::ostream &, const chat &);
	friend std::istream &
	operator>>(std::istream &, chat &);
};

struct update
{
	using tag = tag;

	id_type                                       update_id;
	std::optional<asabot::tg::message>            message;
	std::optional<asabot::tg::message>            edited_message;
	std::optional<asabot::tg::message>            channel_post;
	std::optional<asabot::tg::message>            edited_channel_post;
	std::optional<asabot::tg::inline_query>       inline_query;
	std::optional<asabot::tg::shipping_query>     shipping_query;
	std::optional<asabot::tg::pre_checkout_query> pre_checkout_query;
	std::optional<asabot::tg::poll>               poll;
	std::optional<asabot::tg::poll_answer>        poll_answer;

	friend std::ostream &
	operator<<(std::ostream &, const update &);
	friend std::istream &
	operator>>(std::istream &, update &);
};

} // namespace asabot::tg
