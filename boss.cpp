#include"boss.h"


//boss::boss()
//{
//	this->m_name = name;
//	this->m_departmentid = id;
//	this->m_personernumber = number;
//}

boss::boss(string name,int id,int number)
{
	this->m_name = name;
	this->m_departmentid = id;
	this->m_personernumber = number;
}

void boss:: workinformation()
{
	cout << "职工编号是： " << this->m_personernumber << endl; // 1.员工  2.经理  3.老板
	cout << "职工姓名是： " << this->m_name << endl;
	cout << "职工部门编号是： " << this->getworkname() << endl;
	cout << "职工岗位职责是： 管理公司所有的职务" << endl;

}

string boss::getworkname()
{
	return string("老板");
}