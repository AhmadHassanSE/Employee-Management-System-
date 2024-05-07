#include "newemployee.h"
#include "ui_newemployee.h"

QString username, password, name, age, gender, department, email, mobile, cnic,
        experienceInYears, currentTask;
int id, salary, totalLeaves, approvedLeaves, rejectedLeaves, pendingLeaves;

NewEmployee::NewEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEmployee)
{
    ui->setupUi(this);

}

NewEmployee::~NewEmployee()
{
    delete ui;
}

void NewEmployee::on_pushButton_clicked()
{
    username = ui->username_input->text();
    password = ui->password_input->text();
    id = (ui->id_input->text()).toInt();
    name = ui->name_input->text();
    age = QString::number(ui->age_spinbox->value());
    gender = ui->gender_combobox->currentText();
    department = ui->department_input->text();
    email = ui->email_input->text();
    mobile = ui->mobile_input->text();
    cnic = ui->cnic_input->text();
    salary = ui->salary_input->text().toInt();
    experienceInYears = QString::number(ui->experience_spinbox->value());

    QSqlDatabase db4 = QSqlDatabase::addDatabase("QSQLITE");
        db4.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
        QSqlQuery query(db4);
        if (db4.open()){
            query.prepare("INSERT INTO Employee (username, id, name, age, gender, department, email, mobile, cnic, salary, experience, total_leaves, approved_leaves, rejected_leaves, pending_leaves, current_task) VALUES (:username, :id, :name, :age, :gender, :department, :email, :mobile, :cnic, :salary, :experience, :total_leaves, :approved_leaves, :rejected_leaves, :pending_leaves, :current_task);");
                    query.bindValue(":username", username);
                    query.bindValue(":id", id);
                    query.bindValue(":name", name);
                    query.bindValue(":age", age);
                    query.bindValue(":gender", gender);
                    query.bindValue(":department", department);
                    query.bindValue(":email", email);
                    query.bindValue(":mobile", mobile);
                    query.bindValue(":cnic", cnic);
                    query.bindValue(":salary", salary);
                    query.bindValue(":experience", experienceInYears);
                    query.bindValue(":total_leaves", totalLeaves);
                    query.bindValue(":approved_leaves", approvedLeaves);
                    query.bindValue(":rejected_leaves", rejectedLeaves);
                    query.bindValue(":pending_leaves", pendingLeaves);
                    query.bindValue(":current_task", currentTask);
                    query.exec();

            }
            else{
                qDebug() << "Cannot open Databse";
            }
        db4.close();
        QMessageBox::about(this, "Success", "Employee Added");
        accept();
}

