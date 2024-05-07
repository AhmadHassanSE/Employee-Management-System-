#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
using namespace std;


class Employee
{
private:
    QString username = "";
    int id = 0;
    QString name = "";
    QString age = "";
    QString gender = "";
    QString department = "";
    QString email = "";
    QString mobile = "";
    QString cnic = "";
    int salary = 0;
    QString experienceInYears = "0";
    int totalLeaves = 0;
    int approvedLeaves = 0;
    int rejectedLeaves = 0;

public:
    // Constructors
    Employee(){}
    Employee(QString username, int id, QString name, QString age, QString gender, QString department,
             QString email, QString mobile, QString cnic, int salary, QString experinceInYears,
             int totalLeaves, int approvedLeaves, int rejectedLeaves);
    // Destructors
    ~Employee(){};
    // Setters
    void setUsername(QString userName);
    void setId(int id);
    void setName(QString name);
    void setAge(QString age);
    void setGender(QString gender);
    void setDepartment(QString department);
    void setEmail(QString email);
    void setMobile(QString mobile);
    void setCnic(QString cnic);
    void setSalary(int salary);
    void setExperienceInYears(QString experience);
    void setTotalLeaves(int totalLeaves);
    void setApprovedLeaves(int approvedLeaves);
    void setRejectedLeaves(int rejectedLeaves);
    // Getters
    QString getUsername();
    int getId();
    QString getName();
    QString getAge();
    QString getGender();
    QString getDepartment();
    QString getEmail();
    QString getMobile();
    QString getCnic();
    int getSalary();
    QString getExperienceInYears();
    int getTotalLeaves();
    int getApprovedLeaves();
    int getRejectedLeaves();
};

#endif // EMPLOYEE_H
