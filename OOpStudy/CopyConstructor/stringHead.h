#include "stdafx.h"
#ifdef OPERATOR_TEST

#include <iostream>
using namespace std;


class String
{
public:

	String(const char * szpStr);
	String(void);
	String(const String &s);// 重载复制构造函数 
	String &operator = (const String &s);// 重载赋值操作符
	char &operator [](const unsigned int index);//重载[]操作符,用于取间类似数组取元
	const char &operator [](const unsigned int index) const;// 重载[]操作符
	String &operator +=(const String &lhs);// 重载复合赋值操作符
	unsigned int GetLength();
	~String();

	// 算术与关系运算符一般应该友元化
	friend String operator+(const String &lhs, const String &rhs);// 算术加操作符
	friend bool operator == (const String &lhs, const String &rhs);// 相等操作符
	friend bool operator !=(const String &lhs, const String &rhs);// 不相等操作符
	friend bool operator <(const String &lhs, const String &rhs);// 小于操作符
	friend bool operator >(const String &lhs, const String &rhs);// 大于操作符

	// 输入输出操作符, 一般元化
	friend ostream & operator<< (ostream &os, const String &s);
	friend istream & operator>> (istream &is, const String &s);
private:
	const static int BUFF_SIZE = 512;
	unsigned int m_nLen;
	char *m_pData;

};

#endif