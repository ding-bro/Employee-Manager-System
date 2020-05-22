#include <iostream>
using namespace std;
#include"manager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"workmanager.h"

int main()
{

	//manager show;
	//manager exit;
	//worker* e = new employee;
	//e->m_name = "丁丁";
	//e->m_departmentid = 1;
	//e->m_personernumber = 1649;
	//e->workinformation();
	//
	//cout << endl;
	//
	//worker * m = new manager;
	//m->m_name = "能能";
	//m->m_departmentid = 2;
	//m->m_personernumber = 2001;
	//m->workinformation();

	//cout << endl;

	//worker* b = new boss;
	//b->m_name = "丁丁";
	//b->m_personernumber = 164985;
	//b->m_departmentid = 3;
	//b->workinformation();
	
	workmanager m;

	while (true)
	{
		
		m.showmenu();
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 0:
			m.exitmenu();
			break;
		case 1:
			m.addperson();
			break;
		case 2:
			m.showperson();
			break;
		case 3:

		//	m.deleteperson();
		//{ 
		//	int ret = m.isexist(1);
		//if (ret = -1)
		//{
		//	cout << "不存在" << endl;      //  当switch语句中，命令过长时会报错，此时要把命令包括break一起用大括号括起来
		//}
		//else
		//{
		//	cout << "存在" << endl;
		//}

		//break;
		//}
			m.deleteperson();
			break;
		case 4:
			m.modifyperson();
			break;
		case 5:
			m.searchperson();
			break;
		case 6:
			m.sortperson();
			break;
		case 7:
			m.clearperson();
			break;
		default:
			cout << "请输入有效的数字!" << endl;
			//system("pause");
			//system("cls");
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
	
	return 0;
}