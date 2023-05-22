#include"workerManager.h"
#define rep(i,n)for(int i =0;i<n;i++)





WorkerManager::WorkerManager() 
{
	
	// �ե�����ϴ��ڤ��ʤ�����
	ifstream ifs;

	ifs.open(FILENAME,ios::in);

	if (!ifs.is_open())
	{

		// cout << "�ե����뤬���ڤ��ʤ�" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		this->m_FileIsEmpty = true;

		ifs.close();
		
		return;


	}


	// �ե�����Ϥ��뤬���ǩ`������äƤ��ʤ���
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		// cout << "�Τ���äƤ��ʤ���" << endl;

		m_EmpNum = 0;
		m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		
		ifs.close();

		return;


	}

	 //���ե������ǩ`������ڤ��Ƥ��롣
	int num = this->get_EmpNum();
	// cout << "�t������" << num << "�ˤ���" << endl;
	this->m_EmpNum = num;
	 // �����å����g��Ո
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// �ǩ`�������Ф˱��椹��

	this->init_Emp();








}

void WorkerManager::Show_Menu() 
{
	cout << "********************************" << endl;
	cout << "****** �T�������ƥ� ********" << endl;
	cout << "********************************" << endl;
	cout << "****** 0.exit ******************" << endl;
	cout << "****** 1.addWorkerinfo *********" << endl;
	cout << "****** 2.ShowWorkerinfo *********" << endl;
	cout << "****** 3.deletWorkerinfo *******" << endl;
	cout << "****** 4.editWorkerinfo ********" << endl;
	cout << "****** 5.searchWorkerinfo ******" << endl;
	cout << "****** 6.sort by number ********" << endl;
	cout << "****** 7.delete all ************" << endl;
	cout << "********************************" << endl;
	cout << endl;



}

bool is_Num(string& str) {

	{
		if (str.empty()||str.size()!=1) { cout << "���������ޥ�ɤ�������������" << endl; return false; }

		if (isdigit(str[0]))
		{

			return true;



		}

		else
		{
			cout << "���������ޥ�ɤ�������������" << endl;


			return false;
		}



	}


}

//��������������
int WorkerManager::get_EmpNum() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) 
	{
		num++;

	}
	return num;
	


}



WorkerManager::	~WorkerManager() 
{
	if (this->m_EmpArray != NULL) 
	{
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;

	}




}

void WorkerManager::Exit_System()
{

	cout << "�ޤ��Τ����ä򤪴������Ƥ���ޤ���" << endl;

	system("pause");

	exit(0);// �ץ������]���롣


}

//���¤����T�򥤥�ץå�
void WorkerManager ::Add_Emp()
{
	
	cout << "�¤��������T���������Ƥ���������" << endl;
	
	int addNum = 0;

	cin >> addNum;

	if (addNum > 0) 
	{

		// �¤������g����������Ԫ���������¼���������Ȥκ�
		int newSize = this->m_EmpNum + addNum;
		// �¤������g������

		Worker ** newSpace = new Worker* [newSize];
		// Ԫ�Υǩ`�����¤������g�˥��ԩ`����
		if (this->m_EmpArray != NULL)
		{
			rep(i,this->m_EmpNum)
			{

				newSpace[i] = this->m_EmpArray[i];



			}



		}

		rep(i, addNum) 
		{
			int id;
			string name;
			int dSelect; 

			cout << i + 1 << "��Ŀ���T�η��Ť����Ƥ���������" << endl;
			cin >> id;

			cout << i + 1 << "��Ŀ���T����ǰ�����Ƥ���������" << endl;
			cin >> name;

			cout << "��٥�����Ƥ���������" << endl;
			cout << "1.��ͨ��T" << endl;
			cout << "2.����" << endl;
			cout << "3.�ۆT" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker  = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;


			case 3:
				worker = new boss(id, name, 3);
				break;


				 
				 

			default:
				break;
			}

			// �¤������ä��T�Υݥ��󥿩`�����Ф˱��椹�롣
			newSpace[this->m_EmpNum + i] = worker;







		
		}	

		// Ԫ�Υ��ک`����ዷŤ���
		delete [] this->m_EmpArray;

		// �¤������g�Υݥ��󥿩`�����
		this->m_EmpArray = newSpace;
		// �T���������
		this->m_EmpNum = newSize; 

		this->m_FileIsEmpty = false;


		cout << "���٤����ˤ������" << addNum << "����줿��" << endl;

		this->save();






	}



	
	else
	{
		cout << "�Τ����ʤ��Τͣ�" << endl;
		
	}

	system("pause");

	system("cls");




};



//���ե�����򱣴�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	rep(i, this->m_EmpNum)
	{

		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->sm_name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;


	}

	ofs.close();



}


//���T�γ��ڻ�
void WorkerManager::init_Emp() 
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{

		Worker* worker = NULL;

		if (dId == 1)
		{

			worker = new  Employee(id, name, dId);
				


		}
		else if(dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new boss(id, name, dId);

		}
		this->m_EmpArray[index] = worker;
		index++;


	}


	ifs.close();




}

// // �T�����_��
void WorkerManager::Show_Emp() 
{
	// �ǩ`������äƤ��뤫���ж�
	if (this->m_FileIsEmpty)
	{

		cout << "�ե����뤬�ʤ������ǩ`������äƤ��ʤ��ߤ������ͣ�" << endl;

		 



	}
	else
	{
		rep(i, m_EmpNum)
		{
			// ���B�����ä��ơ��v���إ�������

			this->m_EmpArray[i]->showInfo();


		}
	}

	system("pause");
	system("cls");
	 
}

// �T��������
void WorkerManager::Del_Emp() 
{
	if(this->m_FileIsEmpty)
	{
	
		cout << "�ե����뤬���ڤ��ʤ������ǩ`������äƤ��ʤ��ߤ����裡" << endl;
	
	}
	else
	{
		cout << "��������ID��̤��ƣ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) 
		{
			// ���������ᡢ�ǩ`����ǰ���Ƥ���
			rep(i, this->m_EmpNum-1)
			{

				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				


			}
			this->m_EmpNum--;
			this->save();



		}
		else {

			cout << "ʧ��������ä��ߤ����������˱����˴��ڤ��Ƥ���Τ��ʣ�" << endl;


		}
	}

	system("pause");
	system("cls");



}

// �T���ڤ��뤫�ɤ��������Ф�λ�ä�-1��꥿�`��
int WorkerManager::IsExist(int id) 
{
	int index = -1;

	rep(i, this->m_EmpNum) 
	{
		if (this->m_EmpArray[i]->m_ID == id) 
		{
			index = 1;
			break;

		}


	}
	return index;
}


// Edit���v��
void WorkerManager::EditNewMember(int DID,int newid, string newname,Worker *pointer)
{

	switch (DID)
	{
	case 1:
		pointer = new Employee(newid, newname, DID);
		break;
	case 2:
		pointer = new Manager(newid, newname, DID);
		break;
	case 3:
		pointer = new boss(newid, newname, DID);
		break;

	default:
		break;
	}



}

// Edit���
void WorkerManager::Mod_Emp() 
{
	
	if (this->m_FileIsEmpty) {


		cout << "�ե����뤬���ڤ��ʤ������ǩ`������äƤ��ʤ��ߤ����裡" << endl;

	}
	else 
	{

		cout << "ID�̤��Ƥ裺��" << endl;
		int id;
		cin >> id;
		
		int ret = this->IsExist(id);
		if (ret != -1) 
		{
			delete this->m_EmpArray[ret];

			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "Ҋ�Ĥ��ä��裡" << id << "���ˤ�͡��¤���ID�̤��ƣ���" << endl;

			cin >> newID;

			cout << "��ǰ�ʤ�Ƥ����Σ�" <<endl;
			cin >> newName;

			cout << "�թ`�󡢂����ˣ�" << endl;
			cout << "1.��ͨ��T\n2.����\n3.boss" << endl;

			cin >> dSelect;
			Worker* worker = NULL;
			EditNewMember(dSelect, newID, newName, worker);

			this->m_EmpArray[ret] = worker;

			cout << "��ɤ����裡" << endl;

			this->save();
			
			 


		}
		else
		{
		
			cout << "�����ˤ����ˤ���Τ��ʡ��u����ʤ�?" << endl;
		
		}

	}


	system("pause");
	system("cls");



}

// Search
void WorkerManager::Find_Emp()
{

	if(this->m_FileIsEmpty)
	{
		cout << "�ե����뤬���ڤ��ʤ������Τ���äƤ��ʤ��褦�����ȡ����ɷ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "̽��������̤��ơ�	" << endl;
		cout << "1.ID��̽��" << endl;
		cout << "2.��ǰ��̽��" << endl;

		int select = 0;
		cin >> select;
		if(select == 1)
		{
			int ID = 0;
			cout << "ID�̤��ƣ�" << endl;

			cin >> ID;
			
			int ret = 	IsExist(ID);
			if (ret != -1) 
			{
				cout << "Ҋ�Ĥ����裡�����ˤǤ�����" <<endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else
			{
				cout << "���������ˤʤ��裡" << endl;
			}
		}
		else if(select ==2)
		{

			string name;
			cout << "��ǰ�̤��Ƥ�" << endl;
			cin >> name;
			bool flag = false;



			rep(i, m_EmpNum) 
			{
				if (this->m_EmpArray[i]->sm_name == name)
				{
					
					cout << "Ҋ�Ĥ����裡�����ˤǤ�����" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}

			if (!flag)
			{
				cout << "���������ˤʤ��裡" << endl;
			}

		}
		else
		{
			cout << "�����������裡" << endl;  
		}


		system("pause");
		system("cls");







	}





}

// sort
void  WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ե����뤬���ڤ��ʤ������Τ���äƤ��ʤ��褦�����ȡ����ɷ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�ɤΤ褦�ˁK���椨������	" << endl;
		cout << "1.ID��С�����" << endl;
		cout << "2.ID���󤭤��" << endl;

		int select = 0;
		cin >> select;

		rep(i,m_EmpNum)
		{
			int minOrMax = i;
			for(int j = i + 1;j<this->m_EmpNum;j++) 
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_ID>this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;

					}

				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;

					}
				}
			}
			
			if(i!=minOrMax)
			{
			
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;

			
			
			}




		}
		
		cout << "�K��ä��衫" << endl;
		this->save();
		this->Show_Emp();
	
		








	}



}


// clean
void WorkerManager::Clean_File()
{
	cout << "ȫ���ʤ��ʤ뤱�ɡ������ˤ����Σ�(yes or no)" << endl;
	cout << "1.yes" << endl;
	cout << "2.no" << endl;
	int select = 0;
	cin >> select;
	 

	if(select ==1)
	{
	
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if(this->m_EmpArray!=NULL)
		{
		rep(i,m_EmpNum)
		{
		
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;

		
		
		}
		
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		


		
		}
		cout << "�K��ä���" << endl;
		system("pause");
		system("cls");
	}

	else
	{
		cout << "����ͩ`" << endl;
		system("pause");
		system("cls");
	}

}