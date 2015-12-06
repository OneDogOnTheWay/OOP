// Grade____Adiministrater.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>                                         ///////////////////////输出控制格式
#include <string>

#include <stdlib.h>

using namespace std;
////////////////////Student basic information//////////////////建立一个学生信息的链表
typedef struct student{
	unsigned m_id;
	string m_name;
	unsigned m_age;
	string m_sex;
	string m_address;
	string m_contact;
	string m_dormitory;
	struct student *m_next; /////////建立一个链表,单向链表，双向链表，单向循环链表，双向循环链表，二叉树这些都是由结构体衍生的基本数据类型
}student;
///////////////////////////////Function////////////////////////
class CStudent{
private:
	student *head;
public:
	CStudent(){
		head = new student;
		head->m_id = 0;
		head->m_name = "noname";
		head->m_next = NULL;
	}
	~CStudent(){
		student *p = head, *q;
		while (p){                                           ///////////////////////释放掉整个链表
			q = p;
			p = q->m_next;
			delete q;
		}
	}
	student readdata(int model);/////////////////////////model=1;不读取学号，2;不读取姓名,	其他，读取所有信息//////////////
	void entering();
	bool insert(const student &astu);
	student *findid(unsigned id) const;
	student *findname(const string &name) const;
	student *findsex(const string &sex) const;
	student *finddormitory(const string &dormitory) const;
	unsigned boys() const;/////////////////////////将成员函数声明为常数，const必须同时出现在声明和定义中，否则会出现一个编译时的错误
	unsigned girls() const;
	unsigned headcount() const;
	bool eraseid();
	bool erasename();
	bool modifyid();
	bool modifyname();
	void Show() const;
	void query() const;
	/////////////////////friend//////////////////////////////
	void friend statistics(const CStudent &aclss);
	void friend erase(CStudent &aclss);
	void friend modify(CStudent &aclss);
};

string readstring(){///////////////////////////////////////////////////////数据的输入////功能性函数
	string str;
	while (cin.get() != '\n')
		cin >> str;
	return str;
}

////////////////////define readdata function///////////////////////
student CStudent::readdata(int model){
	student tmp;
	if (model != 1){ cout << "学号:"; cin >> tmp.m_id; }
	if (model != 2){ cout << "姓名;"; tmp.m_name = readstring(); }
	cin >> tmp.m_age;

	cout << "性别:";
	tmp.m_sex = readstring();
	cout << "住址:";
	tmp.m_address = readstring();
	cout << "联系方式:";
	tmp.m_contact = readstring();
	cout << "寝室:";
	tmp.m_dormitory = readstring();
	return tmp;
}
////////////////////////////define entring function 学号唯一性和输入有效性///////////////////////////
void CStudent::entering(){
	student tmp;
	cout << "学号(0 to return):";
	cin >> tmp.m_id;
	while (tmp.m_id){
		if (findid(tmp.m_id) == NULL) {
			cout << "姓名:";
			tmp.m_name = readstring();
			
			///cout << "年龄:";
		    ///cin >> tmp.m_age;
			
			
			cout << "性别:";
			tmp.m_sex = readstring();
			cout << "住址;";
			tmp.m_address = readstring();
			cout << "联系方式:";
			tmp.m_contact = readstring();
			cout << "寝室:";
			tmp.m_dormitory = readstring();
			insert(tmp);
		}
		else
			cout << "重复的学号:" << tmp.m_id << endl;
		cout << "学号(0 to return):";
		cin >> tmp.m_id;
	}
}
///////////////////////////////学生信息的查询/////////////////////////
/////////////////////////////define findid function///////////////////
student *CStudent::findid(unsigned id) const {
	student *p;
	for (p = head; p->m_next; p = p->m_next)
	if (p->m_next->m_id == id)
		return p;
	return NULL;
}
////////////////define findname function//////////////////////////////
student *CStudent::findname(const string &name) const{
	student *p;
	for (p = head; p->m_next; p = p->m_next)
	if (p->m_next->m_name == name)
		return p;
	return NULL;
}
////////////////define findsex function///////////////////////////////
student *CStudent::findsex(const string &sex) const{
	student *p;
	for (p = head; p->m_next; p = p->m_next)
	if (p->m_next->m_sex == sex)
		return p;
	return NULL;
}
/////////////////define finddormitory function///////////////////////
student *CStudent::finddormitory(const string &dormitory) const {
	student *p;
	for (p = head; p->m_next; p = p->m_next)
	if (p->m_next->m_dormitory == dormitory)
		return p;
	return NULL;
}
/////////////////define insert function/////////////////////////////
bool CStudent::insert(const student &astu) {
	student *newnode, *p = head;
	if (p->m_next == NULL){
		p->m_next = new student(astu);
		p->m_next->m_next = NULL;
		return true;
	}
	while (p->m_next){
		if (p->m_next->m_id == astu.m_id){
			cout << "重复的学号，插入失败！\n";
			return false;
		}
		if (p->m_next->m_id > astu.m_id){
			newnode = new student(astu);
			newnode->m_next = p->m_next;
			p->m_next = newnode;
			return true;
		}
		p = p->m_next;
	}
	p->m_next = new student(astu);
	p->m_next->m_next = NULL;
	return true;
}
//////////////////////////学生信息的统计////////////////////////////
/////////////////////define boys function///////////////////////////
unsigned CStudent::boys() const {
	unsigned cnt = 0;
	student *p;
	for (p = head->m_next; p; p = p->m_next)
	if (p->m_sex == "男")
		++cnt;
	return cnt;
}
//////////////////////define grils function/////////////////////////
unsigned CStudent::girls() const {
	unsigned cnt = 0;
	student *p;
	for (p = head->m_next; p; p = p->m_next)
	if (p->m_sex == "女")
		++cnt;
	return cnt;
}
/////////////////////define headcount function/////////////////////
unsigned CStudent::headcount() const {
	unsigned cnt = 0;
	student *p;
	for (p = head->m_next; p; p = p->m_next, ++cnt);
	return cnt;
}
/////////////////////学生信息的删除（学号）///////////////////////////////
bool CStudent::eraseid() {
	student *p, *q;
	unsigned id;
	cout << "输入要删除的学号:";
	cin >> id;
	p = findid(id);
	if (p == NULL){
		cout << "没有找到学号是\"" << id << "\"的学生，删除失败！\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}
/////////////////////学生信息的删除(姓名)////////////////////////////////
bool CStudent::erasename(){
	student *q, *p;
	string name;
	cout << "输入要删除的姓名:";
	name = readstring();
	p = findname(name);
	if (p == NULL){
		cout << "没有找到姓名是\"" << name << "\"的学生，删除失败!\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}

////////////////////学生信息的更改(地址）///////////////////////////////
bool CStudent::modifyid() {
	student *p, tmp;
	unsigned id;
	cout << "输入要修改的学号";
	cin >> id;
	p = findid(id);
	if (p == NULL){
		cout << "没有找到学号是\"" << id << "\"的学生，删除失败！\n";
		return false;
	}
	tmp = readdata(1);
	tmp.m_id = id;
	*p = tmp;
	return true;
}
////////////////////学生信息的更改（姓名）///////////////////////////////
bool CStudent::modifyname() {
	student *p, tmp;
	string name;
	cout << "输入要修改的姓名";
	cin >> name;
	name = readstring();
	p = findname(name);
	if (p == NULL){
		cout << "没有找到姓名是\"" << name << "\"的学生，删除失败！\n";
		return false;
	}
	tmp = readdata(2);
	tmp.m_name = name;
	*p = tmp;
	return true;
}

////////////////////////选项菜单///////////////////////////////////////
int menu() {
	int choice;
	do {
		system("cls");
		cout << "\t*****************************************\n";
		cout << "\t*          学生基本信息管理系统         *\n";
		cout << "\t========================================*\n";
		cout << "\t*            1,录入学生信息             *\n";
		cout << "\t*            2,显示学生信息             *\n";
		cout << "\t*            3,查询学生信息             *\n";
		cout << "\t*            4,添加学生信息             *\n";
		cout << "\t*            5,统计学生信息             *\n";
		cout << "\t*            6,删除学生信息             *\n";
		cout << "\t*            7,修改管理系统             *\n";
		cout << "\t*            0,退出管理系统             *\n";
		cout << "\t*****************************************\n";
		cout << "\n\t请选择：";
		cin >> choice;
	} while (choice<0 || choice>7);
	return choice;
}
//////////////////////////////////show////////////////////////////
void show(student *p){
	cout << p->m_id << " " << p->m_name << " " << p->m_age << " ";
	cout << p->m_sex << " " << p->m_address << " ";
	cout << p->m_contact << " " << p->m_dormitory << endl;
}
/////////////////////////////////show()///////////////////////////
void CStudent::Show() const {
	student *p;
	cout << "-----------------------------------------------\n";
	for (p = head->m_next; p; p = p->m_next)
		show(p);
	cout << "-----------------------------------------------\n";
	system("pause");
}
////////////////////////////////query()///////////////////////////
void CStudent::query() const {
	int select;
	unsigned id;
	string name;
	student *p;
	cout << "1,按学号查询\n2,按姓名查询\n0,返回\n";
	cin >> select;
	switch (select){
	case 1:cout << "请输入学号："; cin >> id;
		if (p = findid(id))
			show(p->m_next);
		break;
	case 2:cout << "请输入姓名："; name = readstring();
		if (p = findname(name))
			show(p->m_next);
		break;
	case 0:return;
	default:cout << "选择错误。\n";
	}
	system("pause");
}
//////////////////////////////三个友元处理///////////////////////////
//////////statistics()/////友元不需要带CStudent:://直接定义即可//////
void statistics(const CStudent &a) {
	unsigned total = a.headcount();
	unsigned boys = a.boys();
	unsigned girls = a.girls();
	cout << "学生总数：" << total << "人。\n";
	cout << "其中,男生：" << boys << "名。\n";
	cout << "女生：" << girls << "名。\n";
	system("pause");
}
/////////////////////////erase()///////////////////////////////////
void erase(CStudent &a) {
	int select;
	unsigned id;
	string name;
	student *p, *q;
	cout << "1,按学号删除\n2,按姓名删除\n0,返回\n";
	cin >> select;
	switch (select){
	case 1:cout << "请输入学号："; cin >> id;
		if (p = a.findid(id)){
			q = p->m_next;
			p->m_next = q->m_next;
			delete q;
			cout << "成功删除" << id << "的信息。\n";
		}
		break;
	case 2:cout << "请输入姓名："; name = readstring();
		if (p = a.findname(name)){
			q = p->m_next;
			p->m_next = q->m_next;
			delete q;
			cout << "成功删除" << name << "的信息。\n";
		}
		break;
	case 0:return;
	default:cout << "选择错误。\n";
	}
	system("pause");
}
//////////////////////////modify()///////////////////////////
void modify(CStudent &a) {
	int select;
		cout << "1,按学号修改\n2，按姓名修改\n0，返回";
	cin >> select;
	switch (select){
	case 1:if (a.modifyid())
		cout << "修改成功。\n";
		break;
	case 2:if (a.modifyname())
		cout << "修改成功。\n";
		break;
	case 0:return;
	default:cout << "选择错误。\n";
	}
	system("system");
}
///////////////////////////////main()////////////////////////
int main(){
	CStudent a;
	int an;
	do{
		an = menu();
		switch (an) {
		case 1: a.entering();
			break;
		case 2: a.Show();
			break;
		case 3: a.query();
			break;
		case 4: a.entering();
			break;
		case 5: statistics(a);
			break;
		case 6: erase(a);
			break;
		case 7: modify(a);
			break;
		case 0: break;
		default:cout << "选择错误。\n";
			break;
		}
	} while (an);
	system("pause");
	return 0;
}