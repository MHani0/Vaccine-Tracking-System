#include "signup.h"
#include "Initial.h"

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


void Signup::signup_clicked() {

    //read from text boxes, validate inputs, then proceed or give an error message if wrong
        //validate inputs and length of nat ID
    QString name = ui->name->toPlainText();
    QString natID = ui->natID->toPlainText();
    QString password = ui->password->toPlainText();

    QString gender = "";
    //make sure a box got checked before proceeding to not read from NULL
    if (ui->genderButtonGroup->checkedButton() != nullptr) {
        gender = ui->genderButtonGroup->checkedButton()->objectName(); //male or female
    }

    QString governorate = ui->governorate->toPlainText();

    QString vaccine = "";
    if (ui->vaccineButtonGroup->checkedButton() != nullptr) {  //make sure not NULL
        vaccine = ui->vaccineButtonGroup->checkedButton()->objectName(); //returns unvaccinated or vaccinated_1 or vaccinated_2
    }

    
    //validate the data, insert the data into a new object of User in the hash table
}

void Signup::back_clicked() {

    Initial* initial = new Initial();

    initial->show();

    this->close();

}
