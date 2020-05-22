#include"employee.h"

//employee::employee()
//{
//	this->m_name = name;
//	this->m_personernumber = number;
//	this->m_departmentid = id;
//}
employee::employee(string name, int id, int number)
{
	this->m_name = name;
	this->m_departmentid = id;
	this->m_personernumber = number;
}

void employee::workinformation()
{
	cout << "职工编号是： " << this->m_personernumber<< endl; // 1.员工  2.经理  3.老板
	cout << "职工姓名是： " << this->m_name << endl;
	cout << "职工部门编号是： " << this->getworkname() << endl;
	cout << "职工岗位职责是： 完成经理派发的任务" << endl;
}

string employee::getworkname()
{
	return string("员工");     // 用 return 返回
}