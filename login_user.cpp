#include "login_user.h"
#include "Initial.h"

Login_User::Login_User(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::LoginUserClass)
{
    ui->setupUi(this);

    connect(ui->login, &QPushButton::clicked, this, &Login_User::login_clicked);
    connect(ui->back, &QPushButton::clicked, this, &Login_User::back_clicked);
}

Login_User::~Login_User()
{
    delete ui;
}


void Login_User::login_clicked() {

//read from text boxes, validate inputs, then proceed or give an error message if wrong
    //validate inputs and length of nat ID
    QString natID = ui->natID->toPlainText();
    QString password = ui->password->toPlainText();

    if (natID == "12345" && password == "password") {
     
        //display next screen
    }
}

void Login_User::back_clicked() {

    Initial* initial = new Initial();

    initial->show();

    this->close();

}
