#include"employee.h"

Employee::Employee(int id, string name, int did) {


	this->m_ID = id;
	this->sm_name = name;
	this->m_DeptID = did;



}


// ��������ʾ
void Employee::showInfo() {

	cout << "�TID������" << this->m_ID
		<< "\t��ǰ��" << this->sm_name
		<< "\t�N:  " << this->getDeptName() << endl;



}
// ���T��ʾ
string Employee::getDeptName() {

	return string("��ͨ��T");

}