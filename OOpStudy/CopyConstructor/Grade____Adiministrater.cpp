// Grade____Adiministrater.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>                                         ///////////////////////������Ƹ�ʽ
#include <string>

#include <stdlib.h>

using namespace std;
////////////////////Student basic information//////////////////����һ��ѧ����Ϣ������
typedef struct student{
	unsigned m_id;
	string m_name;
	unsigned m_age;
	string m_sex;
	string m_address;
	string m_contact;
	string m_dormitory;
	struct student *m_next; /////////����һ������,��������˫����������ѭ������˫��ѭ��������������Щ�����ɽṹ�������Ļ�����������
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
		while (p){                                           ///////////////////////�ͷŵ���������
			q = p;
			p = q->m_next;
			delete q;
		}
	}
	student readdata(int model);/////////////////////////model=1;����ȡѧ�ţ�2;����ȡ����,	��������ȡ������Ϣ//////////////
	void entering();
	bool insert(const student &astu);
	student *findid(unsigned id) const;
	student *findname(const string &name) const;
	student *findsex(const string &sex) const;
	student *finddormitory(const string &dormitory) const;
	unsigned boys() const;/////////////////////////����Ա��������Ϊ������const����ͬʱ�����������Ͷ����У���������һ������ʱ�Ĵ���
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

string readstring(){///////////////////////////////////////////////////////���ݵ�����////�����Ժ���
	string str;
	while (cin.get() != '\n')
		cin >> str;
	return str;
}

////////////////////define readdata function///////////////////////
student CStudent::readdata(int model){
	student tmp;
	if (model != 1){ cout << "ѧ��:"; cin >> tmp.m_id; }
	if (model != 2){ cout << "����;"; tmp.m_name = readstring(); }
	cin >> tmp.m_age;

	cout << "�Ա�:";
	tmp.m_sex = readstring();
	cout << "סַ:";
	tmp.m_address = readstring();
	cout << "��ϵ��ʽ:";
	tmp.m_contact = readstring();
	cout << "����:";
	tmp.m_dormitory = readstring();
	return tmp;
}
////////////////////////////define entring function ѧ��Ψһ�Ժ�������Ч��///////////////////////////
void CStudent::entering(){
	student tmp;
	cout << "ѧ��(0 to return):";
	cin >> tmp.m_id;
	while (tmp.m_id){
		if (findid(tmp.m_id) == NULL) {
			cout << "����:";
			tmp.m_name = readstring();
			
			///cout << "����:";
		    ///cin >> tmp.m_age;
			
			
			cout << "�Ա�:";
			tmp.m_sex = readstring();
			cout << "סַ;";
			tmp.m_address = readstring();
			cout << "��ϵ��ʽ:";
			tmp.m_contact = readstring();
			cout << "����:";
			tmp.m_dormitory = readstring();
			insert(tmp);
		}
		else
			cout << "�ظ���ѧ��:" << tmp.m_id << endl;
		cout << "ѧ��(0 to return):";
		cin >> tmp.m_id;
	}
}
///////////////////////////////ѧ����Ϣ�Ĳ�ѯ/////////////////////////
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
			cout << "�ظ���ѧ�ţ�����ʧ�ܣ�\n";
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
//////////////////////////ѧ����Ϣ��ͳ��////////////////////////////
/////////////////////define boys function///////////////////////////
unsigned CStudent::boys() const {
	unsigned cnt = 0;
	student *p;
	for (p = head->m_next; p; p = p->m_next)
	if (p->m_sex == "��")
		++cnt;
	return cnt;
}
//////////////////////define grils function/////////////////////////
unsigned CStudent::girls() const {
	unsigned cnt = 0;
	student *p;
	for (p = head->m_next; p; p = p->m_next)
	if (p->m_sex == "Ů")
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
/////////////////////ѧ����Ϣ��ɾ����ѧ�ţ�///////////////////////////////
bool CStudent::eraseid() {
	student *p, *q;
	unsigned id;
	cout << "����Ҫɾ����ѧ��:";
	cin >> id;
	p = findid(id);
	if (p == NULL){
		cout << "û���ҵ�ѧ����\"" << id << "\"��ѧ����ɾ��ʧ�ܣ�\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}
/////////////////////ѧ����Ϣ��ɾ��(����)////////////////////////////////
bool CStudent::erasename(){
	student *q, *p;
	string name;
	cout << "����Ҫɾ��������:";
	name = readstring();
	p = findname(name);
	if (p == NULL){
		cout << "û���ҵ�������\"" << name << "\"��ѧ����ɾ��ʧ��!\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}

////////////////////ѧ����Ϣ�ĸ���(��ַ��///////////////////////////////
bool CStudent::modifyid() {
	student *p, tmp;
	unsigned id;
	cout << "����Ҫ�޸ĵ�ѧ��";
	cin >> id;
	p = findid(id);
	if (p == NULL){
		cout << "û���ҵ�ѧ����\"" << id << "\"��ѧ����ɾ��ʧ�ܣ�\n";
		return false;
	}
	tmp = readdata(1);
	tmp.m_id = id;
	*p = tmp;
	return true;
}
////////////////////ѧ����Ϣ�ĸ��ģ�������///////////////////////////////
bool CStudent::modifyname() {
	student *p, tmp;
	string name;
	cout << "����Ҫ�޸ĵ�����";
	cin >> name;
	name = readstring();
	p = findname(name);
	if (p == NULL){
		cout << "û���ҵ�������\"" << name << "\"��ѧ����ɾ��ʧ�ܣ�\n";
		return false;
	}
	tmp = readdata(2);
	tmp.m_name = name;
	*p = tmp;
	return true;
}

////////////////////////ѡ��˵�///////////////////////////////////////
int menu() {
	int choice;
	do {
		system("cls");
		cout << "\t*****************************************\n";
		cout << "\t*          ѧ��������Ϣ����ϵͳ         *\n";
		cout << "\t========================================*\n";
		cout << "\t*            1,¼��ѧ����Ϣ             *\n";
		cout << "\t*            2,��ʾѧ����Ϣ             *\n";
		cout << "\t*            3,��ѯѧ����Ϣ             *\n";
		cout << "\t*            4,���ѧ����Ϣ             *\n";
		cout << "\t*            5,ͳ��ѧ����Ϣ             *\n";
		cout << "\t*            6,ɾ��ѧ����Ϣ             *\n";
		cout << "\t*            7,�޸Ĺ���ϵͳ             *\n";
		cout << "\t*            0,�˳�����ϵͳ             *\n";
		cout << "\t*****************************************\n";
		cout << "\n\t��ѡ��";
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
	cout << "1,��ѧ�Ų�ѯ\n2,��������ѯ\n0,����\n";
	cin >> select;
	switch (select){
	case 1:cout << "������ѧ�ţ�"; cin >> id;
		if (p = findid(id))
			show(p->m_next);
		break;
	case 2:cout << "������������"; name = readstring();
		if (p = findname(name))
			show(p->m_next);
		break;
	case 0:return;
	default:cout << "ѡ�����\n";
	}
	system("pause");
}
//////////////////////////////������Ԫ����///////////////////////////
//////////statistics()/////��Ԫ����Ҫ��CStudent:://ֱ�Ӷ��弴��//////
void statistics(const CStudent &a) {
	unsigned total = a.headcount();
	unsigned boys = a.boys();
	unsigned girls = a.girls();
	cout << "ѧ��������" << total << "�ˡ�\n";
	cout << "����,������" << boys << "����\n";
	cout << "Ů����" << girls << "����\n";
	system("pause");
}
/////////////////////////erase()///////////////////////////////////
void erase(CStudent &a) {
	int select;
	unsigned id;
	string name;
	student *p, *q;
	cout << "1,��ѧ��ɾ��\n2,������ɾ��\n0,����\n";
	cin >> select;
	switch (select){
	case 1:cout << "������ѧ�ţ�"; cin >> id;
		if (p = a.findid(id)){
			q = p->m_next;
			p->m_next = q->m_next;
			delete q;
			cout << "�ɹ�ɾ��" << id << "����Ϣ��\n";
		}
		break;
	case 2:cout << "������������"; name = readstring();
		if (p = a.findname(name)){
			q = p->m_next;
			p->m_next = q->m_next;
			delete q;
			cout << "�ɹ�ɾ��" << name << "����Ϣ��\n";
		}
		break;
	case 0:return;
	default:cout << "ѡ�����\n";
	}
	system("pause");
}
//////////////////////////modify()///////////////////////////
void modify(CStudent &a) {
	int select;
		cout << "1,��ѧ���޸�\n2���������޸�\n0������";
	cin >> select;
	switch (select){
	case 1:if (a.modifyid())
		cout << "�޸ĳɹ���\n";
		break;
	case 2:if (a.modifyname())
		cout << "�޸ĳɹ���\n";
		break;
	case 0:return;
	default:cout << "ѡ�����\n";
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
		default:cout << "ѡ�����\n";
			break;
		}
	} while (an);
	system("pause");
	return 0;
}