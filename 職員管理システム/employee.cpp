#include"employee.h"

Employee::Employee(int id, string name, int did) {


	this->m_ID = id;
	this->sm_name = name;
	this->m_DeptID = did;



}


// 個人情報表示
void Employee::showInfo() {

	cout << "職員ID：　　" << this->m_ID
		<< "\t名前：" << this->sm_name
		<< "\t職種:  " << this->getDeptName() << endl;



}
// 部門表示
string Employee::getDeptName() {

	return string("普通社員");

}