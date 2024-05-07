#include "removeemployee.h"
#include "ui_removeemployee.h"

RemoveEmployee::RemoveEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveEmployee)
{
    ui->setupUi(this);
}

RemoveEmployee::~RemoveEmployee()
{
    delete ui;
}

void RemoveEmployee::on_done_btn_clicked()
{
    int id = ui->emp_id_spinbox->value();
    QSqlDatabase db5 = QSqlDatabase::addDatabase("QSQLITE");
    db5.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if (db5.open()){
        QSqlQuery query1(db5);
        query1.prepare("DELETE FROM Employee WHERE id = :id;");
        query1.bindValue(":id", id);
        if(query1.exec()){
            QMessageBox::about(this, "Success", "Employee Removed");
        }
        else{
            qDebug() << "Query execution failed";
        }
    }
    db5.close();
    accept();
}

