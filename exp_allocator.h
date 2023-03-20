#pragma once
#include "exp_specialized.h"
namespace experiment
{
	template<typename type>
	class allocator
	{
		using size_type = exp_size_t;
		using value_type = type;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
	public:

	};
}