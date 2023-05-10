#include "user_screen.h"
#include "main.h"
#include "Initial.h"




User_Screen::User_Screen(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::userScreenClass)
{
    ui->setupUi(this);

    //welcome message
    QString welcomeMSG = "Hi, " + QString::fromStdString(userHash[loggedInUserID].name) + "!";
    ui->welcome->setText(welcomeMSG);

    //set initials visibilities
    ui->user_frame->setVisible(true);
    ui->display_frame->setVisible(false);
    ui->delete_frame->setVisible(false);
    ui->edit_frame->setVisible(false);


    //set initial warning visibilities 
    ui->name_warn->setVisible(false);
    ui->age_warn->setVisible(false);
   

    //buttons in user_frame
    connect(ui->display, &QPushButton::clicked, this, &User_Screen::display_clicked);
    connect(ui->edit, &QPushButton::clicked, this, &User_Screen::edit_clicked);
    connect(ui->deleteacc, &QPushButton::clicked, this, &User_Screen::delete_clicked);
    connect(ui->signout, &QPushButton::clicked, this, &User_Screen::signout_clicked);

    //buttons in display_frame
    connect(ui->display_back, &QPushButton::clicked, this, &User_Screen::display_back_clicked);

    //buttons in delete_frame
    connect(ui->yes, &QPushButton::clicked, this, &User_Screen::delete_yes_clicked);
    connect(ui->no, &QPushButton::clicked, this, &User_Screen::delete_no_clicked);

    //buttons in edit_frame
    connect(ui->edit_update, &QPushButton::clicked, this, &User_Screen::display_update_clicked);
    connect(ui->edit_cancel, &QPushButton::clicked, this, &User_Screen::display_cancel_clicked);

}

User_Screen::~User_Screen()
{
    delete ui;
}



void User_Screen::display_clicked() {

    ui->user_frame->setVisible(false);
    ui->display_frame->setVisible(true);



    QString name = QString::fromStdString(userHash[loggedInUserID].name);
    QString age = QString::number(userHash[loggedInUserID].age);
    QString governorate = QString::fromStdString(userHash[loggedInUserID].governorate);
    QString gender = QString::fromStdString(userHash[loggedInUserID].gender);


    QString vaccine;
    if (userHash[loggedInUserID].dose == 0)
        vaccine = "Unvaccinated";
    else if (userHash[loggedInUserID].dose == 1)
        vaccine = "1 Dose";
    else
        vaccine = "2 Doses";

    ui->id->setText(QString::fromStdString(loggedInUserID));
    ui->name->setText(name);
    ui->age->setText(age);
    ui->gov->setText(governorate);
    ui->gender->setText(gender);
    ui->vaccine->setText(vaccine);

}

void User_Screen::edit_clicked() {

    ui->user_frame->setVisible(false);
    ui->edit_frame->setVisible(true);

    //set text
    ui->edit_name->setText(QString::fromStdString(userHash[loggedInUserID].name));
    ui->edit_age->setText(QString::number(userHash[loggedInUserID].age));
    ui->edit_gov->setCurrentText(QString::fromStdString(userHash[loggedInUserID].governorate));

    //set radio button values
    //gender
    if (userHash[loggedInUserID].gender == "male" || userHash[loggedInUserID].gender == "Male") 
        ui->male->setChecked(true);
    
    else 
        ui->female->setChecked(true);
    
    //dose
    if (userHash[loggedInUserID].dose == 0) 
        ui->edit_unvaccinated->setChecked(true);
    
    else if (userHash[loggedInUserID].dose == 1)
        ui->edit_vaccinated_1->setChecked(true);
    else 
        ui->edit_vaccinated_2->setChecked(true);

}


void User_Screen::delete_clicked() {

    ui->user_frame->setVisible(false);
    ui->delete_frame->setVisible(true);
    

}


void User_Screen::signout_clicked() {

    loggedInUserID = "";

    Initial* initial = new Initial();
    initial->show();
    this->close();

}


//display frame
void User_Screen::display_back_clicked() {

    ui->display_frame->setVisible(false);
    ui->user_frame->setVisible(true);

}

//delete frame
void User_Screen::delete_yes_clicked() {

    deleteUser(loggedInUserID);
    Initial* initial = new Initial();
    initial->show();
    this->close();

}

void User_Screen::delete_no_clicked() {

    ui->delete_frame->setVisible(false);
    ui->user_frame->setVisible(true);

}


//edit frame
void User_Screen::display_update_clicked() {

    bool valid = true;

    //name validate
    if (ui->edit_name->text() == "") {
        valid = false;
        ui->name_warn->setVisible(true);
        qDebug() << "Name Required Field!";
    }
    else {
        ui->name_warn->setVisible(false);
    }



    //age validate
    string q_age = ui->edit_age->text().toStdString();
    int age;
    if (isDigitString(q_age)) {
        age = stoi(q_age);
        if (age <= 0) {
            valid = false;
            ui->age_warn->setVisible(true);
            qDebug() << "Age must be more than 0";
        }
        //valid age
        else {
            ui->age_warn->setVisible(false);
        }
    }
    else {
        valid = false;
        ui->age_warn->setVisible(true);
        qDebug() << "Age must be a number!";

    }




    //nothing has set valid to false, therfore it's true
    if (valid) {


        userHash[loggedInUserID].name = ui->edit_name->text().toStdString();
        userHash[loggedInUserID].age = stoi(ui->edit_age->text().toStdString());
        userHash[loggedInUserID].governorate = ui->edit_gov->currentText().toStdString();
        userHash[loggedInUserID].gender = ui->genderButtonGroup->checkedButton()->objectName().toStdString();
        
        if (ui->doseButtonGroup->checkedButton()->objectName() == "edit_unvaccinated")
            userHash[loggedInUserID].dose = 0;
        else if (ui->doseButtonGroup->checkedButton()->objectName() == "edit_vaccinated_1")
            userHash[loggedInUserID].dose = 1;
        else if (ui->doseButtonGroup->checkedButton()->objectName() == "edit_vaccinated_2")
            userHash[loggedInUserID].dose = 2;



        ui->edit_frame->setVisible(false);
        ui->user_frame->setVisible(true);

        //welcome message regenerating, because the name might have been changed
        QString welcomeMSG = "Hi, " + QString::fromStdString(userHash[loggedInUserID].name) + "!";
        ui->welcome->setText(welcomeMSG);
    }
}

void User_Screen::display_cancel_clicked() {

    ui->edit_frame->setVisible(false);
    ui->user_frame->setVisible(true);

}
