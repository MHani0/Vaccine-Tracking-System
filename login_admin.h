#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_login_admin.h"


class Login_Admin : public QMainWindow
{
    Q_OBJECT

public:
    Login_Admin(QWidget* parent = nullptr);
    ~Login_Admin();

private slots:
    void login_clicked();
    void back_clicked();

private:
    Ui::LoginAdminClass* ui;
};