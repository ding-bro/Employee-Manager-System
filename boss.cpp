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
	cout << "ְ������ǣ� " << this->m_personernumber << endl; // 1.Ա��  2.����  3.�ϰ�
	cout << "ְ�������ǣ� " << this->m_name << endl;
	cout << "ְ�����ű���ǣ� " << this->getworkname() << endl;
	cout << "ְ����λְ���ǣ� ����˾���е�ְ��" << endl;

}

string boss::getworkname()
{
	return string("�ϰ�");
}