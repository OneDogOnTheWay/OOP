#include "StdAfx.h"
#include "MyRect.h"
#include <iostream>

using namespace std;
CMyRect::CMyRect(void)
{
	cout<<"CMyRect::CMyRect()......"<<endl;
	m_dHeight = 0;
	m_dWidth  = 0;
}
CMyRect::CMyRect(const double w,const double h):m_dWidth(w),m_dHeight(h)
{
		cout<<"CMyRect::CMyRect()......"<<endl;
}

CMyRect::~CMyRect(void)
{
	cout<<"CMyRect::~CMyRect()......"<<endl;
}
//void CMyRect::Display()
//{
//	cout<<"********CMyRect Objct Information Output ********"<<endl;
//	//CShape::Display()
//	cout<<"The the Width of the CMyRect is : "<< m_dWidth<<endl;
//	cout<<"The the Height of the CMyRect is : "<< m_dHeight<<endl;
//		
//}
// 重写基类的非虚拟函数，主要目的是为了演示覆盖
void CMyRect::SetLineWidth(const int lineWidth)
{

	cout<<"CMyRect::SetLineWidth()......."<<endl;//在派生类中，重新定义了基类的非虚拟函数，实现覆盖基类的方法
	CShape::SetLineWidth(lineWidth);
}


void CMyRect::SetHeight(const double h)
{
	cout<<"CMyRect::SetHeight()......."<<endl;
	m_dHeight = h;
}
void CMyRect::SetWidth(const double w)
{
	cout<<"CMyRect::SetWidth()......."<<endl;
	m_dWidth = w;
}


const double CMyRect::GetWidth(void) const 
{
	cout<<"CMyRect::GetWidth()......."<<endl;
	return m_dWidth;
}
const double CMyRect::GetHeigth(void) const

{	
	cout<<"CMyRect::GetHeigth()......."<<endl;
	return m_dHeight;
}

//double CMyRect::GetArea(void) const
//{
//	cout<<"CMyRect::GetArea()......."<<endl;
//	double ret = m_dWidth * m_dHeight;
//	return ret;
//}

double CMyRect::GetCircumference(void) const
{
	cout<<"CMyRect::GetCircumference()......."<<endl;
	double ret = 2 * (m_dHeight + m_dWidth);
	return ret;
}
