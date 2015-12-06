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
	void SetLineWidth(const int lineWidth);// ���ǻ���ķ��麯��

	// ��Ԫ�������ܼ̳У�������������֮��Ҫ����ʵ��
	friend std::ostream & operator<<(std::ostream &, const CMyRect &);

	// �����ǻ�������⺯������д
	~CMyRect(void);
	//double GetArea(void) const ;
	double GetCircumference(void) const;
private:
	double m_dWidth;
	double m_dHeight;
};

