#include <mutex>
#include <vector>
#include <stack>
#include <functional>

template <class Resource>
class resource_repo
{
	class resource_handle
	{
		resource_repo& pool_ptr;
		Resource	   res;

		public:
		resource_handle(resource_repo& _pool_ptr, Resource&& _res):
			pool_ptr(_pool_ptr), res(std::move(_res))
		{
		}
		resource_handle(const resource_handle&) = delete;
		resource_handle
		operator=(const resource_handle&) = delete;
		~resource_handle()
		{
			std::lock_guard g {this->pool_ptr.handle_lock};
			this->pool_ptr.handles.push(std::move(res));
		}
		Resource*
		operator->()
		{
			return &res;
		}
	};
	std::mutex				  handle_lock;
	std::stack<Resource>	  handles;
	std::function<Resource()> constructor;

public:	
	resource_handle
	lock()
	{
		if (this->handles.empty())
		{
			return resource_handle {*this, std::move(constructor())};
		}
		else
		{
			std::lock_guard g {this->handle_lock};
			auto			idx = std::move(this->handles.top());
			this->handles.pop();
			return resource_handle {*this, std::move(idx)};
		}
	}
	
	resource_repo(std::function<Resource()> creator):
		constructor(creator)
	{
	}
};
