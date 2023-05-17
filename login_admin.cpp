#include "login_admin.h"
#include "Initial.h"
#include "admin_screen.h"

Login_Admin::Login_Admin(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::LoginAdminClass)
{
    ui->setupUi(this);

    //set initial warning to invisible
    ui->password_warn->setVisible(false);
    //ommiting password
    ui->password->setEchoMode(QLineEdit::Password);

    connect(ui->password, &QLineEdit::returnPressed, this, &Login_Admin::login_clicked);
    connect(ui->login, &QPushButton::clicked, this, &Login_Admin::login_clicked);
    connect(ui->back, &QPushButton::clicked, this, &Login_Admin::back_clicked);
}

Login_Admin::~Login_Admin()
{
    delete ui;
}


void Login_Admin::login_clicked() {

    //read from text boxes, validate inputs, then proceed or give an error message if wrong
    QString password = ui->password->text();

    if (password == "admin") {
        ui->password_warn->setVisible(false);
        qDebug() << "Admin Login Success";
        //display next screen
        Admin_Screen* admin_screen = new Admin_Screen();
        admin_screen->show();
        this->close();
    }
    else {
        ui->password_warn->setVisible(true);
    }
}

void Login_Admin::back_clicked() {

    Initial* initial = new Initial();

    initial->show();

    this->close();

}
