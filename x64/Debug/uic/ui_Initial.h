/********************************************************************************
** Form generated from reading UI file 'Initial.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIAL_H
#define UI_INITIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitialClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *login_user;
    QPushButton *signup;
    QPushButton *login_admin;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InitialClass)
    {
        if (InitialClass->objectName().isEmpty())
            InitialClass->setObjectName("InitialClass");
        InitialClass->resize(960, 570);
        InitialClass->setMinimumSize(QSize(960, 570));
        InitialClass->setMaximumSize(QSize(960, 570));
        centralWidget = new QWidget(InitialClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setAutoFillBackground(false);
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 70, 311, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        login_user = new QPushButton(centralWidget);
        login_user->setObjectName("login_user");
        login_user->setGeometry(QRect(420, 180, 111, 41));
        QFont font1;
        font1.setPointSize(14);
        login_user->setFont(font1);
        signup = new QPushButton(centralWidget);
        signup->setObjectName("signup");
        signup->setGeometry(QRect(420, 250, 111, 41));
        signup->setFont(font1);
        login_admin = new QPushButton(centralWidget);
        login_admin->setObjectName("login_admin");
        login_admin->setGeometry(QRect(420, 320, 111, 41));
        QFont font2;
        font2.setPointSize(10);
        login_admin->setFont(font2);
        InitialClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InitialClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 960, 22));
        InitialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InitialClass);
        mainToolBar->setObjectName("mainToolBar");
        InitialClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InitialClass);
        statusBar->setObjectName("statusBar");
        InitialClass->setStatusBar(statusBar);

        retranslateUi(InitialClass);

        QMetaObject::connectSlotsByName(InitialClass);
    } // setupUi

    void retranslateUi(QMainWindow *InitialClass)
    {
        InitialClass->setWindowTitle(QCoreApplication::translate("InitialClass", "Initial", nullptr));
        label->setText(QCoreApplication::translate("InitialClass", "Vaccine Tracking System", nullptr));
        login_user->setText(QCoreApplication::translate("InitialClass", "Login", nullptr));
        signup->setText(QCoreApplication::translate("InitialClass", "Sign Up", nullptr));
        login_admin->setText(QCoreApplication::translate("InitialClass", "Login As Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitialClass: public Ui_InitialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIAL_H
