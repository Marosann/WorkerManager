#include"boss.h"

using namespace std;


boss::boss(int id, string name, int DID) 
{

	this->sm_name = name;
	this->m_ID = id;
	this->m_DeptID = DID;
}

// 個人情報表示
void boss::showInfo() 
{



	cout << "職員ID：　　" << this->m_ID
		<< "\t名前：" << this->sm_name
		<< "\t職種:  " << this->getDeptName() << endl;



}

string boss::getDeptName() 
{

	return string("役員");



}