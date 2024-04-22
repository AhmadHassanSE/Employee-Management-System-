#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signIn_btn_clicked()
{
    QString username = ui->username_input->text();
    QString password = ui->password_input->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/muhammad-ali/EMS.db");
    if (db.open()){
        QSqlQuery query1(db);
        query1.prepare("SELECT * FROM Employee_login WHERE username = :username AND password = :password;");
        query1.bindValue(":username", username);
        query1.bindValue(":password", password);
        if(query1.exec() && query1.next()){
            QMessageBox::about(this, "Correct Password", "Login Successful :)");
            int id, salary, noOfLeaves;
            float experienceInYears;
            QSqlQuery query2(db);
            query2.prepare("SELECT * FROM Employee WHERE employee_username = :username");
            query2.bindValue(":username", username);
            if(query2.exec() && query2.next()){
                QString name, gender, age, department, mobile, cnic;
                id = query2.value("employee_id").toInt();
                name = query2.value("employee_name").toString();
                gender = query2.value("gender").toString();
                age = query2.value("age").toString();
                department = query2.value("employee_dept").toString();
                mobile = query2.value("employee_mobile").toString();
                cnic = query2.value("employee_cnic").toString();
                salary = query2.value("employee_salary").toInt();
                experienceInYears = query2.value("employee_experience").toFloat();
                noOfLeaves = query2.value("employee_leaves").toFloat();
                qDebug()<<username<<id<<name<<gender<<age<<department<<mobile<<cnic<<salary
                       <<experienceInYears<<noOfLeaves;
            }
//                Dashboard dash;
//                this->hide();
//                dash.setModal(true);
//                dash.exec();
        }else{
          QMessageBox::critical(this, "Incorrect Password", "Unable to Login :(");
        }

    }
}

void MainWindow::on_adminLogin_btn_clicked()
{
    QString username = ui->username_input->text();
    QString password = ui->password_input->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/muhammad-ali/EMS.db");
    if (db.open()){
        QSqlQuery query(db);
        query.prepare("SELECT * FROM Admin_login WHERE username = :username AND password = :password;");
        query.bindValue(":username", username);
        query.bindValue(":password", password);
        if(query.exec()){
            if(query.next()){
                QMessageBox::about(this, "Correct Password", "Login Successful :)");
            }
            else{
                QMessageBox::critical(this, "Incorrect Password", "Unable to Login :(");
            }
        }
    }
    else{
        QMessageBox::critical(this, "Not Connected", "Unable to Connect");
    }

}

