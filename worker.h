#pragma once
#include<iostream>
using namespace std;

class worker
{
public:
	virtual void workinformation() = 0;

	virtual string getworkname() = 0;

	int	m_personernumber;
	string m_name;
	int m_departmentid;

};