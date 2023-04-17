#include<iostream>
#include "User.h"

using namespace std;

void main(void) {
	int choice;
	cout << "\n\t\t\t\t*Welcome to The Egyptian Vaccine Tracking System*\n";
	cout << "\nPlease choose from the following options:\n";
	cout << "\n1. User Login\n\n2. Administrator Login\n\n3. Signup";
	cout << "\n\n> ";
	cin >> choice;

	switch (choice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		cout << "\n\nWrong Input..!\n\n";

	}
}