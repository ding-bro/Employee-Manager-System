#include "workmanager.h"
#include <fstream>
#define filename "Savefile.txt"

void workmanager::showmenu()
{
	cout << "*************************ְ������ϵͳ**************************" << endl;
	cout << endl;
	cout << "**********************0.�˳��������*************************" << endl;
	cout << "  ********************1.����ְ����Ϣ***********************" << endl;
	cout << "  ********************2.��ʾְ����Ϣ***********************" << endl;
	cout << "  ********************3.ɾ��ְ����Ϣ***********************" << endl;
	cout << "  ********************4.�޸�ְ����Ϣ***********************" << endl;
	cout << "  ********************5.����ְ����Ϣ***********************" << endl;
	cout << "  ********************6.���ձ������***********************" << endl;
	cout << "  ********************7.��������ĵ�***********************" << endl;
	cout << endl;
	cout << "����������ѡ��" << endl;
}
void workmanager::exitmenu()
{
	cout << "���ѳɹ��˳�ϵͳ����ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);   // �˳��������ؼ��� 
}




//  ��Ȼʵ�������Ա�����ܣ�����ÿ�ο�ʼ�����ļ���ʱ�򣬲�û�а��ļ��е����ݶ�ȡ�������У�����һֱ��ʼ��
//  1. ��һ��ʹ�ã��ļ�δ����
//  2. �ļ����ڣ����Ǳ��û����
//  3. �ļ����ڣ����ұ���ְ�����е�����



workmanager::workmanager()
{
	 ifstream ifs;                      //  �������ļ� 
	 ifs.open(filename, ios::in);

	 //  �ж��ļ��Ƿ���ڣ�������������ݣ���������Ϊ�գ���bool��������emptyfile��Ϊtrue
	 if (!ifs.is_open())          
	 {
		 cout << "�ļ�������" << endl;
		 this->m_emptynum = 0;
		 this->m_fileempty = true;
		 this->m_emptyarrary = NULL;
		 ifs.close();
		 return;
	 }

	 char end;       //   ����һ��ĩβ���ݣ�  ifs��ȡ������������׻�û�����ݣ���˵������ļ����ڣ������ڲ�����Ϊ��
	 ifs >> end;
	if (ifs.eof())            //   end of line �ļ��Ľ�β�� 
	{
		 cout << "�ļ��ڲ�����Ϊ��" << endl;
		 this->m_emptynum = 0;
		 this->m_fileempty = true;
		 this->m_emptyarrary = NULL;
		 ifs.close();
		 return; 
	}

	// 3. �ļ����ڲ��Ҽ�¼����
	//int num = this->get_employeenum();    //      ��������
	//cout << num << endl;
	//this->m_emptynum =  num;
	// 
	// ���ٿռ�
	//this->m_emptyarrary = new worker * [this->m_emptynum];
	// ���ļ������ݴ��뵽���鵱��
	//init_employee();
	//this->save();
	//for (int i = 0; i < this->m_emptynum; i++)
	//{
	//	cout <<"Ա������"<< this->m_emptyarrary[i]->m_name << endl;
	//	cout << "Ա�����˱��" << this->m_emptyarrary[i]->m_personernumber << endl;
	//	cout << "Ա������" << this->m_emptyarrary[i]->m_departmentid << endl;
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


	int num = 0;   //  ������¼��������
	while (ifs >>name && ifs >> number && ifs >> id) //  ���ifs������id��number��name���ݣ�˵���ļ���������
	{
		// ��������ݣ�whileѭ������һֱ��ȡ��ֱ�����ļ�������ݶ�����
		num++;
	}
	ifs.close();
	return num;	
}

//  ��ʼ������
void workmanager::init_employee()
{
	string name;
	int id;
	int number;
	ifstream ifs;
	ifs.open(filename, ios::in);

	int value = 0;  //  ����������±�

	while (ifs>>number && ifs>>name && ifs>>id)
	{
		worker* valuework = NULL;   //  ����ָ��ָ���������   ��new

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
		//  ����ά����������
		this->m_emptyarrary[value] = valuework;     //  value ��������һ��ʼ�Ǵ�0ѭ����value++�����ͨ��whileһֱ����ѭ��ֱ���������
		value++;
	}
}


 // ���ְ�����ܣ�

void workmanager::addperson()
{
	cout << "��������Ҫ���ְ��������" << endl;

	int addnum = 0;  //  �����û�����������
	cin >> addnum;



	if (addnum > 0)  // ����0���
	{
		//  �����¿ռ�Ĵ�С   ����û�Ҫ������ӣ���ôԭ�����û�����ռ�õĿռ�Ͳ�����,
		//  ����Ҫ���¿���һ���ڴ�ռ����ԭ����������������ӵ�������

		// �¿ռ��С=ԭ����¼����+����������
		int newsize = this->m_emptynum + addnum;

		// �����¿ռ䣺
		worker** newspace = new worker * [newsize];     //  ָ������

		//  ��ԭ�����������ݿ������µĿռ��£�
		if (this->m_emptyarrary != NULL)    //  ԭ������������ָ����������ݵĻ��������е��������ݿ������¿ռ�
		{
			for (int i = 0; i < this->m_emptynum; i++)
			{
				newspace[i] = this->m_emptyarrary[i];
			}
		}

		//  ��������µ�����
		for (int i = 0; i < addnum; i++)  //  �˴���addnum    i < �û�����������
		{
			int id;
			string name;
			int personnumber;

			cout << "��������Ҫ��ӵĵ�" << i + 1 << "��ְ���ĸ��˱��" << endl;
			cin >> personnumber;
			cout << "��������Ҫ��ӵĵ�" << i + 1 << "��ְ��������" << endl;
			cin >> name;
			cout << "��������Ҫ��ӵĵ�" << i + 1 << "��ְ���Ĳ��ű��" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> id;
			//if (personnumber==this->m_emptyarrary[i]->m_personernumber)
			//{
			//	cout << "��Ա�����˱���Ѵ���" << endl;
			//	break;
			//}
			//else if (name== this->m_emptyarrary[i]->m_name)
			//{
			//	cout << "��Ա�������Ѵ���" << endl;
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
				cout << "��������Ч����ֵ" << endl;
				break;
			}
			newspace [this->m_emptynum + i] = workspace;  // �����е�����������������
		}
		
		//  �ͷ�ԭ�пռ䣺
		delete[]this->m_emptyarrary;

		//  �����¿ռ�ָ��
		this->m_emptyarrary = newspace;         //  ע�� ��  �Ⱥ���߱���Ϊ���޸ĵ���ֵ
		                                        //   ������Ҫ������
		//  �����µ�ְ��������
		this->m_emptynum = newsize;

		//  �����ж��ļ���Ϊ�յ�ʱ�򣬽�bool���͸���Ϊfalse            ���
		this->m_fileempty = false;

	/*	int ding=this->get_emptynum();
		cout << ding << endl;*/

		cout << "���" << addnum << "��ְ���ɹ�" << endl;

		this->save();
	}
	else
	{
		cout << "��ӵ�ְ�������������0�����������룡" << endl;
	}
	system("pause");
	system("cls");
}

//void workmanager::repeat()
//{
//	if (this.personnumber==this->m_emptyarrary[i]->m_personernumber)
//	{
//	cout << "��Ա�����˱���Ѵ���" << endl;
//	break;
//	}
//else if (name== this->m_emptyarrary[i]->m_name)
//	{
//	cout << "��Ա�������Ѵ���" << endl;
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
	//	cout << "û��ְ����Ϣ" << endl;
	//}
	if (this->m_emptynum==0)
	{
		cout << "û��ְ����Ϣ" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_emptynum; i++)
		{
			this->m_emptyarrary[i]->workinformation();
			//cout << "ְ����λְ���ǣ� ����ϰ��ɷ�������" << endl;
			//break;
		}

	}

	system("pause");
	system("cls");
}

int workmanager::isexist(int id)
{
	int exist = -1;  // һ��ʼ��Ϊ���ǲ����ڵģ���Ϊ-1
	for (int i = 0; i < this->m_emptynum; i++)
	{
		if (this->m_emptyarrary[i]->m_personernumber==id)  //  ��ְ��
		{
			exist = i;  //  ְ�����ڣ�����ְ���������е�λ��
			break;
		}
	}
	return exist;
}

void workmanager::deleteperson()  //  ɾ��Ա��
{
	if (this->m_fileempty==true)
	{
		cout << "�ļ�Ϊ�գ�����ɾ��" << endl;
	}
	else
	{
		int person = 0;
		cout << "��������Ҫɾ����Ա�����˱��" << endl;
		cin >> person;
		int ret = this->isexist(person);
		if (ret==-1)
		{
			cout << "��Ա��������" << endl;
		}
		else
		{
			for (int i = 0; i < this->m_emptynum-1; i++)
			{
				this->m_emptyarrary[i] = this->m_emptyarrary[i + 1];
			}
			this->m_emptynum--;
			this->save();
			cout << "ɾ���ɹ���" << endl; 
		}
	}
	system("pause");
	system("cls");
}

void workmanager::modifyperson()
{
	if (this->m_fileempty)
	{
		cout << "�ļ������ڣ��޷��޸�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸�ְ����ְ�����˱�����ڲ�ѯ" << endl;
		int number = 0;
		cin >> number;
		int retb = this->isexist(number);
		if (retb==-1)
		{
			cout << "��Ա��������" << endl;
		}
		else
		{
			this->showperson();
			cout << "��������Ҫ�޸ĵ�ѡ��" << endl;
			cout << "1.����" << endl;
			cout << "2.���˱��" << endl;
			cout << "3.���ű�� : ����Ϊ���ű����Ϣ��" << endl;
			cout<< "��.Ա��" << endl;
			cout << "��.����" << endl;
			cout << "��.�ϰ�" << endl;
			int id = 0;
			cin >> id;

			string newname;
			int newnumber;
			int newid;

			cout << "�������޸ĺ��������" << endl;
			cin >> newname;
			cout << "�������޸ĺ�ĸ��˱�ţ�" << endl;
			cin >> newid;
			cout << "��.Ա��" << endl;
			cout << "��.����" << endl;
			cout << "��.�ϰ�" << endl;
			cout << "�������޸ĺ�Ĳ��ű�ţ�" << endl;
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
				cout << "��������Ч����ֵ" << endl;
				break;
			}
			this->m_emptyarrary[retb] = workspace;
			this->save();
			cout << "�޸ĳɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workmanager::searchperson()
{
	cout << "��������Ҫ���ҵ�Ա�����˱��" << endl;
	int personid;
	cin >> personid;
	for (int i = 0; i < this->m_emptynum; i++)
	{
		if (this->m_fileempty==true)
		{
			cout << "�ļ�������" << endl;
			break;
		}
		else
		{
			if (this->isexist(personid)==-1)
			{
				cout << "��Ա��������" << endl;
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
	cout << "�Ƿ���Ա����Ž�������" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	int select;
	cin >> select;

	//  ����ð������

	//while (true)
	//{
	//	if (select == 1)
	//	{
	//		for (int i = 0; i < this->m_emptynum - 1; i++)
	//		{
	//			cout << "1.������������" << endl;
	//			cout << "2.���ս�������" << endl;
	//			int id;
	//			cin >> id;

	//			if (this->m_fileempty == true)
	//			{
	//				cout << "�ļ�������" << endl;
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


	// �����Խ�һ��������С�ı��������

	while (true)
	{
		if (select == 1)
		{
			cout << "1.������������" << endl;
			cout << "2.���ս�������" << endl;
			int id;
			cin >> id;

			for (int i = 0; i < m_emptynum; i++)
			{
				int minormax = i;  // ����һ��������������Сֵ���±꣬���ֵ���±�
				for (int j = i + 1; j < m_emptynum; j++)  // j���±���i��֮ǰ
				{
					if (id==1)
					{
						if (m_emptyarrary[minormax]->m_personernumber > m_emptyarrary[j]->m_personernumber) //  ����
						{
							// ����������С������j�󣬾�˵�������������������С��,j��i��minormax����С
							minormax = j;  // ��ʱ�Ͱ�j��Ϊ��С�������൱�ڽ���
						}
					}
					else
					{
						if (m_emptyarrary[minormax]->m_personernumber< m_emptyarrary[j]->m_personernumber)  // ����
						{
							// �����������෴
							minormax = j;
						}
					}

					// �ж�һ��ʼ�϶�����Сֵ�����ֵ�ǲ��� �����������Сֵ�����ֵ��������ǣ���������
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
	cout << "�Ƿ�Ҫ�������ְ�������ݣ�" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	int select;
	cin >> select;
	while (true)
	{
		if (select == 1)
		{
			ofstream ofs(filename, ios::trunc);   // ɾ���ļ��������´���  trunc
			ofs.close();                         //  ɾ���ڲ�ָ������ݣ�ͬʱ������ɾ���ļ��������

			if (this->m_fileempty == true)
			{
				cout << "�ļ�������" << endl;
				break;
			}
			else if (this->m_emptynum == 0)
			{
				cout << "�ļ��ڲ������Ѿ�Ϊ��" << endl;
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
			delete[] this->m_emptyarrary;            //  ��Ҫ����ά���ڲ���ָ�룬������Ҫ��һ��
			this->m_emptyarrary = NULL;
			this->m_fileempty = true;
		}
		else
		{
			break;
		}
	}
	cout << "��ճɹ���" << endl;
	system("pasue");
	system("cls");
}



void workmanager::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);    //   ������ķ�ʽд�ļ�
	   //  ��ÿ���˵�����д���ļ��У�
		for (int i = 0; i <this->m_emptynum ; i++)
		{
			ofs << this->m_emptyarrary[i]->m_name << endl;
			ofs	<< this->m_emptyarrary[i]->m_personernumber << endl;
			ofs	<< this->m_emptyarrary[i]->getworkname() << endl;
		}
		ofs.close();
}
 






workmanager::~workmanager()                    //  �ֶ��ͷŶ�������
{
	if (this->m_emptyarrary != NULL)
	{
		delete[]this->m_emptyarrary;
		this->m_emptyarrary = NULL;
	}
}