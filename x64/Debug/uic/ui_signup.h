/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignupClass
{
public:
    QWidget *centralwidget;
    QTextEdit *name;
    QPushButton *back;
    QPushButton *signup;
    QTextEdit *natID;
    QTextEdit *password;
    QTextEdit *governorate;
    QRadioButton *male;
    QRadioButton *female;
    QRadioButton *unvaccinated;
    QRadioButton *vaccinated_1;
    QRadioButton *vaccinated_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *genderButtonGroup;
    QButtonGroup *vaccineButtonGroup;

    void setupUi(QMainWindow *SignupClass)
    {
        if (SignupClass->objectName().isEmpty())
            SignupClass->setObjectName("SignupClass");
        SignupClass->resize(960, 570);
        SignupClass->setMinimumSize(QSize(960, 570));
        SignupClass->setMaximumSize(QSize(960, 570));
        centralwidget = new QWidget(SignupClass);
        centralwidget->setObjectName("centralwidget");
        name = new QTextEdit(centralwidget);
        name->setObjectName("name");
        name->setGeometry(QRect(410, 65, 161, 31));
        back = new QPushButton(centralwidget);
        back->setObjectName("back");
        back->setGeometry(QRect(320, 410, 75, 24));
        signup = new QPushButton(centralwidget);
        signup->setObjectName("signup");
        signup->setGeometry(QRect(560, 410, 75, 24));
        natID = new QTextEdit(centralwidget);
        natID->setObjectName("natID");
        natID->setGeometry(QRect(410, 115, 161, 31));
        password = new QTextEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(410, 165, 161, 31));
        governorate = new QTextEdit(centralwidget);
        governorate->setObjectName("governorate");
        governorate->setGeometry(QRect(410, 265, 161, 31));
        male = new QRadioButton(centralwidget);
        genderButtonGroup = new QButtonGroup(SignupClass);
        genderButtonGroup->setObjectName("genderButtonGroup");
        genderButtonGroup->addButton(male);
        male->setObjectName("male");
        male->setGeometry(QRect(420, 223, 89, 20));
        female = new QRadioButton(centralwidget);
        genderButtonGroup->addButton(female);
        female->setObjectName("female");
        female->setGeometry(QRect(510, 223, 89, 20));
        unvaccinated = new QRadioButton(centralwidget);
        vaccineButtonGroup = new QButtonGroup(SignupClass);
        vaccineButtonGroup->setObjectName("vaccineButtonGroup");
        vaccineButtonGroup->addButton(unvaccinated);
        unvaccinated->setObjectName("unvaccinated");
        unvaccinated->setGeometry(QRect(440, 323, 90, 20));
        vaccinated_1 = new QRadioButton(centralwidget);
        vaccineButtonGroup->addButton(vaccinated_1);
        vaccinated_1->setObjectName("vaccinated_1");
        vaccinated_1->setGeometry(QRect(440, 343, 90, 20));
        vaccinated_2 = new QRadioButton(centralwidget);
        vaccineButtonGroup->addButton(vaccinated_2);
        vaccinated_2->setObjectName("vaccinated_2");
        vaccinated_2->setGeometry(QRect(440, 363, 90, 20));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 70, 71, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(330, 120, 71, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(330, 170, 71, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(330, 220, 71, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(330, 270, 71, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(330, 320, 80, 20));
        SignupClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignupClass);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 22));
        SignupClass->setMenuBar(menubar);
        statusbar = new QStatusBar(SignupClass);
        statusbar->setObjectName("statusbar");
        SignupClass->setStatusBar(statusbar);

        retranslateUi(SignupClass);

        QMetaObject::connectSlotsByName(SignupClass);
    } // setupUi

    void retranslateUi(QMainWindow *SignupClass)
    {
        SignupClass->setWindowTitle(QCoreApplication::translate("SignupClass", "MainWindow", nullptr));
        name->setPlaceholderText(QString());
        back->setText(QCoreApplication::translate("SignupClass", "Back", nullptr));
        signup->setText(QCoreApplication::translate("SignupClass", "Sign Up", nullptr));
        natID->setPlaceholderText(QString());
        password->setPlaceholderText(QString());
        governorate->setPlaceholderText(QString());
        male->setText(QCoreApplication::translate("SignupClass", "Male", nullptr));
        female->setText(QCoreApplication::translate("SignupClass", "Female", nullptr));
        unvaccinated->setText(QCoreApplication::translate("SignupClass", "Unvaccinated", nullptr));
        vaccinated_1->setText(QCoreApplication::translate("SignupClass", "1 Dose", nullptr));
        vaccinated_2->setText(QCoreApplication::translate("SignupClass", "2 Doses", nullptr));
        label->setText(QCoreApplication::translate("SignupClass", "Full Name:", nullptr));
        label_2->setText(QCoreApplication::translate("SignupClass", "National ID:", nullptr));
        label_3->setText(QCoreApplication::translate("SignupClass", "Password:", nullptr));
        label_4->setText(QCoreApplication::translate("SignupClass", "Gender:", nullptr));
        label_5->setText(QCoreApplication::translate("SignupClass", "Governorate:", nullptr));
        label_6->setText(QCoreApplication::translate("SignupClass", "Vaccine Status:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupClass: public Ui_SignupClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
