#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_User_Screen.h"


class User_Screen : public QMainWindow
{
    Q_OBJECT

public:


    User_Screen(QWidget* parent = nullptr);
    ~User_Screen();

private slots:

    //user frame
    void display_clicked();
    void edit_clicked();
    void delete_clicked();
    void signout_clicked();

    //display frame
    void display_back_clicked();

    //delete frame
    void delete_yes_clicked();
    void delete_no_clicked();

    //edit frame
    void display_update_clicked();
    void display_cancel_clicked();

private:
    Ui::userScreenClass* ui;
};