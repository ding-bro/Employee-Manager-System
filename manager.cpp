#include "manager.h"


// manager::manager()
//{
//	this->m_name = name;
//	this->m_departmentid = id;
//	this->m_personernumber = number;
//}
 manager::manager(string name, int id, int number)
 {
	 this->m_name = name;
	 this->m_departmentid = id;
	 this->m_personernumber = number;
 }

void manager::workinformation()
{
	cout << "ְ������ǣ� " << this->m_personernumber << endl; // 1.Ա��  2.����  3.�ϰ�
	cout << "ְ�������ǣ� " << this->m_name << endl;
	cout << "ְ�����ű���ǣ� " << this->getworkname() << endl;
	cout << "ְ����λְ���ǣ� ����ϰ��ɷ�������" << endl;
}

string manager::getworkname()
{
	return string("����");
}


