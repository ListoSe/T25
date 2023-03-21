#pragma once
#include"violation.h"
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
class GAI
{
protected:
	map<string, vector<Violation>> db;
public:
	void show();
	void addViol(string s, Violation& v);
	void showAt(string i);

};

