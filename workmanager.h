#pragma once
#include <iostream>
using namespace std;
#include"manager.h"
#include"employee.h"
#include"boss.h"
#include"worker.h"
class workmanager 
{
public:

	void showmenu();

	void exitmenu();

	int id;
	int number;
	string name;

	workmanager();

	int m_emptynum;           //  记录文件中的人数个数  

	worker** m_emptyarrary;   //  员工数组的指针

	void addperson();    //  添加职工

	void showperson();

	~workmanager();  //  析构函数手动释放内存

	void save();//  保存文件函数

	bool m_fileempty;   //  添加bool类型的属性，判断文件是否为空

	int get_employeenum();  //  记录文件打开时的人数个数,  返回是int值

	void init_employee();   //  初始化员工函数

	int isexist(int id); // 判断员工是否存在的函数，如果存在，返回职工在数组中的位置，如果不存在，返回-1

	void deleteperson();

	void modifyperson();

	void searchperson();

	void sortperson();

	void repeat();

	void clearperson();


};