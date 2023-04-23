#include "login_admin.h"
#include "Initial.h"

Login_Admin::Login_Admin(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::LoginAdminClass)
{
    ui->setupUi(this);

    connect(ui->login, &QPushButton::clicked, this, &Login_Admin::login_clicked);
    connect(ui->back, &QPushButton::clicked, this, &Login_Admin::back_clicked);
}

Login_Admin::~Login_Admin()
{
    delete ui;
}


void Login_Admin::login_clicked() {

    //read from text boxes, validate inputs, then proceed or give an error message if wrong
    QString password = ui->password->toPlainText();

    if (password == "admin") {

        //display next screen
 
    }
}

void Login_Admin::back_clicked() {

    Initial* initial = new Initial();

    initial->show();

    this->close();

}
