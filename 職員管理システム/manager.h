#pragma once
#include"worker.h"

using namespace std;
//�������饹
class Manager :public Worker {


public:

	Manager(int id,string name,int DID);

	 void showInfo() ;// ��������ʾ
	 string getDeptName();// ���T��ʾ





};