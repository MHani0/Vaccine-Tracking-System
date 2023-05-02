#include "admin_screen.h"
#include "main.h"
#include "Initial.h"

Admin_Screen::Admin_Screen(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::adminScreenClass)
{
	ui->setupUi(this);

	//set initials visibilities
	ui->admin_screen->setVisible(true);
	ui->user_records->setVisible(false);
	ui->admin_display->setVisible(false);
	ui->admin_delete->setVisible(false);
	ui->view_vax->setVisible(false);
	ui->view_unvax->setVisible(false);

	//set basic statistics
	Basic_statistics();
	ui->male_stats->display(malesRatio);
	ui->female_stats->display(femalesRatio);
	ui->first_dose_stats->display(firstdoseRatio);
	ui->second_dose_stats->display(seconddoseRatio);
	ui->unvaccinated_stats->display(unvaccinatedRatio);

    //buttons in admin_screen
    connect(ui->view_records, &QPushButton::clicked, this, &Admin_Screen::records_clicked);
	connect(ui->view_vaccinated, &QPushButton::clicked, this, &Admin_Screen::vaccinated_clicked);
    connect(ui->view_unvaccinated, &QPushButton::clicked, this, &Admin_Screen::unvaccinated_clicked);
    connect(ui->admin_signout, &QPushButton::clicked, this, &Admin_Screen::signout_clicked);


	//buttons in user_records
	connect(ui->back_button, &QPushButton::clicked, this, &Admin_Screen::records_back_clicked);
	connect(ui->search_button, &QPushButton::clicked, this, &Admin_Screen::search_clicked);
	connect(ui->delete_record, &QPushButton::clicked, this, &Admin_Screen::delete_clicked);
	connect(ui->view_record, &QPushButton::clicked, this, &Admin_Screen::view_clicked);

	//table initialization & connection and setting up selection
	connect(ui->record_table, SIGNAL(cellClicked(int, int)), this, SLOT(table_record_clicked(int, int)));


	//buttons in admin delete
	connect(ui->yes_delete, &QPushButton::clicked, this, &Admin_Screen::yes_clicked);
	connect(ui->no_delete, &QPushButton::clicked, this, &Admin_Screen::no_clicked);


	//buttons in admin_display
	connect(ui->back_display, &QPushButton::clicked, this, &Admin_Screen::display_back_clicked);


	//buttons in view_vax
	connect(ui->vax_back_button, &QPushButton::clicked, this, &Admin_Screen::vaccinated_back_clicked);


	//buttons in view_unvax
	connect(ui->unvax_back_button, &QPushButton::clicked, this, &Admin_Screen::unvaccinated_back_clicked);
}

Admin_Screen::~Admin_Screen()
{
	delete ui;
}

void Admin_Screen::Basic_statistics() {

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

//admin functions
void Admin_Screen::records_clicked() {
	ui->admin_screen->setVisible(false);
	ui->user_records->setVisible(true);

	//loop filling table
	ui->record_table->setRowCount(0);
	int row = 0;
	for (auto& [ID, User] : userHash) {
		QTableWidgetItem* natID = new QTableWidgetItem(QString::fromStdString(ID));
		QTableWidgetItem* fullName = new QTableWidgetItem(QString::fromStdString(User.name));
		QTableWidgetItem* dose = new QTableWidgetItem(QString::number(User.dose));
		
		ui->record_table->insertRow(row);
		ui->record_table->setItem(row, 0, natID);
		ui->record_table->setItem(row, 1, fullName);
		ui->record_table->setItem(row, 2, dose);

		row++;
	}
}


void Admin_Screen::vaccinated_clicked() {
	ui->admin_screen->setVisible(false);
	ui->view_vax->setVisible(true);

	//loop filling table
	ui->vax_table->setRowCount(0);
	for (int row = 0; row < vaccinated.length(); row++) {

		Node* tmp = vaccinated.nodeAt(row);
		
		if (tmp != nullptr) {
			QTableWidgetItem* natID = new QTableWidgetItem(QString::fromStdString(tmp->natID));
			QTableWidgetItem* fullName = new QTableWidgetItem(QString::fromStdString(userHash[tmp->natID].name));
			QTableWidgetItem* dose = new QTableWidgetItem(QString::number(userHash[tmp->natID].dose));
			
			ui->vax_table->insertRow(row);
			ui->vax_table->setItem(row, 0, natID);
			ui->vax_table->setItem(row, 1, fullName);
			ui->vax_table->setItem(row, 2, dose);
		}
		else {
			break;
		}
	}
}


void Admin_Screen::unvaccinated_clicked() {
	ui->admin_screen->setVisible(false);
	ui->view_unvax->setVisible(true);

	//loop filling table
	ui->unvax_table->setRowCount(0);
	int row = 0;
	string key;
	queue<string>copy_queue = not_vaccinated; //copy queue to not pop original queue

	while(!copy_queue.empty()) {

		key = copy_queue.front();
		QTableWidgetItem* natID = new QTableWidgetItem(QString::fromStdString(key));
		QTableWidgetItem* fullName = new QTableWidgetItem(QString::fromStdString(userHash[key].name));

		ui->unvax_table->insertRow(row);
		ui->unvax_table->setItem(row, 0, natID);
		ui->unvax_table->setItem(row, 1, fullName);

		copy_queue.pop();
	}
}
void Admin_Screen::signout_clicked() {

	Initial* initial = new Initial();
	initial->show();
	this->close();
}


//records functions
void Admin_Screen::search_clicked() {

	QString search_text = ui->input_id->text();
	int dose_value = ui->dose_filter->currentIndex();

	string searchID = search_text.toStdString();
	ui->record_table->clearContents();
	ui->record_table->setRowCount(0);

	if (userHash.count(searchID)) {

		int searchDose = userHash[searchID].dose;
		

		if (searchDose == dose_value || dose_value == 3) {
			QTableWidgetItem* natID = new QTableWidgetItem(search_text);
			QTableWidgetItem* fullName = new QTableWidgetItem(QString::fromStdString(userHash[searchID].name));
			QTableWidgetItem* dose = new QTableWidgetItem(QString::number(userHash[searchID].dose));

			ui->record_table->insertRow(0);
			ui->record_table->setItem(0, 0, natID);
			ui->record_table->setItem(0, 1, fullName);
			ui->record_table->setItem(0, 2, dose);
		}
		else {
			qDebug() << "Search not found (Dose Mistmatch)";
		}
	}
	else if (searchID == "") {

		if (dose_value == 3) {
			qDebug() << "Display All";
			records_clicked();
			return;
		}
		
		int row = 0;

		for (auto& [ID, User] : userHash) {

			if (dose_value == User.dose) {

				QTableWidgetItem* natID = new QTableWidgetItem(QString::fromStdString(ID));
				QTableWidgetItem* fullName = new QTableWidgetItem(QString::fromStdString(User.name));
				QTableWidgetItem* dose = new QTableWidgetItem(QString::number(User.dose));

				ui->record_table->insertRow(row);
				ui->record_table->setItem(row, 0, natID);
				ui->record_table->setItem(row, 1, fullName);
				ui->record_table->setItem(row, 2, dose);

				row++;
			}	
		}
	}
	else {
		qDebug() << "Search Not Found";
	}
}
	
void Admin_Screen::table_record_clicked(int row, int col) {

	if (ui->record_table->rowCount() == 0) {
		ui->record_table->clearSelection(); // Disable selection
		return;
	}
		
	row = ui->record_table->currentRow();

	chosenUserID = ui->record_table->item(row, 0)->text().toStdString();
	

}
void Admin_Screen::view_clicked() {
	
	if (chosenUserID != "") {

		ui->user_records->setVisible(false);
		ui->admin_display->setVisible(true);

		QString name = QString::fromStdString(userHash[chosenUserID].name);
		QString age = QString::number(userHash[chosenUserID].age);
		QString governorate = QString::fromStdString(userHash[chosenUserID].governorate);
		QString gender = QString::fromStdString(userHash[chosenUserID].gender);


		QString vaccine;
		if (userHash[chosenUserID].dose == 0)
			vaccine = "Unvaccinated";
		else if (userHash[chosenUserID].dose == 1)
			vaccine = "1 Dose";
		else
			vaccine = "2 Doses";

		ui->display_id->setText(QString::fromStdString(chosenUserID));
		ui->display_name->setText(name);
		ui->display_age->setText(age);
		ui->display_gov->setText(governorate);
		ui->display_gender->setText(gender);
		ui->display_vaccine->setText(vaccine);
		chosenUserID = "";
	}
	else {
		qDebug() << "Choose User";
	}

}
void Admin_Screen::delete_clicked() {
	if (chosenUserID != "") {
		ui->user_records->setVisible(false);
		ui->admin_delete->setVisible(true);
	}
	else {
		qDebug() << "Choose User";
	}

}
void Admin_Screen::records_back_clicked() {
	chosenUserID = "";
	ui->user_records->setVisible(false);
	ui->admin_screen->setVisible(true);
}


//admn_delete functions
void Admin_Screen::yes_clicked() {

	deleteUser(chosenUserID);
	chosenUserID = "";
	qDebug() << "User Deleted";

	ui->admin_delete->setVisible(false);
	ui->user_records->setVisible(true);
}
void Admin_Screen::no_clicked() {
	chosenUserID = "";
	ui->admin_delete->setVisible(false);
	ui->user_records->setVisible(true);
}

//admin_display functions
void Admin_Screen::display_back_clicked() {
	ui->admin_display->setVisible(false);
	ui->user_records->setVisible(true);
}

//view_vax functions
void Admin_Screen::vaccinated_back_clicked() {
	ui->view_vax->setVisible(false);
	ui->admin_screen->setVisible(true);
}

//view_unvax functions
void Admin_Screen::unvaccinated_back_clicked() {
	ui->view_unvax->setVisible(false);
	ui->admin_screen->setVisible(true);
}