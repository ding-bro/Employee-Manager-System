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
	cout << "ְ������ǣ� " << this->m_personernumber<< endl; // 1.Ա��  2.����  3.�ϰ�
	cout << "ְ�������ǣ� " << this->m_name << endl;
	cout << "ְ�����ű���ǣ� " << this->getworkname() << endl;
	cout << "ְ����λְ���ǣ� ��ɾ����ɷ�������" << endl;
}

string employee::getworkname()
{
	return string("Ա��");     // �� return ����
}