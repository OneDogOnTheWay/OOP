#include "stdafx.h"
#include <iostream>
#include <string>
#ifdef COPY_CONTROL

using namespace std;

class Book  
{  
public:  
	Book(string name,int num):m_strName(name),m_nNum(num),  
		m_ptPrice(new double(10.0))   
	{  
		cout<<m_strName<<"  Constructor"<<endl;  
	}  
	Book(string name = "default"):m_strName(name)  
	{  
		m_nNum = 100;  
		m_ptPrice = new double(999);  
		cout<<m_strName<<"  Constructor"<<endl;  
	}  
	Book(const Book &b)  
	{  
		m_nNum = b.m_nNum;  
		m_strName = b.m_strName;  
		m_ptPrice = new double(*b.m_ptPrice);  
		cout<<m_strName<<"  copy constructor..."<<endl;  
	}  
	const Book operator=(const Book b)  
	{  
		m_nNum = b.m_nNum;  
		m_strName = b.m_strName;  
		m_ptPrice = new double(*b.m_ptPrice);  
		cout<<m_strName<<" operator= call..."<<endl;  
		return *this;  

	}  
	void DisplayBookInf()  
	{  
		cout<<"BookName: "<<m_strName  
			<<" Num: "<<m_nNum<<" Price: "<<*m_ptPrice<<endl;  
	}  
	~Book()  
	{  
		//delete m_ptPrice;  
		cout<<m_strName<<"  Dstructor"<<endl;  
	}  
public:  
	string m_strName;  
	int m_nNum;  
	double *m_ptPrice;  

};  

void GetBook(Book b);
double TotalValue(const Book &b);
#endif