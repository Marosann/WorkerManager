//�������T
#pragma once
using namespace std;
#include"worker.h"
class Employee :public Worker
{

public:

	Employee(int id,string name,int did);
	


	 void showInfo() ;// ��������ʾ
	 string getDeptName() ;// ���T��ʾ



};