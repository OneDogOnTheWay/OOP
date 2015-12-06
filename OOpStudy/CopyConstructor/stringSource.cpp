#include "StdAfx.h"
#include "Head.h"
#include "stringHead.h"

#ifdef OPERATOR_TEST

// 构造函数， 该函数中为字符串分配内存空间，然后，
//把字符串原封不到的复制到所分配的内存中,注意要检查指针的有效性
String::String(void)
{
	m_pData = NULL;
	m_pData = new char[BUFF_SIZE];
	memset(m_pData,0,BUFF_SIZE);

}
String::String(const char * szpStr /* = NULL */)
{
	m_nLen = 0;
	if (!szpStr)
	{
		m_pData = NULL;
		return;
	}else 
	{
		m_pData = new char[strlen(szpStr) +1];// 直接复制内存块，即深度复制
		memset(m_pData,0,strlen(szpStr)+1);
		strcpy(m_pData,szpStr);
		
	}


}
// 复制构造函数
String::String(const String &s)
{
	if (this != &s)
	{
		m_pData = NULL;//
		m_pData = new char[strlen(s.m_pData)+1];
		memset(m_pData,0,strlen(s.m_pData)+1);
		strcpy(m_pData, s.m_pData);		
	}
}

// 赋值操作，实现方法与复制构造函数一样，返回为*this
String & String::operator=(const String &s)
{
	if (this != &s)
	{
		if (m_pData != NULL)
		{
			delete [] m_pData;//释放指针
		}

		m_pData = NULL;

		m_pData = new char[strlen(s.m_pData)+1];
		memset(m_pData,0,strlen(s.m_pData)+1);
		memcpy(m_pData, s.m_pData,strlen(s.m_pData));
		
	}
	return *this;
}
char & String::operator[](const unsigned int index)
{
	if (index < strlen(m_pData))
	{
		return m_pData[index];
	}
	//else
	//	return m_pData[0];
}

const char & String::operator[](const unsigned int index)const 
{
	if (index < strlen(m_pData))
	{
		return m_pData[index];
	}
	//else
	//	return m_pData[0];
}
String & String::operator +=(const String &s)
{

	if (this != &s)
	{
		if (m_pData && s.m_pData != NULL)
		{
			char *pTem = new char[strlen(m_pData)+strlen(s.m_pData) +1];
			memset(pTem,0,strlen(m_pData)+strlen(s.m_pData) +1);
			strcpy(pTem,m_pData);// 也可以使用memcpy
			strcpy(pTem+strlen(m_pData),s.m_pData);
			m_pData = pTem;
		}


	}
	return *this;

}

String::~String()
{
	if (!m_pData)
	{
		delete []m_pData;
	}
}

String operator+(const String &lhs, const String &rhs)
{
	String ret(lhs);
	ret += rhs;
	return ret; 
}

bool operator == (const String &lhs, const String &rhs)
{
	int ret = strcmp(lhs.m_pData,rhs.m_pData);// 直接调用的是C语言的当中的比较函数
	if (ret = 0)
	{
		return true;
	}
	else return false;
	
}

bool operator != (const String &lhs, const String &rhs)
{
	if (lhs == rhs)// 直接调用 operator == 操作符
	{
		return false;
	}else 
	{
		return true;
	}

}
bool operator <(const String &lhs, const String &rhs)
{

	int ret = strcmp(lhs.m_pData,rhs.m_pData);
	if (ret <0)
	{
		return true;
	}
	else return false;
}
bool operator >(const String &lhs, const String &rhs)
{
	int ret = strcmp(lhs.m_pData,rhs.m_pData);
	if (ret > 0)
	{
		return true;
	}
	else return false;
}

ostream & operator << (ostream &os, const String &s)
{
	os << s.m_pData;
	return os;
}
istream & operator >> (istream &is, const String &s)
{
	// 因为输入大小不好确定，所以暂时不定义输入实现
	is >> s.m_pData;
	return is;

}

#endif