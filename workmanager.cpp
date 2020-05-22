#include "workmanager.h"
#include <fstream>
#define filename "Savefile.txt"

void workmanager::showmenu()
{
	cout << "*************************职工管理系统**************************" << endl;
	cout << endl;
	cout << "**********************0.退出管理程序*************************" << endl;
	cout << "  ********************1.增加职工信息***********************" << endl;
	cout << "  ********************2.显示职工信息***********************" << endl;
	cout << "  ********************3.删除职工信息***********************" << endl;
	cout << "  ********************4.修改职工信息***********************" << endl;
	cout << "  ********************5.查找职工信息***********************" << endl;
	cout << "  ********************6.按照编号排序***********************" << endl;
	cout << "  ********************7.清空所有文档***********************" << endl;
	cout << endl;
	cout << "请输入您的选择" << endl;
}
void workmanager::exitmenu()
{
	cout << "您已成功退出系统，欢迎下次使用！" << endl;
	system("pause");
	exit(0);   // 退出函数，关键字 
}




//  虽然实现了添加员工功能，但是每次开始运行文件的时候，并没有把文件中的数据读取到程序中，而是一直初始化
//  1. 第一次使用，文件未创建
//  2. 文件存在，但是被用户清空
//  3. 文件存在，并且保存职工所有的数据



workmanager::workmanager()
{
	 ifstream ifs;                      //  建立读文件 
	 ifs.open(filename, ios::in);

	 //  判断文件是否存在，如果不存在数据，把属性置为空，吧bool类型数据emptyfile置为true
	 if (!ifs.is_open())          
	 {
		 cout << "文件不存在" << endl;
		 this->m_emptynum = 0;
		 this->m_fileempty = true;
		 this->m_emptyarrary = NULL;
		 ifs.close();
		 return;
	 }

	 char end;       //   建立一个末尾数据，  ifs读取它，如果读到底还没有数据，就说明这个文件存在，但是内部数据为空
	 ifs >> end;
	if (ifs.eof())            //   end of line 文件的结尾， 
	{
		 cout << "文件内部数据为空" << endl;
		 this->m_emptynum = 0;
		 this->m_fileempty = true;
		 this->m_emptyarrary = NULL;
		 ifs.close();
		 return; 
	}

	// 3. 文件存在并且记录数据
	//int num = this->get_employeenum();    //      测试人数
	//cout << num << endl;
	//this->m_emptynum =  num;
	// 
	// 开辟空间
	//this->m_emptyarrary = new worker * [this->m_emptynum];
	// 将文件的数据存入到数组当中
	//init_employee();
	//this->save();
	//for (int i = 0; i < this->m_emptynum; i++)
	//{
	//	cout <<"员工名："<< this->m_emptyarrary[i]->m_name << endl;
	//	cout << "员工个人编号" << this->m_emptyarrary[i]->m_personernumber << endl;
	//	cout << "员工部门" << this->m_emptyarrary[i]->m_departmentid << endl;
	//	//this->m_emptyarrary[i]->workinformation();
	//}
}

int workmanager::get_employeenum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);


	string name;
	int number;
	string id;


	int num = 0;   //  创建记录人数属性
	while (ifs >>name && ifs >> number && ifs >> id) //  如果ifs读到了id，number，name数据，说明文件里有数据
	{
		// 如果有数据，while循环将会一直读取，直到把文件里的数据都读完
		num++;
	}
	ifs.close();
	return num;	
}

//  初始化数据
void workmanager::init_employee()
{
	string name;
	int id;
	int number;
	ifstream ifs;
	ifs.open(filename, ios::in);

	int value = 0;  //  数组的索引下标

	while (ifs>>number && ifs>>name && ifs>>id)
	{
		worker* valuework = NULL;   //  父类指针指向子类对象   ，new

		if (id==1)
		{
			valuework = new employee(name,id,number);
		}
		else if (id==2)
		{
			valuework = new manager(name, id, number);
		}
		else
		{
			valuework = new boss(name, id, number);
		}
		//  放入维护的数组中
		this->m_emptyarrary[value] = valuework;     //  value 是索引，一开始是从0循环，value++后就是通过while一直自增循环直到数据完毕
		value++;
	}
}


 // 添加职工功能：

void workmanager::addperson()
{
	cout << "请输入您要添加职工的输量" << endl;

	int addnum = 0;  //  保存用户的输入数量
	cin >> addnum;



	if (addnum > 0)  // 大于0添加
	{
		//  计算新空间的大小   如果用户要重新添加，那么原来的用户数量占用的空间就不够用,
		//  所以要重新开辟一个内存空间包含原来的数量和现在添加的数量。

		// 新空间大小=原来记录人数+新增人数：
		int newsize = this->m_emptynum + addnum;

		// 开辟新空间：
		worker** newspace = new worker * [newsize];     //  指针数组

		//  将原来的人数数据拷贝到新的空间下：
		if (this->m_emptyarrary != NULL)    //  原来的数组人数指针如果有数据的话，将现有的人数数据拷贝至新空间
		{
			for (int i = 0; i < this->m_emptynum; i++)
			{
				newspace[i] = this->m_emptyarrary[i];
			}
		}

		//  批量添加新的数据
		for (int i = 0; i < addnum; i++)  //  此处是addnum    i < 用户的输入数量
		{
			int id;
			string name;
			int personnumber;

			cout << "请输入您要添加的第" << i + 1 << "个职工的个人编号" << endl;
			cin >> personnumber;
			cout << "请输入您要添加的第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;
			cout << "请输入您要添加的第" << i + 1 << "个职工的部门编号" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> id;
			//if (personnumber==this->m_emptyarrary[i]->m_personernumber)
			//{
			//	cout << "此员工个人编号已存在" << endl;
			//	break;
			//}
			//else if (name== this->m_emptyarrary[i]->m_name)
			//{
			//	cout << "此员工姓名已存在" << endl;
			//	break;
			//}
			worker* workspace = NULL;

			switch (id)
			{
			case 1:
				workspace = new employee(name, id, personnumber);
				break;
			case 2:
				workspace = new manager(name, id, personnumber);
				break;
			case 3:
				workspace = new boss(name, id, personnumber);
				break;
			default:
				cout << "请输入有效的数值" << endl;
				break;
			}
			newspace [this->m_emptynum + i] = workspace;  // 将已有的人数保存在数字中
		}
		
		//  释放原有空间：
		delete[]this->m_emptyarrary;

		//  更新新空间指向：
		this->m_emptyarrary = newspace;         //  注意 ：  等号左边必须为可修改的左值
		                                        //   至关重要的问题
		//  更新新的职工人数：
		this->m_emptynum = newsize;

		//  更新判断文件不为空的时候，将bool类型更新为false            后加
		this->m_fileempty = false;

	/*	int ding=this->get_emptynum();
		cout << ding << endl;*/

		cout << "添加" << addnum << "个职工成功" << endl;

		this->save();
	}
	else
	{
		cout << "添加的职工数量必须大于0，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}

//void workmanager::repeat()
//{
//	if (this.personnumber==this->m_emptyarrary[i]->m_personernumber)
//	{
//	cout << "此员工个人编号已存在" << endl;
//	break;
//	}
//else if (name== this->m_emptyarrary[i]->m_name)
//	{
//	cout << "此员工姓名已存在" << endl;
//	break;
//	}
//}

void workmanager::showperson()
{
	//if (this->m_fileempty=false)
	//{
	//	for (int i = 0; i < m_emptynum; i++)
	//	{
	//		this->m_emptyarrary[i]->workinformation();
	//		cout << 1 << endl;
	//		cout << endl;
	//		break;
	//	}
	//}
	//else
	//{
	//	cout << "没有职工信息" << endl;
	//}
	if (this->m_emptynum==0)
	{
		cout << "没有职工信息" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_emptynum; i++)
		{
			this->m_emptyarrary[i]->workinformation();
			//cout << "职工岗位职责是： 完成老板派发的任务" << endl;
			//break;
		}

	}

	system("pause");
	system("cls");
}

int workmanager::isexist(int id)
{
	int exist = -1;  // 一开始认为它是不存在的，置为-1
	for (int i = 0; i < this->m_emptynum; i++)
	{
		if (this->m_emptyarrary[i]->m_personernumber==id)  //  找职工
		{
			exist = i;  //  职工存在，返回职工在数组中的位置
			break;
		}
	}
	return exist;
}

void workmanager::deleteperson()  //  删除员工
{
	if (this->m_fileempty==true)
	{
		cout << "文件为空，不能删除" << endl;
	}
	else
	{
		int person = 0;
		cout << "请输入您要删除的员工个人编号" << endl;
		cin >> person;
		int ret = this->isexist(person);
		if (ret==-1)
		{
			cout << "此员工不存在" << endl;
		}
		else
		{
			for (int i = 0; i < this->m_emptynum-1; i++)
			{
				this->m_emptyarrary[i] = this->m_emptyarrary[i + 1];
			}
			this->m_emptynum--;
			this->save();
			cout << "删除成功！" << endl; 
		}
	}
	system("pause");
	system("cls");
}

void workmanager::modifyperson()
{
	if (this->m_fileempty)
	{
		cout << "文件不存在，无法修改" << endl;
	}
	else
	{
		cout << "请输入您要修改职工的职工个人编号用于查询" << endl;
		int number = 0;
		cin >> number;
		int retb = this->isexist(number);
		if (retb==-1)
		{
			cout << "此员工不存在" << endl;
		}
		else
		{
			this->showperson();
			cout << "请输入您要修改的选项" << endl;
			cout << "1.姓名" << endl;
			cout << "2.个人编号" << endl;
			cout << "3.部门编号 : 以下为部门编号信息：" << endl;
			cout<< "①.员工" << endl;
			cout << "②.经理" << endl;
			cout << "③.老板" << endl;
			int id = 0;
			cin >> id;

			string newname;
			int newnumber;
			int newid;

			cout << "请输入修改后的姓名：" << endl;
			cin >> newname;
			cout << "请输入修改后的个人编号：" << endl;
			cin >> newid;
			cout << "①.员工" << endl;
			cout << "②.经理" << endl;
			cout << "③.老板" << endl;
			cout << "请输入修改后的部门编号：" << endl;
			cin >> newnumber;

			worker* workspace = NULL;
			switch (newnumber)
			{
			case 1:
				workspace = new employee(newname, newid, newnumber);
				break;
			case 2:
				workspace = new manager(newname, newid, newnumber);
				break;
			case 3:
				workspace = new boss(newname, newid, newnumber);
				break;
			default:
				cout << "请输入有效的数值" << endl;
				break;
			}
			this->m_emptyarrary[retb] = workspace;
			this->save();
			cout << "修改成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workmanager::searchperson()
{
	cout << "请输入您要查找的员工个人编号" << endl;
	int personid;
	cin >> personid;
	for (int i = 0; i < this->m_emptynum; i++)
	{
		if (this->m_fileempty==true)
		{
			cout << "文件不存在" << endl;
			break;
		}
		else
		{
			if (this->isexist(personid)==-1)
			{
				cout << "此员工不存在" << endl;
				break;
			}
			else
			{
				this->m_emptyarrary[i]->m_personernumber=personid;

				personid = i;
				this->m_emptyarrary[i]->workinformation();
				
			}
		}
	}
	system("pause");
	system("cls");
}

void workmanager::sortperson()
{
	cout << "是否按照员工编号进行排序？" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	int select;
	cin >> select;

	//  利用冒泡排序：

	//while (true)
	//{
	//	if (select == 1)
	//	{
	//		for (int i = 0; i < this->m_emptynum - 1; i++)
	//		{
	//			cout << "1.按照升序排列" << endl;
	//			cout << "2.按照降序排列" << endl;
	//			int id;
	//			cin >> id;

	//			if (this->m_fileempty == true)
	//			{
	//				cout << "文件不存在" << endl;
	//				break;
	//			}
	//			
	//			if (id==1)
	//			{
	//				for (int j = 0; j < this->m_emptynum - 1 - i; j++)
	//				{
	//					int temp;
	//					if (this->m_emptyarrary[j + 1]->m_personernumber < this->m_emptyarrary[j]->m_personernumber)
	//					{
	//						temp = this->m_emptyarrary[j + 1]->m_personernumber;
	//						this->m_emptyarrary[j + 1]->m_personernumber = this->m_emptyarrary[j]->m_personernumber;
	//						this->m_emptyarrary[j]->m_personernumber = temp;
	//					}
	//				}
	//				this->save();
	//				this->showperson();
	//				break;
	//			}
	//			else
	//			{
	//				for (int i = 0; i < this->m_emptynum-1; i++)
	//				{
	//					for (int j = 0; j < this->m_emptynum-1-i; j++)
	//					{
	//						int temp;
	//						if (this->m_emptyarrary[j + 1]->m_personernumber > this->m_emptyarrary[j]->m_personernumber)
	//						{
	//							temp = this->m_emptyarrary[j + 1]->m_personernumber;
	//							this->m_emptyarrary[j + 1]->m_personernumber = this->m_emptyarrary[j]->m_personernumber;
	//							this->m_emptyarrary[j]->m_personernumber = temp;
	//						}
	//					}
	//				}
	//				this->save();
	//				this->showperson();
	//				break;
	//			}
	//	
	//		}
	//		break;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//system("pasue");
	//system("cls");


	// 利用自建一个最大或最小的变量来完成

	while (true)
	{
		if (select == 1)
		{
			cout << "1.按照升序排列" << endl;
			cout << "2.按照降序排列" << endl;
			int id;
			cin >> id;

			for (int i = 0; i < m_emptynum; i++)
			{
				int minormax = i;  // 建立一个变量来定义最小值的下标，最大值的下标
				for (int j = i + 1; j < m_emptynum; j++)  // j的下标在i的之前
				{
					if (id==1)
					{
						if (m_emptyarrary[minormax]->m_personernumber > m_emptyarrary[j]->m_personernumber) //  升序
						{
							// 如果定义的最小的数比j大，就说明，定义的数并不是最小的,j比i（minormax）还小
							minormax = j;  // 此时就把j改为最小的数，相当于交换
						}
					}
					else
					{
						if (m_emptyarrary[minormax]->m_personernumber< m_emptyarrary[j]->m_personernumber)  // 降序
						{
							// 降序与升序相反
							minormax = j;
						}
					}

					// 判断一开始认定的最小值或最大值是不是 计算出来的最小值和最大值，如果不是，交换数据
					if (i != minormax)
					{
						worker* temp = m_emptyarrary[i];
						m_emptyarrary[i] = m_emptyarrary[minormax];
						m_emptyarrary[minormax] = temp;
					}
				}
			}
			this->save();
			this->showperson();
			break;
		}
		else
		{
			break;
		}
	}
	system("pasue");
	system("cls");
		
}

void workmanager::clearperson()
{
	cout << "是否要清空所有职工的数据？" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	int select;
	cin >> select;
	while (true)
	{
		if (select == 1)
		{
			ofstream ofs(filename, ios::trunc);   // 删除文件后再重新创建  trunc
			ofs.close();                         //  删除内部指针的数据，同时别忘了删除文件里的数据

			if (this->m_fileempty == true)
			{
				cout << "文件不存在" << endl;
				break;
			}
			else if (this->m_emptynum == 0)
			{
				cout << "文件内部数据已经为空" << endl;
				break;
			}
			else
			{
				for (int i = 0; i < this->m_emptynum; i++)
				{
					delete this->m_emptyarrary[i];
				}
			}
			this->m_emptynum = 0;
			delete[] this->m_emptyarrary;            //  不要忘记维护内部的指针，这是重要的一步
			this->m_emptyarrary = NULL;
			this->m_fileempty = true;
		}
		else
		{
			break;
		}
	}
	cout << "清空成功！" << endl;
	system("pasue");
	system("cls");
}



void workmanager::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);    //   用输出的方式写文件
	   //  将每个人的数据写入文件中：
		for (int i = 0; i <this->m_emptynum ; i++)
		{
			ofs << this->m_emptyarrary[i]->m_name << endl;
			ofs	<< this->m_emptyarrary[i]->m_personernumber << endl;
			ofs	<< this->m_emptyarrary[i]->getworkname() << endl;
		}
		ofs.close();
}
 






workmanager::~workmanager()                    //  手动释放堆区数据
{
	if (this->m_emptyarrary != NULL)
	{
		delete[]this->m_emptyarrary;
		this->m_emptyarrary = NULL;
	}
}