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

template<class T, class Tree>
struct deserialize
{
	T
	operator()(Tree &&) const;
	T
	operator()(Tree const &) const;
};

template<class T>
bool
optional_move_assign(T & t_dest, std::optional<T> t_src)
{
	if (t_src)
	{
		t_dest = t_src.value();
		return true;
	}
	else
	{
		return false;
	}
};

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

// template<
//    class R,
//    class T,
//    template<class O>
//    class Optional1,
//    template<class O> class Optional2 = std::optional>
// Optional2<R>
// map(std::function<R(T)> t_f, Optional1<T> const & t_in)
//{
//	if (t_in)
//	{
//		return t_f(t_in.value());
//	}
//	else
//	{
//		return {};
//	}
//}

template<class T>
struct deserialize<std::vector<T>, pt::ptree>
{
	std::vector<T> &
	operator()(pt::ptree const & t_src) const
	{
		std::vector<T> ret;
		for (auto const & src : t_src)
		{
			ret.push_back(deserialize {}(src.second));
		}
	}
	std::vector<T> &
	operator()(pt::ptree && t_src) const
	{
		std::vector<T> ret;
		for (auto const & src : t_src)
		{
			ret.push_back(deserialize {}(src.second));
		}
	}
};

template<>
struct deserialize<asabot::tg::message, pt::ptree>
{
	asabot::tg::message
	operator()(pt::ptree && t_src) const;
	asabot::tg::message
	operator()(pt::ptree const & t_src) const;
};

template<>
class deserialize<asabot::tg::update, pt::ptree>
{
	asabot::tg::update
	operator()(pt::ptree const & t_src) const
	{
		return {
		    .channel_post =
		        map(deserialize<asabot::tg::message, pt::ptree> {},
		            t_src.get_child_optional("channel_post")),
		    // map(deserialize,
		    //    t_update.edited_channel_post,
		    //    t_src.get_child_optional("edited_channel_post"));
		    // map(deserialize,
		    //    t_update.edited_message,
		    //    t_src.get_child_optional("edited_message"));
		    // map(deserialize,
		    //    t_update.inline_query,
		    //    t_src.get_child_optional("inline_query"));
		    // map(deserialize, t_update.message,
		    // t_src.get_child_optional("message")); map(deserialize,
		    // t_update.poll, t_src.get_child_optional("poll"));
		    // map(deserialize,
		    //    t_update.poll_answer,
		    //    t_src.get_child_optional("poll_answer"));
		    // map(deserialize,
		    //    t_update.pre_checkout_query,
		    //    t_src.get_child_optional("pre_checkout_query"));
		    // map(deserialize,
		    //    t_update.shipping_query,
		    //    t_src.get_child_optional("shipping_query"));
		};
	}
};
#endif
