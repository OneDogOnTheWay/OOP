// CopyConstructor.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Book.h"
#include <vector>
#include "SmartPt.h"

#ifdef COPY_CONTROL
void GetBook(Book b)
{
    // add code 
}
double TotalValue(const Book &b)
{
	return (b.m_nNum*(*b.m_ptPrice));
}

#endif



