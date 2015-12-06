#include "stdafx.h"
#include <stdio.h>

#ifdef COPY_CONTROL

class String;

class UseCount
{
	friend class String;
	char *psz;
	int count;
	UseCount(char*p):psz(p),count(1){}
	~UseCount(){ delete psz;}
};

class String 
{
public:
	String(char *psz):ptr(new UseCount(psz)){}
	String(const String &origStr):ptr(origStr.ptr)
	{
		++ptr->count;
	}
	String &operator=(const String &orig)
	{
		++orig.ptr->count;
		if (--ptr->count == 0)
		{
			delete ptr;
		}
		ptr = orig.ptr;

	}
	void OutputStr()
	{
		printf("%s \n",ptr->psz);
	}

	~String()
	{
		if (--ptr->count == 0)
		{
			delete ptr;
		}
	}
private:
	UseCount *ptr;
};

#endif