#include "User.h" 

using namespace std; 


User::User(string password, string name, int age, string gender, string governorate, int dose) {
	this->password = password;
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->governorate = governorate;
	this->dose = dose;
}

User::User() {
	this->password = "";
	this->name = "";
	this->age = 0;
	this->gender = "";
	this->governorate = "";
	this->dose = 0;
}

User::~User() {

}

void User::displayData() { 
	cout << "Full name: " << name << "\nAge: " << age << "\nGender: " << gender << "\ngovernorate" << "\nVaccine dose: " << dose; 
}