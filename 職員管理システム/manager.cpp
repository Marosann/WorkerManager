#include"manager.h"

using namespace std;

Manager::Manager(int id, string name, int DID) {

	this->sm_name = name;
	this->m_ID = id;
	this->m_DeptID = DID;




};

void Manager::showInfo() 
{
	cout << "職員ID：　　" << this->m_ID
		<< "\t名前：" << this->sm_name
		<< "\t職種:  " << this->getDeptName() << endl;




}// 個人情報表示
string Manager::getDeptName()
{

	return string("管理職");


}// 部門表示