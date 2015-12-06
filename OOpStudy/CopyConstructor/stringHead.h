#include "stdafx.h"
#ifdef OPERATOR_TEST

#include <iostream>
using namespace std;


class String
{
public:

	String(const char * szpStr);
	String(void);
	String(const String &s);// ���ظ��ƹ��캯�� 
	String &operator = (const String &s);// ���ظ�ֵ������
	char &operator [](const unsigned int index);//����[]������,����ȡ����������ȡԪ
	const char &operator [](const unsigned int index) const;// ����[]������
	String &operator +=(const String &lhs);// ���ظ��ϸ�ֵ������
	unsigned int GetLength();
	~String();

	// �������ϵ�����һ��Ӧ����Ԫ��
	friend String operator+(const String &lhs, const String &rhs);// �����Ӳ�����
	friend bool operator == (const String &lhs, const String &rhs);// ��Ȳ�����
	friend bool operator !=(const String &lhs, const String &rhs);// ����Ȳ�����
	friend bool operator <(const String &lhs, const String &rhs);// С�ڲ�����
	friend bool operator >(const String &lhs, const String &rhs);// ���ڲ�����

	// �������������, һ��Ԫ��
	friend ostream & operator<< (ostream &os, const String &s);
	friend istream & operator>> (istream &is, const String &s);
private:
	const static int BUFF_SIZE = 512;
	unsigned int m_nLen;
	char *m_pData;

};

#endif