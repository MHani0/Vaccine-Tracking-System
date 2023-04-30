#include "Initial.h"
#include "login_user.h"
#include "login_admin.h"
#include "signup.h"
#include "Main.h"

Initial::Initial(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::InitialClass)
{
    ui->setupUi(this);

    //reset any logged in user
    loggedInUserID = "";

    connect(ui->login_user, &QPushButton::clicked, this, &Initial::login_user_button_clicked);
    connect(ui->login_admin, &QPushButton::clicked, this, &Initial::login_admin_button_clicked);
    connect(ui->signup, &QPushButton::clicked, this, &Initial::signup_button_clicked);
}

Initial::~Initial()
{
    delete ui;
}

void Initial::login_user_button_clicked() {

    Login_User* login_user = new Login_User();

    login_user->show();

    this->close();

}

void Initial::login_admin_button_clicked() {

    Login_Admin* login_admin = new Login_Admin();

    login_admin->show();

    this->close();

}

void Initial::signup_button_clicked() {

    Signup* signup = new Signup();

    signup->show();

    this->close();

}