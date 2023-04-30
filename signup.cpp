#include "signup.h"
#include "main.h"
#include "Initial.h"

using namespace std;





Signup::Signup(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::SignupClass)
{
    ui->setupUi(this);

    //set validations to false (default)
    Signup::id_valid = false;
    Signup::name_valid = false;
    Signup::password_valid = false;
    Signup::age_valid = false;
    Signup::governorate_valid = false;
    Signup::gender_valid = false;
    Signup::vaccine_valid = false;


    //make the warning initially invisible
    ui->name_warn->setVisible(false);
    ui->password_warn->setVisible(false);
    ui->age_warn->setVisible(false);
    ui->ID_warn->setVisible(false);
    ui->gov_warn->setVisible(false);
    ui->gender_warn->setVisible(false);
    ui->dose_warn->setVisible(false);

    //successful note
    ui->successfully->setVisible(false);

    //make it initially enabled
    ui->signup->setEnabled(true);
    
    //buttons
    connect(ui->signup, &QPushButton::clicked, this, &Signup::signup_clicked);
    connect(ui->back, &QPushButton::clicked, this, &Signup::back_clicked);

    //text loses focus
    connect(ui->name, &QLineEdit::editingFinished, this, &Signup::name_validate);
    connect(ui->natID, &QLineEdit::editingFinished, this, &Signup::id_validate);
    connect(ui->password, &QLineEdit::editingFinished, this, &Signup::pass_validate);
    connect(ui->age, &QLineEdit::editingFinished, this, &Signup::age_validate);
    connect(ui->governorate, &QLineEdit::editingFinished, this, &Signup::gov_validate);


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

    QString q_name = ui->name->text();
    string name = q_name.toStdString();

    /*QString age = ui->age->toPlainText();
    string std_age = age.toStdString();*/

    QString q_natID = ui->natID->text();
    string natID = q_natID.toStdString();

    QString q_password = ui->password->text();
    string password = q_password.toStdString();

    string q_age = ui->age->text().toStdString();

    QString q_governorate = ui->governorate->text();
    string governorate = q_governorate.toStdString();

    //make sure a box got checked before proceeding to not read from NULL
    string gender;
    if (ui->genderButtonGroup->checkedButton() != nullptr) {

        ui->gender_warn->setVisible(false);

        QString q_gender = ui->genderButtonGroup->checkedButton()->objectName();
        if (q_gender.toStdString() == "male")
            gender = "male";
        else {
            gender = "female";
        }

        gender_valid = true;
    }
    else {
        ui->gender_warn->setVisible(true);
        gender_valid = false;
        qDebug() << "Gender Required Field!";
    }
    
    //returns unvaccinated or vaccinated_1 or vaccinated_2
    int vaccine = 0;
    if (ui->vaccineButtonGroup->checkedButton() != nullptr) {  //make sure not NULL

        ui->dose_warn->setVisible(false);

        QString q_vaccine = ui->vaccineButtonGroup->checkedButton()->objectName();
        if (q_vaccine.toStdString() == "unvaccinated")
            vaccine = 0;
        else if (q_vaccine.toStdString() == "vaccinated_1")
            vaccine = 1;
        else {
            vaccine = 2;
        }

        vaccine_valid = true;
    }
    else {
        ui->dose_warn->setVisible(true);
        vaccine_valid = false;
        qDebug() << "Vaccine is Required Field!";
    }
 

    
    //if everything is valid then create user
    if (id_valid && name_valid && age_valid && password_valid && gender_valid && vaccine_valid && governorate_valid) {

        ui->signup->setEnabled(false);
        ui->successfully->setVisible(true);

        qDebug() << "User Created";
        User user(password, name, stoi(q_age), gender, governorate, vaccine);
        hashKeysOrdered.push_back(natID);
        userHash[natID] = user;

        //insert him into either queue waiting list or linked list, depending on his dose
        if (vaccine == 0)
            not_vaccinated.push(natID);
        else
            vaccinated.insert(natID, userHash);

        //next page
    }
   
    
}

void Signup::back_clicked() {

    Initial* initial = new Initial();

    initial->show();

    this->close();

}



//validation functions
void Signup::name_validate() {

    string name = ui->name->text().toStdString();
    if (name == "") {
        ui->name_warn->setVisible(true);
        name_valid = false;
        qDebug() << "Name Required Field!";
    }
    else {
        name_valid = true;
        ui->name_warn->setVisible(false);
    }

}


void Signup::id_validate() {

    string natID = ui->natID->text().toStdString();
    //validate the data, insert the data into a new object of User in the hash table
    if (userHash.count(natID) || natID.length() != 14 || !isDigitString(natID)) {
        id_valid = false;
        ui->ID_warn->setVisible(true);
        qDebug() << "Invalid ID";

    }
    else {
        id_valid = true;
        ui->ID_warn->setVisible(false);
    }

}


void Signup::pass_validate() {

    string password = ui->password->text().toStdString();
    if (password.length() < 8) {
        password_valid = false;
        ui->password_warn->setVisible(true);
        qDebug() << "Password must be at least 8 characters";

    }
    else {
        password_valid = true;
        ui->password_warn->setVisible(false);
    }
}


void Signup::age_validate() {

    string q_age = ui->age->text().toStdString();
    int age;
    //validate the data, insert the data into a new object of User in the hash table
    if (isDigitString(q_age)) {
        age = stoi(q_age);
        if (age <= 0) {
            age_valid = false;
            ui->age_warn->setVisible(true);
            qDebug() << "Age must be more than 0";
        }
        //valid age
        else {
            age_valid = true;
            ui->age_warn->setVisible(false);
        }
    }
    else {
        age_valid = false;
        ui->age_warn->setVisible(true);
        qDebug() << "Age must be a number!";

    }
}

void Signup::gov_validate() {

    string governorate = ui->governorate->text().toStdString();
  
    if (governorate == "") {
        governorate_valid = false;
        ui->gov_warn->setVisible(true);
        qDebug() << "Governorate Required Field!";

    }
    else {
        governorate_valid = true;
        ui->gov_warn->setVisible(false);
    }
}

