#include<string>
#include<cctype>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{

	/*test��
	
	Worker * worker = NULL;
	worker = new Employee(1, "A", 222);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "B", 3);
	worker->showInfo();
	delete worker;
	
	worker = new boss(3, "C", 4);
	worker->showInfo();
	delete worker;*/
	
	
	WorkerManager wm;
	int num_choice = -1 ;
	int flag = 0;
	string choice;//��`���`�Υ��ޥ�ɤ򱣴档
	
	while (true) 
	{
		wm.Show_Menu();
		if (flag) {

			cout << "���������ޥ�ɤ��������������͡�" << endl;

			flag = 0;
		}
		else { cout << "�������ޥ�ɤ���������������(0~7)" << endl; }

		cin >> choice;//���ޥ�ɤ��ܤ���

		if (is_Num(choice))
		{
			 num_choice = stoi(choice);
		}
	

		
		


		switch (num_choice)
		{


		case 0:    // exit
			wm.Exit_System();
			break;
		case 1:    // add
			wm.Add_Emp();

			break;
		case 2:    // show
			wm.Show_Emp();

			break;
		case 3:    // delete
			wm.Del_Emp();

			break;
		case 4:    // edit 
			wm.Mod_Emp();

			break;
		case 5:	   // search
			wm.Find_Emp();
			 
			break;
		case 6:    // sort
			wm.Sort_Emp();

			break;
		case 7:    // delete all


			break;



		default:
			 flag = 1;
			system("cls");
			
			break;
		}



	}










	system("pause");

	return 0;


}