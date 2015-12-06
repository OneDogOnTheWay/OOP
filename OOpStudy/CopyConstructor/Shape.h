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
	virtual double GetArea(void) const ;// ��ȡ���
	virtual double GetCircumference(void) const ;// ��ȡ�ܳ�

	friend std::ostream & operator<<(std::ostream &,const CShape &);// ��Ԫ�����޷��̳�

private:
	int   m_nLineWidth;// ͼ���������
	static int m_nCShapeNum;// ��̬���ݳ�Ա��������ϵ��ֻ��һ��ʵ��
};

