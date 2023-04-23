#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_signup.h"


class Signup : public QMainWindow
{
    Q_OBJECT

public:
    Signup(QWidget* parent = nullptr);
    ~Signup();

private slots:
    void signup_clicked();
    void back_clicked();

private:
    Ui::SignupClass* ui;
};