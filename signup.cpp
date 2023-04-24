#include "signup.h"
#include "main.h"
#include "Initial.h"

using namespace std;

Signup::Signup(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::SignupClass)
{
    ui->setupUi(this);

    connect(ui->signup, &QPushButton::clicked, this, &Signup::signup_clicked);
    connect(ui->back, &QPushButton::clicked, this, &Signup::back_clicked);
}

Signup::~Signup()
{
    delete ui;
}

//bugs: errors do not show together (solvable by crooky if statement too many conditions)
// age text box not added (code written)
//Running does not save in files

void Signup::signup_clicked() {

    //read from text boxes, validate inputs, then proceed or give an error message if wrong
    //validate inputs and length of nat ID

    QString name = ui->name->toPlainText();
    string std_name = name.toStdString();

    /*QString age = ui->age->toPlainText();
    string std_age = age.toStdString();*/

    QString natID = ui->natID->toPlainText();
    string std_natID = natID.toStdString();

    QString password = ui->password->toPlainText();
    string std_password = password.toStdString();

    QString governorate = ui->governorate->toPlainText();
    string std_governorate = governorate.toStdString();

    //make sure a box got checked before proceeding to not read from NULL
    string gender;    
    if (ui->genderButtonGroup->checkedButton() != nullptr) {
        QString radio_choice = ui->genderButtonGroup->checkedButton()->objectName();
        if (radio_choice.toStdString() == "male")
            gender = "Male";
        else {
            gender = "Female";
        }
    }
    
    //returns unvaccinated or vaccinated_1 or vaccinated_2
    int vaccine;
    if (ui->vaccineButtonGroup->checkedButton() != nullptr) {  //make sure not NULL
        QString radio_choice = ui->vaccineButtonGroup->checkedButton()->objectName();
        if (radio_choice.toStdString() == "unvaccinated")
            vaccine = 0;
        else if (radio_choice.toStdString() == "vaccinated_1")
            vaccine = 1;
        else {
            vaccine = 2;
        }
     
    }

    //validate the data, insert the data into a new object of User in the hash table
    if (userHash.count(std_natID)) {
        qDebug() << "User already exists";
        return;
    }
    if (std_name == "") {
        qDebug() << "Name Required Field!";
        return;
        
    }
    if (std_natID.length() != 14) {
        qDebug() << "ID should be 14 characters";
        return;
    }
    if (std_password.length() < 8) {
        qDebug() << "Password must be at least 8 characters";
        return;
    }
    if (ui->genderButtonGroup->checkedButton() == nullptr) {
        qDebug() << "Gender Required Field!";
        return;
    }
    /*
    if (isdigit(age)){   
        if(std_age <= 0) {
            qDebug() << "Age must be more than 0";
        }
        return;
    }
    if (!isdigit(age)){
        qDebug() << "Age must be a number!";
        return;
    }
    */
    
    if (std_governorate == "") {
        qDebug() << "Governorate Required Field!";
        return;
    }
    if (ui->vaccineButtonGroup->checkedButton() == nullptr) {
        qDebug() << "Vaccine is Required Field!";
        return;
    }
    // decoy age *5* remove when complete
    else {
        qDebug() << "User Created";
        User entry(std_password, std_name, 5,/*(int)std_age,*/ gender, std_governorate, vaccine);
        userHash[std_natID] = entry;
        //next page
    }
    
}

void Signup::back_clicked() {

    Initial* initial = new Initial();

    initial->show();

    this->close();

}
