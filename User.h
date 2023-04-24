#pragma once

#include <iostream>

using namespace std;

class User
{


public:

	string password;
	string name;
	int age;
	string gender;
	string governorate;
	int dose;

public:
	User(string, string, int, string, string, int);
	User();
	~User();
	void displayData();
};

