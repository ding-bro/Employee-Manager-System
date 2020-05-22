#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class employee :public worker
{
public:
	//employee();
	employee(string name, int id, int number);
	void workinformation();


	string getworkname();

	int number;
	string name;
	int id;

};