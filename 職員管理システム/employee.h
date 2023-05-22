//　基幹職員
#pragma once
using namespace std;
#include"worker.h"
class Employee :public Worker
{

public:

	Employee(int id,string name,int did);
	


	 void showInfo() ;// 個人情報表示
	 string getDeptName() ;// 部門表示



};