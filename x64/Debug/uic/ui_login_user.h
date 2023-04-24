/********************************************************************************
** Form generated from reading UI file 'login_user.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_USER_H
#define UI_LOGIN_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginUserClass
{
public:
    QWidget *centralwidget;
    QTextEdit *natID;
    QTextEdit *password;
    QPushButton *login;
    QPushButton *back;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginUserClass)
    {
        if (LoginUserClass->objectName().isEmpty())
            LoginUserClass->setObjectName("LoginUserClass");
        LoginUserClass->resize(960, 570);
        LoginUserClass->setMinimumSize(QSize(960, 570));
        LoginUserClass->setMaximumSize(QSize(960, 570));
        centralwidget = new QWidget(LoginUserClass);
        centralwidget->setObjectName("centralwidget");
        natID = new QTextEdit(centralwidget);
        natID->setObjectName("natID");
        natID->setGeometry(QRect(390, 160, 161, 31));
        password = new QTextEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(390, 220, 161, 31));
        login = new QPushButton(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(520, 290, 75, 24));
        back = new QPushButton(centralwidget);
        back->setObjectName("back");
        back->setGeometry(QRect(340, 290, 75, 24));
        LoginUserClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginUserClass);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 22));
        LoginUserClass->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginUserClass);
        statusbar->setObjectName("statusbar");
        LoginUserClass->setStatusBar(statusbar);

        retranslateUi(LoginUserClass);

        QMetaObject::connectSlotsByName(LoginUserClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoginUserClass)
    {
        LoginUserClass->setWindowTitle(QCoreApplication::translate("LoginUserClass", "MainWindow", nullptr));
        natID->setPlaceholderText(QCoreApplication::translate("LoginUserClass", "National ID", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("LoginUserClass", "Password", nullptr));
        login->setText(QCoreApplication::translate("LoginUserClass", "Login", nullptr));
        back->setText(QCoreApplication::translate("LoginUserClass", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginUserClass: public Ui_LoginUserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_USER_H
