#pragma once

#include <QMainWindow>
#include "ui_admin_screen.h"

class Admin_Screen : public QMainWindow
{
	Q_OBJECT

public:
	Admin_Screen(QWidget *parent = nullptr);
	~Admin_Screen();

private:
	//basic stat
	double malesRatio, femalesRatio, unvaccinatedRatio,
		firstdoseRatio, seconddoseRatio;

	void basic_statistics();

	//adv stat
	int users_count, users_unvax, users_1, users_2;
	int males_count, males_unvax, males_1, males_2;
	int females_count, females_unvax, females_1, females_2;

	void advanced_statistics();

private slots:

	//admin_screen frame
	void records_clicked();
	void vaccinated_clicked();
	void unvaccinated_clicked();
	void advanced_clicked();
	void signout_clicked();

	//user_records frame
	void search_clicked();
	void view_clicked();
	void delete_clicked();
	void records_back_clicked();
	void table_record_clicked(int,int);
	void selection_changed();

	//admin_delete frame
	void yes_clicked();
	void no_clicked();

	//admin_display frame
	void display_back_clicked();

	//view_vax frame
	void vaccinated_back_clicked();

	//view_unvax frame
	void unvaccinated_back_clicked();

	//advanced_frame
	void advanced_back_clicked();
	void advanced_filter_changed(); //if gov from combobox or age from spinbox changed

private:
	Ui::adminScreenClass* ui;
};
