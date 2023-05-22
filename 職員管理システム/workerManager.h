#pragma once //ヘッダーファイル重複を防ぐ
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"


#include<fstream>
#define FILENAME  "list.txt"


using namespace std;

bool is_Num(string& str);


class WorkerManager {


public:

	
	WorkerManager();
	//メニューを表す
	void Show_Menu();
	
	void Exit_System();
		
	//　職員数記録

	int m_EmpNum;

	//　職員配列ポインター

	Worker** m_EmpArray;

	//　新しい職員をインプット

	void Add_Emp();

	//　ファイルを保存
	void save();


	// ファイルの中にデータが入っているかどうか
	bool m_FileIsEmpty;

	//　人数を数える
	int get_EmpNum();

	//　職員の初期化
	void init_Emp();


	// 職員情報を開く
	void Show_Emp();

	// 職員情報を削除
	void Del_Emp();

	// 職員存在するかどうか、配列の位置か-1をリターン
	int IsExist(int id);

	// Edit情報
	void Mod_Emp();

	// Edit用関数
	void EditNewMember(int DID,int newid,string newname, Worker *pointer);

	// Search
	void Find_Emp();
	// sort
	void Sort_Emp();

	// clean
	void Clean_File();
	 




	~WorkerManager();



};