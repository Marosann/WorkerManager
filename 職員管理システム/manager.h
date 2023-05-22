#pragma once
#include"worker.h"

using namespace std;
//管理職クラス
class Manager :public Worker {


public:

	Manager(int id,string name,int DID);

	 void showInfo() ;// 個人情報表示
	 string getDeptName();// 部門表示





};