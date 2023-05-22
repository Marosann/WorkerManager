#pragma once
#include<iostream>
using namespace std;
#include<string>

//職員クラス
class Worker 
{
public:

	virtual void showInfo() = 0;// 個人情報表示
	virtual string getDeptName() = 0;// 部門表示



	int m_ID; // 職員ID 
	string sm_name; // 名前
	int m_DeptID; // 部門ID




};