#pragma once
namespace experiment
{
	template<typename _iterator>
	class iterator_traits
	{
		using value_type = typename _iterator::value_type;
		using pointer = typename _iterator::pointer;
		using reference = typename _iterator::reference;
	};
	template<typename _type>
	class iterator_traits<_type*>
	{
		using value_type = _type;

	};
}