#include"manager.h"

using namespace std;

Manager::Manager(int id, string name, int DID) {

	this->sm_name = name;
	this->m_ID = id;
	this->m_DeptID = DID;




};

void Manager::showInfo() 
{
	cout << "�TID������" << this->m_ID
		<< "\t��ǰ��" << this->sm_name
		<< "\t�N:  " << this->getDeptName() << endl;




}// ��������ʾ
string Manager::getDeptName()
{

	return string("����");


}// ���T��ʾ