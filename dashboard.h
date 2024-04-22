#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include "employee.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(Employee &employee,QWidget *parent = nullptr);
    ~Dashboard();
private slots:
   void updateWelcomeMessage(const QString &employeeName);
private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
