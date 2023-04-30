#include "login_user.h"
#include "Initial.h"
#include "user_screen.h"
#include "main.h"

Login_User::Login_User(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::LoginUserClass)
{
    ui->setupUi(this);

    //make the warning initially invisible 
    ui->login_warn->setVisible(false);
    
    connect(ui->login, &QPushButton::clicked, this, &Login_User::login_clicked);
    connect(ui->back, &QPushButton::clicked, this, &Login_User::back_clicked);
}

Login_User::~Login_User()
{
    delete ui;
}


void Login_User::login_clicked() {

    // read from text boxes, validate inputs, then proceed or give an error message if wrong

    QString natID = ui->natID->text();
    string key = natID.toStdString();

    QString password = ui->password->text();
    string value = password.toStdString();

    if (userHash.count(key)){
        if (value == userHash[key].password) {
            ui->login_warn->setVisible(false);
            qDebug() << "Login Success";

            loggedInUserID = key;
            //Display next screen
            User_Screen* user_screen = new User_Screen();
            user_screen->show();
            this->close();

        }
        else {
            ui->login_warn->setVisible(true);
            qDebug() << "Login Failed";
        }
    }
    else {
        ui->login_warn->setVisible(true);
        qDebug() << "Login Failed";
    }
}

void Login_User::back_clicked() {

    Initial* initial = new Initial();

    initial->show();

    this->close();

}
