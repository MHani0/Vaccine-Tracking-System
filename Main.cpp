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
void handlingDoses()
{
	for (const auto& pair : userHash) {
		if(pair.second.dose == 0)
			not_vaccinated.push(pair.first);
		else
			vaccinated.insert(pair.first, userHash);
	}
}
void Basic_statistics()
{
	int malesRatio, femalesRatio, unvaccinatedRatio, firstdoseRatio, seconddoseRatio;
	for (const auto& pair : userHash) {
		if (pair.second.gender == "male" || pair.second.gender == "Male")
			malesRatio++;
		else if (pair.second.gender == "female" || pair.second.gender == "Female")
			femalesRatio++;
		if (pair.second.dose == 0)
			unvaccinatedRatio++;
		else if (pair.second.dose == 1)
			firstdoseRatio++;
		else if (pair.second.dose == 2)
			seconddoseRatio++;
	}
	malesRatio /= userHash.size();
	femalesRatio /= userHash.size();
	unvaccinatedRatio /= userHash.size();
	firstdoseRatio /= userHash.size();
	seconddoseRatio /= userHash.size();
}
void delUser(string userID)
{
	queue <string> copyqueue;
	while (!not_vaccinated.empty())
	{
		if (userID != not_vaccinated.front())
			copyqueue.front() = not_vaccinated.front();
		not_vaccinated.pop();

	}
	while (!copyqueue.empty())
	{
		not_vaccinated.front() = copyqueue.front();
		copyqueue.pop();
	}
	vaccinated.deleteAt(userID);
	userHash.erase(userID);
}