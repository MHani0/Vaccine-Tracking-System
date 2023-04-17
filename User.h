#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
private:
	string fullName;
	int age;
	string nationalId;
	char gender;
	string governorate;
	string password;
	bool vaccinated;
	int dose;

public: 
	void displayData();
};

