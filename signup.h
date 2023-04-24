#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_signup.h"


class Signup : public QMainWindow
{
    Q_OBJECT

public:

    //default to false, only set true in validating functions
    bool id_valid;
    bool name_valid;
    bool password_valid;
    bool age_valid;
    bool governorate_valid;
    bool gender_valid;
    bool vaccine_valid;


    Signup(QWidget* parent = nullptr);
    ~Signup();

private slots:
    void signup_clicked();
    void back_clicked();

    //validation events
    void name_validate();
    void id_validate();
    void age_validate();
    void pass_validate();
    void gov_validate();


private:
    Ui::SignupClass* ui;
};