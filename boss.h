#pragma once
#include<iostream>
using namespace std;
#include"worker.h"



class boss:public worker
{
public:
	//boss();
	boss(string name,int id,int number);
	 void workinformation();

	 string getworkname();



	//int id;
	//int number;
	//string name;

};