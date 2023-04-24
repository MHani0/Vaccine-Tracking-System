#include "main.h"
#include "Initial.h"

int main(int argc, char *argv[])
{

    string filename = "users.txt";
    QApplication a(argc, argv);


	load_data(userHash, filename);



	  //print values in hash for debugging
	for (auto & pair : userHash) {
		qDebug() << "ID: " << pair.first << ", Password: " << pair.second.password << ", Name: " << pair.second.name << ", Age: " << pair.second.age << ", Gender: " << pair.second.gender << ", Governorate: " << pair.second.governorate << ", Dose: " << pair.second.dose << "\n";
	}


	 //decoy user for testing
	User user1("1111", "Bob", 40, "Male", "Alex", 0);
	userHash.insert({"3030120144",user1});


    Initial inital;
    inital.show();

	//Qt Application main event loop
    int exitCode = a.exec();


	save_data(userHash, filename);


	return exitCode;
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

	while (infile >> id >> password >> name >> age >> gender >> governorate >> dose) {
		User user(password, name, stoi(age), gender, governorate, stoi(dose));
		userHash[id] = user;
	}
}
