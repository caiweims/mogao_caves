#pragma once
#include <stdexcept>
namespace experiment
{
	//tools function
	char* expand(const char* ptr, int n)
	{
		char* p = new char[n];
		strcpy_s(p, n, ptr);//
		return p;
	}
	class string
	{
	public:
		//basic cons stuff
		string();
		explicit string(const char*);
		string(const string&);
		string& operator=(const string&);

		string(string&&);
		string& operator=(string&&);

		//access of characters
		char& operator[](int n) { return ptr[n]; }//no check
		char operator[](int n) const { return ptr[n]; }

		char& at(int n) { check(n); return ptr[n]; }//range checked
		char at(int n) const { check(n); return ptr[n]; }

		string& operator+=(char);
		const char* c_str() { return ptr; }//C-style string access
		const char* c_str()const { return ptr; }

		//
		int size()const { return sz; }
		int capacity()const
		{
			return sz <= short_max ? short_max : sz + space;
		}
	private:
		//for short string opt.
		static const int short_max = 15;
		int sz;                 //number of characters
		char* ptr;

		union                   //space manage lite vector
		{						//use one of them only,decided by design
			int space;			//unused allocated space
			char ch[short_max + 1];//leave space for terminating-0
		};
		void check(int n) const
		{
			if (n < 0 || sz <= n)
				throw std::out_of_range("string::at()");
		}
		void copy_from(const string&);
		void move_from(string&);
		
	};
	void string::copy_from(const string& s)
	{
		if (s.sz <= short_max)
		{
			memcpy(this,&s,sizeof(s));
			ptr = ch;
		}
		else 
		{
			ptr = expand(s.ptr, s.sz + 1);
			sz = s.sz;
			space = 0;
		}

	}
	void string::move_from(string& s)
	{
		if (s.sz <= short_max)
		{
			memcpy(this, &s, sizeof(s));
		}
		else
		{
			ptr = s.ptr;
			sz = s.sz;
			space = s.space;
			//keep moved safe
			s.ptr = s.ch;
			s.sz = 0;
			s.ch[0] = 0;
		}
	}
	/******************************/
	/*
	* constroctors
	*//****************************/
	string::string() :sz(0), ptr(ch) { ch[0] = 0; }
	string::string(const char* p)
		:sz(strlen(p)), ptr(sz <= short_max ? ch : new char[sz+1]),space(0)
	{
		//when ch init
		strcpy_s(ptr, sz+1, p);
	}
}