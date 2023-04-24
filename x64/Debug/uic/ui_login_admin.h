/********************************************************************************
** Form generated from reading UI file 'login_admin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_ADMIN_H
#define UI_LOGIN_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginAdminClass
{
public:
    QWidget *centralwidget;
    QTextEdit *password;
    QPushButton *back;
    QPushButton *login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginAdminClass)
    {
        if (LoginAdminClass->objectName().isEmpty())
            LoginAdminClass->setObjectName("LoginAdminClass");
        LoginAdminClass->resize(960, 570);
        LoginAdminClass->setMinimumSize(QSize(960, 570));
        LoginAdminClass->setMaximumSize(QSize(960, 570));
        centralwidget = new QWidget(LoginAdminClass);
        centralwidget->setObjectName("centralwidget");
        password = new QTextEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(410, 170, 161, 31));
        back = new QPushButton(centralwidget);
        back->setObjectName("back");
        back->setGeometry(QRect(360, 240, 75, 24));
        login = new QPushButton(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(550, 240, 75, 24));
        LoginAdminClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginAdminClass);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 22));
        LoginAdminClass->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginAdminClass);
        statusbar->setObjectName("statusbar");
        LoginAdminClass->setStatusBar(statusbar);

        retranslateUi(LoginAdminClass);

        QMetaObject::connectSlotsByName(LoginAdminClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoginAdminClass)
    {
        LoginAdminClass->setWindowTitle(QCoreApplication::translate("LoginAdminClass", "MainWindow", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("LoginAdminClass", "Admin Password", nullptr));
        back->setText(QCoreApplication::translate("LoginAdminClass", "Back", nullptr));
        login->setText(QCoreApplication::translate("LoginAdminClass", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginAdminClass: public Ui_LoginAdminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_ADMIN_H
