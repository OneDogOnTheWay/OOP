#pragma once
#include <string>
#include <iostream>


class CShape;
std::ostream &operator<<(std::ostream &, const CShape &);

class CShape
{
public:
	CShape(void);  
	CShape(const int lineWidth);
	void SetLineWidth(const int lineWidth);
	int GetLineWidth() const;


	virtual ~CShape(void);
	virtual double GetArea(void) const ;// 获取面积
	virtual double GetCircumference(void) const ;// 获取周长

	friend std::ostream & operator<<(std::ostream &,const CShape &);// 友元函数无法继承

private:
	int   m_nLineWidth;// 图形线条宽度
	static int m_nCShapeNum;// 静态数据成员在派生体系中只有一个实例
};

