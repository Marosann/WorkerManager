#pragma once
#include<iostream>
using namespace std;
#include<string>

//�T���饹
class Worker 
{
public:

	virtual void showInfo() = 0;// ��������ʾ
	virtual string getDeptName() = 0;// ���T��ʾ



	int m_ID; // �TID 
	string sm_name; // ��ǰ
	int m_DeptID; // ���TID




};