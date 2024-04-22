#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(Employee &employee, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dashboard)
{

    ui->setupUi(this);
}

Dashboard::~Dashboard()
{
    delete ui;
}
void Dashboard::updateWelcomeMessage(const QString &employeeName){
  ui->label->setText("Welcome Back" + employeeName);
}
