#pragma once
#include "shape.h"
#include <iostream>


class CMyRect;
std::ostream & operator<<(std::ostream &, const CMyRect &);

class CMyRect :	public CShape
{
public:
	CMyRect(void);
	CMyRect(const double ,const double n);
	void SetWidth(const double);
	void SetHeight(const double);
	const double GetWidth(void) const ;
	const double GetHeigth(void) const ;
	void SetLineWidth(const int lineWidth);// 覆盖基类的非虚函数

	// 友元函数不能继承，所以在派生类之中要重新实现
	friend std::ostream & operator<<(std::ostream &, const CMyRect &);

	// 以下是基类的虚拟函数，重写
	~CMyRect(void);
	//double GetArea(void) const ;
	double GetCircumference(void) const;
private:
	double m_dWidth;
	double m_dHeight;
};

