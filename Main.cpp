#include "Main.h"

using namespace std;

void main(void) {

	unordered_map < string, User> userHash;
	string filename = "users.txt";


	load_data(userHash, filename);


	
	/* print values in hash for debugging
	//print hash for any debugging
	for (auto & pair : userHash) {
		cout << "ID: " << pair.first << ", Password: " << pair.second.password << ", Name: " << pair.second.name << ", Age: " << pair.second.age << ", Gender: " << pair.second.gender << ", Governorate: " << pair.second.governorate << ", Dose: " << pair.second.dose << std::endl;
	}
	*/

	/* //decoy user for testing
	User user2("1111", "Bob", 40, "Male", "Alex", 0);
	userHash["3030260100659"] = user2;
	*/

	int choice;
	cout << "\n\t\t\t\t*Welcome to The Egyptian Vaccine Tracking System*\n";
	cout << "\nPlease choose from the following options:\n";
	cout << "\n1. User Login\n\n2. Administrator Login\n\n3. Sign up";
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



	
	save_data(userHash, filename);

}






void save_data(unordered_map<string, User>& userHash, string filename) {

	ofstream outfile(filename);

	for (const auto& pair : userHash) {
		outfile << pair.first << "\n";
		outfile << pair.second.password << "\n";
		outfile << pair.second.name << "\n";
		outfile << pair.second.age << "\n";
		outfile << pair.second.gender << "\n";
		outfile << pair.second.governorate << "\n";
		outfile << pair.second.dose << "\n";

	}
}

void load_data(unordered_map<string, User>& userHash, string filename) {

	ifstream infile(filename);
	string line;
	string id, password, name, age, gender, governorate, dose;

	while (infile >> id >> password >> name >> age >> gender  >> governorate >> dose) {
		User user(password, name, stoi(age), gender, governorate, stoi(dose));
		userHash[id] = user;
	}
}