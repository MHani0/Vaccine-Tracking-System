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

	void Basic_statistics();

private slots:

	//admin_screen frame
	void records_clicked();
	void vaccinated_clicked();
	void unvaccinated_clicked();
	void signout_clicked();

	//user_records frame
	void search_clicked();
	void view_clicked();
	void delete_clicked();
	void records_back_clicked();
	void table_record_clicked(int,int);

	//admin_delete frame
	void yes_clicked();
	void no_clicked();

	//admin_display frame
	void display_back_clicked();

	//view_vax frame
	void vaccinated_back_clicked();

	//view_unvax frame
	void unvaccinated_back_clicked();

private:
	Ui::adminScreenClass* ui;
};