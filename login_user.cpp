#include "login_user.h"
#include "Initial.h"
#include "main.h"
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

    // read from text boxes, validate inputs, then proceed or give an error message if wrong

    QString natID = ui->natID->toPlainText();
    string key = natID.toStdString();

    QString password = ui->password->toPlainText();
    string value = password.toStdString();

    if (userHash.count(key)){
        if (value == userHash[key].password) {
            qDebug() << "Login Success";
            //Display next screen
        }
        else {
            //Display Failure text with reason (Invalid Pass)
            qDebug() << "Login Failed";
        }
    }
    else {
        //Display Failure text with reason (Invalid ID)
        qDebug() << "Login Failed";
    }
}

void Login_User::back_clicked() {

    Initial* initial = new Initial();

    initial->show();

    this->close();

}
