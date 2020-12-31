#ifndef ASABOT_TG_USE_VARIANT
	#include <boost/property_tree/ptree.hpp>
	#include <boost/property_tree/json_parser.hpp>
	#include "types-optional.hpp"

namespace pt = boost::property_tree;


template<class T, class Tree>
struct serialize
{
	Tree
	operator()(T &&) const;
	Tree
	operator()(T const &) const;
};

template<class T>
T
id(T&& t)
{
	return t;
}

template<class T>
T
id(const T& t)
{
	return t;
}

template<class T, class Tree>
struct deserialize
{
	T
	operator()(Tree &&) const;
	T
	operator()(Tree const &) const;
};

template<class T>
std::unique_ptr<T>
to_unique(std::optional<T> && t_in)
{
	if (t_in)
	{
		return std::make_unique<T>(std::move(t_in.value()));
	}
	else
	{
		return {};
	}
}

template<class T>
std::unique_ptr<T>
to_unique(std::optional<T> const & t_in)
{
	if (t_in)
	{
		return std::make_unique<T>(t_in.value());
	}
	else
	{
		return {};
	}
}

template<
    class Fn,
    class T,
    template<class O>
    class Optional1,
    template<class O> class Optional2 = std::optional>
Optional2<std::invoke_result_t<Fn, T>>
map(Fn && t_f, Optional1<T> && t_in)
{
	if (t_in)
	{
		return t_f(std::move(t_in.value()));
	}
	else
	{
		return {};
	}
}

template<
    class Fn,
    class T,
    template<class O>
    class Optional1,
    template<class O> class Optional2 = std::optional>
Optional2<std::invoke_result_t<Fn, T>>
map(Fn && t_f, Optional1<T> const & t_in)
{
	if (t_in)
	{
		return t_f(t_in.value());
	}
	else
	{
		return {};
	}
}

template<class T>
struct deserialize<std::vector<T>, pt::ptree>
{
	std::vector<T>
	operator()(pt::ptree const & t_src) const
	{
		std::vector<T> ret;
		for (auto const & src : t_src)
		{
			ret.push_back(deserialize<T, pt::ptree> {}(src.second));
		}
		return ret;
	}
	std::vector<T>
	operator()(pt::ptree && t_src) const
	{
		std::vector<T> ret;
		for (auto const & src : t_src)
		{
			ret.push_back(deserialize<T, pt::ptree> {}(src.second));
		}
		return ret;
	}
};

template<>
struct deserialize<asabot::tg::user, pt::ptree>
{
	asabot::tg::user
	operator()(pt::ptree const & t_src) const;
};

template<>
struct deserialize<asabot::tg::message, pt::ptree>
{
	asabot::tg::message
	operator()(pt::ptree const & t_src) const
	{
		return {
		    .message_id = t_src.get<asabot::tg::id_type>("message_id"),
		    .from       = to_unique(
                map(deserialize<asabot::tg::user, pt::ptree> {},
                    t_src.get_child_optional("from"))),
		    .sender_chat = to_unique(
		        map(deserialize<asabot::tg::chat, pt::ptree> {},
		            t_src.get_child_optional("sender_chat"))),
		    .date = asabot::tg::time_type(asabot::tg::time_type::duration(t_src.get<asabot::tg::time_type::duration::rep>("date"))),
		    .chat = to_unique(
		        map(deserialize<asabot::tg::chat, pt::ptree> {},
		            t_src.get_child_optional("chat"))),
		    .forward_from = to_unique(
		        map(deserialize<asabot::tg::user, pt::ptree> {},
		            t_src.get_child_optional("chat"))),
		    .forward_from_chat = to_unique(
		        map(deserialize<asabot::tg::chat, pt::ptree> {},
		            t_src.get_child_optional("chat"))),
		    .forward_from_message_id =
		        map([](auto const & a){return a;},t_src.get_optional<asabot::tg::id_type>(
		            "forward_from_message_id")),

		};
	}
};

template<>
struct deserialize<asabot::tg::update, pt::ptree>
{
	asabot::tg::update
	operator()(pt::ptree const & t_src) const
	{
		return {
		    .update_id = t_src.get<asabot::tg::id_type>("update_id"),

		    .message =
		        map(deserialize<asabot::tg::message, pt::ptree> {},
		            t_src.get_child_optional("message")),
		    .edited_message =
		        map(deserialize<asabot::tg::message, pt::ptree> {},
		            t_src.get_child_optional("edited_message")),
		    .channel_post =
		        map(deserialize<asabot::tg::message, pt::ptree> {},
		            t_src.get_child_optional("channel_post")),
		    .edited_channel_post =
		        map(deserialize<asabot::tg::message, pt::ptree> {},
		            t_src.get_child_optional("edited_channel_post")),
			////////////////////////////////////////////////////////////
			///                     FUTURE USE                       ///
			////////////////////////////////////////////////////////////
		    //.inline_query =
		    //    map(deserialize<asabot::tg::inline_query, pt::ptree> {},
		    //        t_src.get_child_optional("inline_query")),
		    //.shipping_query =
		    //    map(deserialize<asabot::tg::shipping_query, pt::ptree> {},
		    //        t_src.get_child_optional("shipping_query")),
		    //.pre_checkout_query =
		    //    map(deserialize<asabot::tg::pre_checkout_query, pt::ptree> {},
		    //        t_src.get_child_optional("pre_checkout_query")),
		    //.poll =
		    //    map(deserialize<asabot::tg::poll, pt::ptree> {},
		    //        t_src.get_child_optional("poll")),
		    //.poll_answer =
		    //    map(deserialize<asabot::tg::poll_answer, pt::ptree> {},
		    //        t_src.get_child_optional("poll_answer")),
		};
	}
};

std::istream&
operator>>(std::istream& s, std::vector<asabot::tg::update>& t_updates)
{
	pt::ptree pt;
	pt::read_json(s, pt);
	t_updates = deserialize<std::vector<asabot::tg::update>, pt::ptree>{}(pt);
	return s;
}

#endif
