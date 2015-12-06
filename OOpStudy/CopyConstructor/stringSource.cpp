#include "StdAfx.h"
#include "Head.h"
#include "stringHead.h"

#ifdef OPERATOR_TEST

// ���캯���� �ú�����Ϊ�ַ��������ڴ�ռ䣬Ȼ��
//���ַ���ԭ�ⲻ���ĸ��Ƶ���������ڴ���,ע��Ҫ���ָ�����Ч��
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
		m_pData = new char[strlen(szpStr) +1];// ֱ�Ӹ����ڴ�飬����ȸ���
		memset(m_pData,0,strlen(szpStr)+1);
		strcpy(m_pData,szpStr);
		
	}


}
// ���ƹ��캯��
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

// ��ֵ������ʵ�ַ����븴�ƹ��캯��һ��������Ϊ*this
String & String::operator=(const String &s)
{
	if (this != &s)
	{
		if (m_pData != NULL)
		{
			delete [] m_pData;//�ͷ�ָ��
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
			strcpy(pTem,m_pData);// Ҳ����ʹ��memcpy
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
	int ret = strcmp(lhs.m_pData,rhs.m_pData);// ֱ�ӵ��õ���C���Եĵ��еıȽϺ���
	if (ret = 0)
	{
		return true;
	}
	else return false;
	
}

bool operator != (const String &lhs, const String &rhs)
{
	if (lhs == rhs)// ֱ�ӵ��� operator == ������
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
	// ��Ϊ�����С����ȷ����������ʱ����������ʵ��
	is >> s.m_pData;
	return is;

}

#endif