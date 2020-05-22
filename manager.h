#pragma once
#include <iostream>
using namespace std;
#include"employee.h"
#include"boss.h"
#include"worker.h"


class manager:public worker
{
public:

	void workinformation();

	string getworkname();

	int id;
	int number;
	string name;

	manager(string name, int id, int number);
};