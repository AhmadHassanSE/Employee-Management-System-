#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include "employee.h"
#include "newemployee.h"

namespace Ui {
class AdminDashboard;
}

class AdminDashboard : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDashboard(QWidget *parent = nullptr);
    ~AdminDashboard();

private slots:
    void on_logout_btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::AdminDashboard *ui;
    Employee *employees;
};

#endif // ADMINDASHBOARD_H
