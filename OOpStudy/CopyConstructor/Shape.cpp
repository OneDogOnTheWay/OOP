#include "StdAfx.h"
#include "Shape.h"
#include <iostream>

using namespace std;

CShape::CShape(void)
{
	cout<<"CShape::CShape()......"<<endl;
	cout<<"------^<>^����ÿһ��^<>^------^"<<endl;
	m_nLineWidth = 0;
}

CShape::CShape(const int lineWidth):m_nLineWidth(lineWidth)
{

}
CShape::~CShape(void)
{
	cout<<"CShape::~CShape(void)......"<<endl;
	cout<<"Happy in every day......"<<endl;
}
//void CShape::Display(void)
//{
//	//cout<<"***********CShape Object Information Output***********"<<endl;
//	//cout<<"the lineWidth of CShape is:  "<<m_nLineWidth<<endl;
//}
double CShape::GetArea(void) const
{
	cout<<"CShape::GetArea()...."<<endl;
	return 0.0;
	// ���಻ʵ���������
}
double CShape::GetCircumference(void) const 
{
	cout<<"CShape::GetCircumference(): "<<endl;
	return 0.0;
	// ���಻ʵ���ܳ�����
}
void CShape::SetLineWidth(const int lineWidth)
{
	cout<<"CShape::SetLineWidth(): "<<endl;
	m_nLineWidth = lineWidth;
}

int CShape::GetLineWidth(void) const
{
	cout<<"CShape::GetLineWidth(): "<<endl;
	return m_nLineWidth;
}

ostream & operator<<(ostream &os,const CShape &sh)
{
	cout<<"***********CShape Object Information Output***********"<<endl;
	return os;
}
int CShape::m_nCShapeNum = 0;// �������ʼ����̬���ݳ�Ա