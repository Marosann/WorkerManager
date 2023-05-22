#pragma once //�إå��`�ե��������}�����
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
	//��˥�`���
	void Show_Menu();
	
	void Exit_System();
		
	//���T��ӛ�h

	int m_EmpNum;

	//���T���Хݥ��󥿩`

	Worker** m_EmpArray;

	//���¤����T�򥤥�ץå�

	void Add_Emp();

	//���ե�����򱣴�
	void save();


	// �ե�������Ф˥ǩ`������äƤ��뤫�ɤ���
	bool m_FileIsEmpty;

	//��������������
	int get_EmpNum();

	//���T�γ��ڻ�
	void init_Emp();


	// �T�����_��
	void Show_Emp();

	// �T��������
	void Del_Emp();

	// �T���ڤ��뤫�ɤ��������Ф�λ�ä�-1��꥿�`��
	int IsExist(int id);

	// Edit���
	void Mod_Emp();

	// Edit���v��
	void EditNewMember(int DID,int newid,string newname, Worker *pointer);

	// Search
	void Find_Emp();
	// sort
	void Sort_Emp();

	// clean
	void Clean_File();
	 




	~WorkerManager();



};