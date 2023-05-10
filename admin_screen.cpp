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
	ui->advanced_frame->setVisible(false);

	//set basic statistics
	basic_statistics();

    //buttons in admin_screen
    connect(ui->view_records, &QPushButton::clicked, this, &Admin_Screen::records_clicked);
	connect(ui->view_vaccinated, &QPushButton::clicked, this, &Admin_Screen::vaccinated_clicked);
    connect(ui->view_unvaccinated, &QPushButton::clicked, this, &Admin_Screen::unvaccinated_clicked);
    connect(ui->view_advanced, &QPushButton::clicked, this, &Admin_Screen::advanced_clicked);
    connect(ui->admin_signout, &QPushButton::clicked, this, &Admin_Screen::signout_clicked);


	//buttons in user_records
	connect(ui->back_button, &QPushButton::clicked, this, &Admin_Screen::records_back_clicked);
	connect(ui->search_button, &QPushButton::clicked, this, &Admin_Screen::search_clicked);
	connect(ui->delete_record, &QPushButton::clicked, this, &Admin_Screen::delete_clicked);
	connect(ui->view_record, &QPushButton::clicked, this, &Admin_Screen::view_clicked);

	//table initialization & connection and setting up selection
	connect(ui->record_table, &QTableWidget::cellClicked, this, &Admin_Screen::table_record_clicked);
	connect(ui->record_table, &QTableWidget::itemSelectionChanged, this, &Admin_Screen::selection_changed);
	ui->record_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	//buttons in admin delete
	connect(ui->yes_delete, &QPushButton::clicked, this, &Admin_Screen::yes_clicked);
	connect(ui->no_delete, &QPushButton::clicked, this, &Admin_Screen::no_clicked);


	//buttons in admin_display
	connect(ui->back_display, &QPushButton::clicked, this, &Admin_Screen::display_back_clicked);


	//buttons in view_vax
	connect(ui->vax_back_button, &QPushButton::clicked, this, &Admin_Screen::vaccinated_back_clicked);
	ui->vax_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//buttons in view_unvax
	connect(ui->unvax_back_button, &QPushButton::clicked, this, &Admin_Screen::unvaccinated_back_clicked);
	ui->unvax_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//buttons and events in advanced_frame
	connect(ui->back_button_adv, &QPushButton::clicked, this, &Admin_Screen::advanced_back_clicked);
	connect(ui->governorate_adv, SIGNAL(currentIndexChanged(int)), this, SLOT(advanced_filter_changed()));
	connect(ui->low_range, QOverload<int>::of(&QSpinBox::valueChanged), this, &Admin_Screen::advanced_filter_changed);
	connect(ui->high_range, QOverload<int>::of(&QSpinBox::valueChanged), this, &Admin_Screen::advanced_filter_changed);
}

Admin_Screen::~Admin_Screen()
{
	delete ui;
}

void Admin_Screen::basic_statistics() {

	malesRatio = femalesRatio = unvaccinatedRatio = firstdoseRatio = seconddoseRatio = 0.0;

	if (userHash.empty()) {
		ui->male_stats->display(0.0);
		ui->female_stats->display(0.0);
		ui->first_dose_stats->display(0.0);
		ui->second_dose_stats->display(0.0);
		ui->unvaccinated_stats->display(0.0);
		return;
	}

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
	malesRatio = (malesRatio*100) / userHash.size();
	femalesRatio = (femalesRatio * 100) / userHash.size();
	unvaccinatedRatio = (unvaccinatedRatio * 100) / userHash.size();
	firstdoseRatio = (firstdoseRatio * 100) / userHash.size();
	seconddoseRatio = (seconddoseRatio * 100) / userHash.size();

	qDebug() << malesRatio << femalesRatio << firstdoseRatio << seconddoseRatio << unvaccinatedRatio;
	
	ui->male_stats->display(malesRatio);
	ui->female_stats->display(femalesRatio);
	ui->first_dose_stats->display(firstdoseRatio);
	ui->second_dose_stats->display(seconddoseRatio);
	ui->unvaccinated_stats->display(unvaccinatedRatio);
}

//admin functions
void Admin_Screen::records_clicked() {
	ui->admin_screen->setVisible(false);
	ui->user_records->setVisible(true);

	ui->view_record->setVisible(false);
	ui->delete_record->setVisible(false);

	ui->input_id->setText(""); //resetting search bar
	ui->dose_filter->setCurrentIndex(0); //resseting dose

	//removing index from table
	ui->record_table->verticalHeader()->setVisible(false);

	//loop filling table
	ui->record_table->setRowCount(0);
	int row = 0;
	for (auto& key : hashKeysOrdered) {
		QTableWidgetItem* natID = new QTableWidgetItem(QString::fromStdString(key));
		QTableWidgetItem* fullName = new QTableWidgetItem(QString::fromStdString(userHash[key].name));
		QTableWidgetItem* dose = new QTableWidgetItem(QString::number(userHash[key].dose));
		
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

		row++;
	}
}


void Admin_Screen::advanced_clicked() {

	ui->admin_screen->setVisible(false);
	ui->advanced_frame->setVisible(true);

	//set initials
	ui->governorate_adv->setCurrentIndex(0);
	ui->low_range->setValue(0);
	ui->high_range->setValue(120);


	//we do not have to call advanced statistics here, when the initials are set, the valuechanged event will be triggered autoamtically

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
		

		if (searchDose + 1 == dose_value || dose_value == 0) {
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

		if (dose_value == 0) {
			qDebug() << "Display All";
			records_clicked();
			return;
		}
		
		int row = 0;

		for (auto& key : hashKeysOrdered) {

			if (dose_value == userHash[key].dose + 1) {

				QTableWidgetItem* natID = new QTableWidgetItem(QString::fromStdString(key));
				QTableWidgetItem* fullName = new QTableWidgetItem(QString::fromStdString(userHash[key].name));
				QTableWidgetItem* dose = new QTableWidgetItem(QString::number(userHash[key].dose));

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

	ui->view_record->setVisible(true);
	ui->delete_record->setVisible(true);

	row = ui->record_table->currentRow();

	//when a row is clicked, select all other columns within this row
	for (int col = 0; col < 3; col++) {
		ui->record_table->item(row, col)->setSelected(true);
	}

	chosenUserID = ui->record_table->item(row, 0)->text().toStdString();
	

}

void Admin_Screen::selection_changed(){
	//if no cell selected, disable buttons
	if (ui->record_table->selectedItems().isEmpty()) {
		ui->view_record->setVisible(false);
		ui->delete_record->setVisible(false);
	}
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

	basic_statistics();

	ui->user_records->setVisible(false);
	ui->admin_screen->setVisible(true);
}


//admn_delete functions
void Admin_Screen::yes_clicked() {

	deleteUser(chosenUserID);
	chosenUserID = "";
	qDebug() << "User Deleted";
	
	records_clicked();

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


//advanced_frame functions
void Admin_Screen::advanced_back_clicked() {
	ui->advanced_frame->setVisible(false);
	ui->admin_screen->setVisible(true);
}

void Admin_Screen::advanced_filter_changed() {

	//make sure the high bounds of age isn't less than low bounds and vice versa
	ui->low_range->setMaximum(ui->high_range->value());
	ui->high_range->setMinimum(ui->low_range->value());

	advanced_statistics();

	
	

}


void Admin_Screen::advanced_statistics() {
	//init advanced varaibles with 0
	users_count = users_unvax = users_1 = users_2 =
	males_count = males_unvax = males_1 = males_2 =
	females_count = females_unvax = females_1 = females_2 = 0;

	for (const auto& pair : userHash) {
		
		//apply governorate and age filters
		//match governorate unless it's all, then match low range and high range of the age filter
		if ((ui->governorate_adv->currentText().toStdString() == pair.second.governorate || ui->governorate_adv->currentText().toStdString() == "All") &&
			ui->low_range->value() <= pair.second.age && ui->high_range->value() >= pair.second.age) {

			//all users
			users_count++;
			if (pair.second.dose == 0) users_unvax++;
			else if (pair.second.dose == 1) users_1++;
			else users_2++;

			//males
			if (pair.second.gender == "male" || pair.second.gender == "Male") {
				males_count++;
				if (pair.second.dose == 0) males_unvax++;
				else if (pair.second.dose == 1) males_1++;
				else males_2++;
			}

			//females
			if (pair.second.gender == "female" || pair.second.gender == "Female") {
				females_count++;
				if (pair.second.dose == 0) females_unvax++;
				else if (pair.second.dose == 1) females_1++;
				else females_2++;
			}
		}
	}

	//set the labels
	//all
	ui->users_count->setText(QString::number(users_count));
	ui->users_unvax->setText(QString::number(users_unvax));
	ui->users_1->setText(QString::number(users_1));
	ui->users_2->setText(QString::number(users_2));

	//males
	ui->males_count->setText(QString::number(males_count));
	ui->males_unvax->setText(QString::number(males_unvax));
	ui->males_1->setText(QString::number(males_1));
	ui->males_2->setText(QString::number(males_2));

	//females
	ui->females_count->setText(QString::number(females_count));
	ui->females_unvax->setText(QString::number(females_unvax));
	ui->females_1->setText(QString::number(females_1));
	ui->females_2->setText(QString::number(females_2));


	qDebug() << users_count << users_unvax << users_1 << users_2 <<
		males_count << males_unvax << males_1 << males_2 <<
		females_count << females_unvax << females_1 << females_2;

}
