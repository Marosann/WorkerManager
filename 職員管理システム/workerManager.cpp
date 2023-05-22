#include"workerManager.h"
#define rep(i,n)for(int i =0;i<n;i++)





WorkerManager::WorkerManager() 
{
	
	// ファイルは存在しない場合
	ifstream ifs;

	ifs.open(FILENAME,ios::in);

	if (!ifs.is_open())
	{

		// cout << "ファイルが存在しない" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		this->m_FileIsEmpty = true;

		ifs.close();
		
		return;


	}


	// ファイルはあるが、データが入っていない。
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		// cout << "何も入っていないよ" << endl;

		m_EmpNum = 0;
		m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		
		ifs.close();

		return;


	}

	 //　ファイルもデータも存在している。
	int num = this->get_EmpNum();
	// cout << "総人数は" << num << "人だよ" << endl;
	this->m_EmpNum = num;
	 // スタック空間申請
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// データを配列に保存する

	this->init_Emp();








}

void WorkerManager::Show_Menu() 
{
	cout << "********************************" << endl;
	cout << "****** 職員管理システム ********" << endl;
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
		if (str.empty()||str.size()!=1) { cout << "正しいコマンドを入力ください" << endl; return false; }

		if (isdigit(str[0]))
		{

			return true;



		}

		else
		{
			cout << "正しいコマンドを入力ください" << endl;


			return false;
		}



	}


}

//　人数を数える
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

	cout << "またのご利用をお待ちしております。" << endl;

	system("pause");

	exit(0);// プログラムを閉じる。


}

//　新しい職員をインプット
void WorkerManager ::Add_Emp()
{
	
	cout << "新しく入れる職員の数を入れてください。" << endl;
	
	int addNum = 0;

	cin >> addNum;

	if (addNum > 0) 
	{

		// 新しい空間の人数が、元の人数と新加入の人数との和
		int newSize = this->m_EmpNum + addNum;
		// 新しい空間を作る

		Worker ** newSpace = new Worker* [newSize];
		// 元のデータを新しい空間にコピーする
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

			cout << i + 1 << "番目の職員の番号を入れてください。" << endl;
			cin >> id;

			cout << i + 1 << "番目の職員の名前を入れてください。" << endl;
			cin >> name;

			cout << "レベルを入れてください。" << endl;
			cout << "1.普通社員" << endl;
			cout << "2.管理職" << endl;
			cout << "3.役員" << endl;
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

			// 新しく作った職員のポインターを配列に保存する。
			newSpace[this->m_EmpNum + i] = worker;







		
		}	

		// 元のスペースを釈放する
		delete [] this->m_EmpArray;

		// 新しい空間のポインターを更新
		this->m_EmpArray = newSpace;
		// 職員人数を更新
		this->m_EmpNum = newSize; 

		this->m_FileIsEmpty = false;


		cout << "すべて完了したよん～" << addNum << "人入れたよ" << endl;

		this->save();






	}



	
	else
	{
		cout << "何も入れないのね？" << endl;
		
	}

	system("pause");

	system("cls");




};



//　ファイルを保存
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


//　職員の初期化
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

// // 職員情報を開く
void WorkerManager::Show_Emp() 
{
	// データが入っているかを判断
	if (this->m_FileIsEmpty)
	{

		cout << "ファイルがないか、データが入っていないみたいだね！" << endl;

		 



	}
	else
	{
		rep(i, m_EmpNum)
		{
			// 多態を利用して、関数へアクセス

			this->m_EmpArray[i]->showInfo();


		}
	}

	system("pause");
	system("cls");
	 
}

// 職員情報を削除
void WorkerManager::Del_Emp() 
{
	if(this->m_FileIsEmpty)
	{
	
		cout << "ファイルが存在しないか、データが入っていないみただよ！" << endl;
	
	}
	else
	{
		cout << "削除するIDを教えて：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) 
		{
			// 削除した後、データを前に移す。
			rep(i, this->m_EmpNum-1)
			{

				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				


			}
			this->m_EmpNum--;
			this->save();



		}
		else {

			cout << "失敗しちゃったみたい。この人本当に存在しているのかな？" << endl;


		}
	}

	system("pause");
	system("cls");



}

// 職員存在するかどうか、配列の位置か-1をリターン
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


// Edit用関数
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

// Edit情報
void WorkerManager::Mod_Emp() 
{
	
	if (this->m_FileIsEmpty) {


		cout << "ファイルが存在しないか、データが入っていないみただよ！" << endl;

	}
	else 
	{

		cout << "ID教えてよ：　" << endl;
		int id;
		cin >> id;
		
		int ret = this->IsExist(id);
		if (ret != -1) 
		{
			delete this->m_EmpArray[ret];

			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "見つかったよ！" << id << "の人よね、新しいID教えて：　" << endl;

			cin >> newID;

			cout << "名前なんていうの？" <<endl;
			cin >> newName;

			cout << "ふーん、偉い人？" << endl;
			cout << "1.普通社員\n2.管理職\n3.boss" << endl;

			cin >> dSelect;
			Worker* worker = NULL;
			EditNewMember(dSelect, newID, newName, worker);

			this->m_EmpArray[ret] = worker;

			cout << "完成したよ！" << endl;

			this->save();
			
			 


		}
		else
		{
		
			cout << "本当にこの人いるのかな、噓じゃない?" << endl;
		
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
		cout << "ファイルが存在しないか、何も入っていないようだけと。大丈夫？" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "探す方法を教えて～	" << endl;
		cout << "1.IDで探す" << endl;
		cout << "2.名前で探す" << endl;

		int select = 0;
		cin >> select;
		if(select == 1)
		{
			int ID = 0;
			cout << "ID教えて！" << endl;

			cin >> ID;
			
			int ret = 	IsExist(ID);
			if (ret != -1) 
			{
				cout << "見つけたよ！この人でいい？" <<endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else
			{
				cout << "こういう人ないよ！" << endl;
			}
		}
		else if(select ==2)
		{

			string name;
			cout << "名前教えてよ" << endl;
			cin >> name;
			bool flag = false;



			rep(i, m_EmpNum) 
			{
				if (this->m_EmpArray[i]->sm_name == name)
				{
					
					cout << "見つけたよ！この人でいい？" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}

			if (!flag)
			{
				cout << "こういう人ないよ！" << endl;
			}

		}
		else
		{
			cout << "１か２だけよ！" << endl;  
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
		cout << "ファイルが存在しないか、何も入っていないようだけと。大丈夫？" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "どのように並べ替えたい？	" << endl;
		cout << "1.IDが小さい順" << endl;
		cout << "2.IDが大きい順" << endl;

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
		
		cout << "終わったよ～" << endl;
		this->save();
		this->Show_Emp();
	
		








	}



}


// clean
void WorkerManager::Clean_File()
{
	cout << "全部なくなるけど、本当にいいの？(yes or no)" << endl;
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
		cout << "終わったよ" << endl;
		system("pause");
		system("cls");
	}

	else
	{
		cout << "だよねー" << endl;
		system("pause");
		system("cls");
	}

}