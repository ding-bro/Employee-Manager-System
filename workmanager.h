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

	int m_emptynum;           //  ��¼�ļ��е���������  

	worker** m_emptyarrary;   //  Ա�������ָ��

	void addperson();    //  ���ְ��

	void showperson();

	~workmanager();  //  ���������ֶ��ͷ��ڴ�

	void save();//  �����ļ�����

	bool m_fileempty;   //  ���bool���͵����ԣ��ж��ļ��Ƿ�Ϊ��

	int get_employeenum();  //  ��¼�ļ���ʱ����������,  ������intֵ

	void init_employee();   //  ��ʼ��Ա������

	int isexist(int id); // �ж�Ա���Ƿ���ڵĺ�����������ڣ�����ְ���������е�λ�ã���������ڣ�����-1

	void deleteperson();

	void modifyperson();

	void searchperson();

	void sortperson();

	void repeat();

	void clearperson();


};