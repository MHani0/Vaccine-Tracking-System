#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Initial.h"

class Initial : public QMainWindow
{
    Q_OBJECT

public:
    Initial(QWidget *parent = nullptr);
    ~Initial();

private slots:
    void login_user_button_clicked();
    void login_admin_button_clicked();
    void signup_button_clicked();

private:
    Ui::InitialClass *ui;
};
