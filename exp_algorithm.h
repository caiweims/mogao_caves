#pragma once
namespace experiment
{
	template<typename iter,typename datatype>
	inline
	bool find(const iter beg,const iter end,const datatype& key)
	{
		iter it = beg;
		while (it != end)
			if (*it++ == key)
				return true;
		return false;
	}
}