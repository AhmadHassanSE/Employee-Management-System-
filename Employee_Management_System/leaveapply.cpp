#include "leaveapply.h"
#include "ui_leaveapply.h"

// Variables to hold employee ID and leaves throughout this dialog
QString empId;
int leaves;

LeaveApply::LeaveApply(Employee& obj, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeaveApply)
{
    ui->setupUi(this);
    ui->leave_spinbox->setMinimum(1); // Setting minimum index of leaves
    empId = obj.getId();
    leaves = obj.getTotalLeaves();
}

LeaveApply::~LeaveApply()
{
    delete ui;
}

void LeaveApply::on_pushButton_clicked()
{
    int newLeaves = leaves + (ui->leave_spinbox->value()); // Updating leaves after gaining input
    int pendingLeaves = newLeaves - leaves; // Pending leaves are newly applied leaves minus previous leaves
    QSqlDatabase db3 = QSqlDatabase::addDatabase("QSQLITE");
    db3.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if (db3.open()){
        QSqlQuery query(db3);
        // Updating Database with new number of total_leaves and pending_leaves
        query.prepare("UPDATE Employee SET total_leaves = :newLeaves, pending_leaves = :pendingLeaves WHERE id = :employeeId");
        query.bindValue(":newLeaves", newLeaves);
        query.bindValue(":pendingLeaves", pendingLeaves);
        query.bindValue(":employeeId", empId);
        query.exec();
        db3.close();
    }
    accept();
    QMessageBox::information(this, "Success", "Leave applied");
}

