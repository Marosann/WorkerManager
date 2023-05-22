#pragma once
#include"worker.h"

using namespace std;
//役員クラス
class boss : public Worker 
{

public:
	
	boss(int id, string name, int DID);

	void showInfo();// 個人情報表示
	string getDeptName();// 部門表示


};