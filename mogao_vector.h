#pragma once
namespace mogao
{
	//https://svn.apache.org/repos/asf/stdcxx/
	//template <typename T,typename Allocator=std::allocator<T>>
	//above:we saw that we must soecify a allocator before we use our vector
	template<typename T>
	class vector
	{
		static std::allocator<T> alloc;//finally we will use our own
		using value_type = T;
		//using size_type = std::allocator<T>::size_type;

	public:
	private:

	};
	std::allocator<T> vector<T>::alloc;
}
