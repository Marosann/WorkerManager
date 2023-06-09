#include"workerManager.h"
#define rep(i,n)for(int i =0;i<n;i++)





WorkerManager::WorkerManager() 
{
	
	// ファイルは贋壓しない��栽
	ifstream ifs;

	ifs.open(FILENAME,ios::in);

	if (!ifs.is_open())
	{

		// cout << "ファイルが贋壓しない" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		this->m_FileIsEmpty = true;

		ifs.close();
		
		return;


	}


	// ファイルはあるが、デ�`タが秘っていない。
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		// cout << "採も秘っていないよ" << endl;

		m_EmpNum = 0;
		m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		
		ifs.close();

		return;


	}

	 //　ファイルもデ�`タも贋壓している。
	int num = this->get_EmpNum();
	// cout << "�t繁方は" << num << "繁だよ" << endl;
	this->m_EmpNum = num;
	 // スタック腎�g賦��
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// デ�`タを塘双に隠贋する

	this->init_Emp();








}

void WorkerManager::Show_Menu() 
{
	cout << "********************************" << endl;
	cout << "****** ���T砿尖システム ********" << endl;
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
		if (str.empty()||str.size()!=1) { cout << "屎しいコマンドを秘薦ください" << endl; return false; }

		if (isdigit(str[0]))
		{

			return true;



		}

		else
		{
			cout << "屎しいコマンドを秘薦ください" << endl;


			return false;
		}



	}


}

//　繁方を方える
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

	cout << "またのご旋喘をお棋ちしております。" << endl;

	system("pause");

	exit(0);// プログラムを�]じる。


}

//　仟しい���Tをインプット
void WorkerManager ::Add_Emp()
{
	
	cout << "仟しく秘れる���Tの方を秘れてください。" << endl;
	
	int addNum = 0;

	cin >> addNum;

	if (addNum > 0) 
	{

		// 仟しい腎�gの繁方が、圷の繁方と仟紗秘の繁方との才
		int newSize = this->m_EmpNum + addNum;
		// 仟しい腎�gを恬る

		Worker ** newSpace = new Worker* [newSize];
		// 圷のデ�`タを仟しい腎�gにコピ�`する
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

			cout << i + 1 << "桑朕の���Tの桑催を秘れてください。" << endl;
			cin >> id;

			cout << i + 1 << "桑朕の���Tの兆念を秘れてください。" << endl;
			cin >> name;

			cout << "レベルを秘れてください。" << endl;
			cout << "1.噸宥芙�T" << endl;
			cout << "2.砿尖��" << endl;
			cout << "3.叨�T" << endl;
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

			// 仟しく恬った���Tのポインタ�`を塘双に隠贋する。
			newSpace[this->m_EmpNum + i] = worker;







		
		}	

		// 圷のスペ�`スを��慧する
		delete [] this->m_EmpArray;

		// 仟しい腎�gのポインタ�`を厚仟
		this->m_EmpArray = newSpace;
		// ���T繁方を厚仟
		this->m_EmpNum = newSize; 

		this->m_FileIsEmpty = false;


		cout << "すべて頼阻したよん゛" << addNum << "繁秘れたよ" << endl;

		this->save();






	}



	
	else
	{
		cout << "採も秘れないのね��" << endl;
		
	}

	system("pause");

	system("cls");




};



//　ファイルを隠贋
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


//　���Tの兜豚晒
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

// // ���T秤�鵑鱸_く
void WorkerManager::Show_Emp() 
{
	// デ�`タが秘っているかを登僅
	if (this->m_FileIsEmpty)
	{

		cout << "ファイルがないか、デ�`タが秘っていないみたいだね��" << endl;

		 



	}
	else
	{
		rep(i, m_EmpNum)
		{
			// 謹�Bを旋喘して、�v方へアクセス

			this->m_EmpArray[i]->showInfo();


		}
	}

	system("pause");
	system("cls");
	 
}

// ���T秤�鵑鯱�茅
void WorkerManager::Del_Emp() 
{
	if(this->m_FileIsEmpty)
	{
	
		cout << "ファイルが贋壓しないか、デ�`タが秘っていないみただよ��" << endl;
	
	}
	else
	{
		cout << "��茅するIDを縮えて��" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) 
		{
			// ��茅した瘁、デ�`タを念に卞す。
			rep(i, this->m_EmpNum-1)
			{

				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				


			}
			this->m_EmpNum--;
			this->save();



		}
		else {

			cout << "払�，靴舛磴辰燭澆燭ぁ�この繁云輝に贋壓しているのかな��" << endl;


		}
	}

	system("pause");
	system("cls");



}

// ���T贋壓するかどうか、塘双の了崔か-1をリタ�`ン
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


// Edit喘�v方
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

// Edit秤��
void WorkerManager::Mod_Emp() 
{
	
	if (this->m_FileIsEmpty) {


		cout << "ファイルが贋壓しないか、デ�`タが秘っていないみただよ��" << endl;

	}
	else 
	{

		cout << "ID縮えてよ�此�" << endl;
		int id;
		cin >> id;
		
		int ret = this->IsExist(id);
		if (ret != -1) 
		{
			delete this->m_EmpArray[ret];

			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "��つかったよ��" << id << "の繁よね、仟しいID縮えて�此�" << endl;

			cin >> newID;

			cout << "兆念なんていうの��" <<endl;
			cin >> newName;

			cout << "ふ�`ん、�イと烹�" << endl;
			cout << "1.噸宥芙�T\n2.砿尖��\n3.boss" << endl;

			cin >> dSelect;
			Worker* worker = NULL;
			EditNewMember(dSelect, newID, newName, worker);

			this->m_EmpArray[ret] = worker;

			cout << "頼撹したよ��" << endl;

			this->save();
			
			 


		}
		else
		{
		
			cout << "云輝にこの繁いるのかな、�uじゃない?" << endl;
		
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
		cout << "ファイルが贋壓しないか、採も秘っていないようだけと。寄嬋健��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "冥す圭隈を縮えて゛	" << endl;
		cout << "1.IDで冥す" << endl;
		cout << "2.兆念で冥す" << endl;

		int select = 0;
		cin >> select;
		if(select == 1)
		{
			int ID = 0;
			cout << "ID縮えて��" << endl;

			cin >> ID;
			
			int ret = 	IsExist(ID);
			if (ret != -1) 
			{
				cout << "��つけたよ�，海糧砲任いぃ�" <<endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else
			{
				cout << "こういう繁ないよ��" << endl;
			}
		}
		else if(select ==2)
		{

			string name;
			cout << "兆念縮えてよ" << endl;
			cin >> name;
			bool flag = false;



			rep(i, m_EmpNum) 
			{
				if (this->m_EmpArray[i]->sm_name == name)
				{
					
					cout << "��つけたよ�，海糧砲任いぃ�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}

			if (!flag)
			{
				cout << "こういう繁ないよ��" << endl;
			}

		}
		else
		{
			cout << "１か２だけよ��" << endl;  
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
		cout << "ファイルが贋壓しないか、採も秘っていないようだけと。寄嬋健��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "どのように�Kべ紋えたい��	" << endl;
		cout << "1.IDが弌さい��" << endl;
		cout << "2.IDが寄きい��" << endl;

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
		
		cout << "�Kわったよ゛" << endl;
		this->save();
		this->Show_Emp();
	
		








	}



}


// clean
void WorkerManager::Clean_File()
{
	cout << "畠何なくなるけど、云輝にいいの��(yes or no)" << endl;
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
		cout << "�Kわったよ" << endl;
		system("pause");
		system("cls");
	}

	else
	{
		cout << "だよね�`" << endl;
		system("pause");
		system("cls");
	}

}