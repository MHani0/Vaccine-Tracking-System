#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_login_user.h"


class Login_User : public QMainWindow
{
    Q_OBJECT

public:
    Login_User(QWidget* parent = nullptr);
    ~Login_User();

private slots:
    void login_clicked();
    void back_clicked();

private:
    Ui::LoginUserClass *ui;
};