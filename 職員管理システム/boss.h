#pragma once
#include"worker.h"

using namespace std;
//�ۆT���饹
class boss : public Worker 
{

public:
	
	boss(int id, string name, int DID);

	void showInfo();// ��������ʾ
	string getDeptName();// ���T��ʾ


};