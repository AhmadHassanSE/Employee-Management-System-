#include "admindashboard.h"
#include "ui_admindashboard.h"

AdminDashboard::AdminDashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);
    // Setting navigation bar icons

//    QIcon home("/home/muhammad-ali/icons/home.png");
//    ui->home_btn->setIcon(home);
//    ui->home_btn->setIconSize(QSize(25, 25));
//    ui->home_btn->setFixedSize(QSize(25, 25));
//    ui->home_btn->setFocusPolicy(Qt::NoFocus);

//    QIcon salary("/home/muhammad-ali/icons/salary.png");
//    ui->salary_btn->setIcon(salary);
//    ui->salary_btn->setIconSize(QSize(25, 25));
//    ui->salary_btn->setFixedSize(QSize(25, 25));
//    ui->salary_btn->setFocusPolicy(Qt::NoFocus);

//    QIcon attendance("/home/muhammad-ali/icons/attendance.png");
//    ui->attendance_btn->setIcon(attendance);
//    ui->attendance_btn->setIconSize(QSize(25, 25));
//    ui->attendance_btn->setFixedSize(QSize(25, 25));
//    ui->attendance_btn->setFocusPolicy(Qt::NoFocus);

//    QIcon performance("/home/muhammad-ali/icons/performance.png");
//    ui->performance_btn->setIcon(performance);
//    ui->performance_btn->setIconSize(QSize(25, 25));
//    ui->performance_btn->setFixedSize(QSize(25, 25));
//    ui->performance_btn->setFocusPolicy(Qt::NoFocus);

    QIcon logout("/home/muhammad-ali/icons/logout.png");
    ui->logout_btn->setIcon(logout);
    ui->logout_btn->setIconSize(QSize(25, 25));
    ui->logout_btn->setFixedSize(QSize(25, 25));
    ui->logout_btn->setFocusPolicy(Qt::NoFocus);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/muhammad-ali/Downloads/EMS.db");
    if (db.open()){
        QSqlQuery query1;
           query1.prepare("SELECT COUNT(*) FROM Employee");
            if (!query1.exec()) {
                qDebug() << "Error executing query:" << query1.lastError().text();
            }
            // Fetch the result
            if (query1.next()) {
                int totalEmployees = query1.value(0).toInt();
                ui->label_2->setText(QString::number(totalEmployees));
                QSqlQuery query2;
                query2.prepare("SELECT * FROM Employee");
                if (!query2.exec()) {
                    qDebug() << "Error executing query:" << query2.lastError().text();
                    return;
                }
                while (query2.next()) {
                    // Retrieve data from each column of the current row
                    QString id = query2.value(1).toString();
                    QString name = query2.value(2).toString();
                    QString department = query2.value(5).toString();
                    ui->id_listwidget->addItem(id);
                    ui->id_listwidget->setStyleSheet("QListWidget { border: none; }");
                    ui->name_listwidget->addItem(name);
                    ui->name_listwidget->setStyleSheet("QListWidget { border: none; }");
                    ui->department_listwidget->addItem(department);
                    ui->department_listwidget->setStyleSheet("QListWidget { border: none; }");

                }
            } else {
                qDebug() << "No result fetched!";
            }
        }
    else{
        QMessageBox::critical(this, "Connection Error", "Unable to connect database :(");
    }
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}

void AdminDashboard::on_logout_btn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quit?", "Are you sure you want to quit?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      QMessageBox::about(this, "Logged Out", "You are successfully logged out");
      this->close();
      QApplication::quit();
    }
}
void AdminDashboard::on_pushButton_clicked()
{
    NewEmployee newEmp;
    newEmp.setModal(true);
    newEmp.setWindowTitle("New Employee");
    newEmp.exec();
}
