#include "main.h"
#include "Initial.h"

int main(int argc, char *argv[])
{

    string filename = "users.txt";
    QApplication a(argc, argv);


	load_data(userHash, filename);

	loggedInUserID = "";

	handlingDoses();

	//print values in hash for debugging
	for (auto & key : hashKeysOrdered) {
		qDebug() << "ID: " << key << ", Password: " << userHash[key].password << ", Name: " << userHash[key].name << ", Age: " << userHash[key].age << ", Gender: " << userHash[key].gender << ", Governorate: " << userHash[key].governorate << ", Dose: " << userHash[key].dose << "\n";
	}




    Initial inital;
    inital.show();

	//Qt Application main event loop
    int exitCode = a.exec();



	//PRINT VALUES AFTER PROGRAM ENDS FOR DEBUGGING
	//display linked list for debugging
	vaccinated.display();

	//display queue for debugging
	queue<string> copy_queue = not_vaccinated; // Make a copy of the queue

	qDebug() << "Contents of the queue: ";
	while (!copy_queue.empty()) {
		qDebug() << copy_queue.front() << " ";
		copy_queue.pop();
	}
	qDebug() << "\n";

	//print values in hash for debugging
	for (auto& key : hashKeysOrdered) {
		qDebug() << "ID: " << key << ", Password: " << userHash[key].password << ", Name: " << userHash[key].name << ", Age: " << userHash[key].age << ", Gender: " << userHash[key].gender << ", Governorate: " << userHash[key].governorate << ", Dose: " << userHash[key].dose << "\n";
	}


	save_data(userHash, filename);



	return exitCode;
}





void save_data(unordered_map<string, User>& userHash, string filename) {

	ofstream outfile(filename);

	for (const auto& key : hashKeysOrdered) {
		outfile << key << "\n";
		outfile << userHash[key].password << "\n";
		outfile << userHash[key].name << "\n";
		outfile << userHash[key].age << "\n";
		outfile << userHash[key].gender << "\n";
		outfile << userHash[key].governorate << "\n";
		outfile << userHash[key].dose << "\n";

	}
}

void load_data(unordered_map<string, User>& userHash, string filename) {

	ifstream infile(filename);
	string line;
	string id, password, name, ageStr, gender, governorate, doseStr;

	while (getline(infile, line)) {

		id = trim(line);

		getline(infile, line);
		password = trim(line);

		getline(infile, line);
		name = trim(line);

		getline(infile, line);
		ageStr = trim(line);
		int age = stoi(ageStr);

		getline(infile, line);
		gender = trim(line);

		getline(infile, line);
		governorate = trim(line);

		getline(infile, line);
		doseStr = trim(line);
		int dose = stoi(doseStr);

		//create user and store him into hash
		User user(password, name, age, gender, governorate, dose);
		hashKeysOrdered.push_back(id);
		userHash[id] = user;
	}
}

//gets put into queue waiting list if unvaccinated and in a sorted linked list if vaccinated
void handlingDoses()
{
	for (const auto& key : hashKeysOrdered) {
		if(userHash[key].dose == 0)
			not_vaccinated.push(key);
		else
			vaccinated.insert(key, userHash);
	}
}


void deleteUser(string natID)
{

	if (userHash.count(natID) == 0) return;

	if (userHash[natID].dose == 0) {
		queue <string> copyqueue;
		while (!not_vaccinated.empty())
		{
			if (natID != not_vaccinated.front())
				copyqueue.push(not_vaccinated.front());
			not_vaccinated.pop();

		}
		while (!copyqueue.empty())
		{
			not_vaccinated.push(copyqueue.front());
			copyqueue.pop();
		}
	}

	else {
		vaccinated.deleteAt(natID);
	}


	hashKeysOrdered.erase(remove(hashKeysOrdered.begin(), hashKeysOrdered.end(), natID), hashKeysOrdered.end());
	userHash.erase(natID);
}



bool isDigitString(const string& str) {

	if (str.length() == 0) return false;

	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}


string trim(const std::string& s) {
	auto start = s.begin();
	while (start != s.end() && isspace(*start)) {
		++start;
	}
	auto end = s.end();
	while (end != start && isspace(*(end - 1))) {
		--end;
	}
	return string(start, end);
}
