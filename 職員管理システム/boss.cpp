#include"boss.h"

using namespace std;


boss::boss(int id, string name, int DID) 
{

	this->sm_name = name;
	this->m_ID = id;
	this->m_DeptID = DID;
}

// ��������ʾ
void boss::showInfo() 
{



	cout << "�TID������" << this->m_ID
		<< "\t��ǰ��" << this->sm_name
		<< "\t�N:  " << this->getDeptName() << endl;



}

string boss::getDeptName() 
{

	return string("�ۆT");



}