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
    QString gender = "";
    QString age = "";
    QString department = "";
    QString mobileNumber = "";
    QString cnic = "";
    int salary = 0;
    float experienceInYears = 0;
    int noOfLeaves = 0;

public:
    // Constructors
    Employee(){}
    Employee(QString username, int id, QString name, QString gender, QString age, QString department,
             QString mobile, QString cnic, int salary, float experinceInYears, int noOfLeaves);
    // Destructors
    ~Employee(){};
    // Setters
    void setUserName(QString userName);
    void setId(int id);
    void setName(QString name);
    void setGender(QString gender);
    void setAge(QString age);
    void setDepartment(QString department);
    void setMobile(QString mobile);
    void setCnic(QString cnic);
    void setSalary(int salary);
    void setExperienceInYears(float experience);
    void setNoOfLeaves(int leaves);
    // Getters
    QString getUserName();
    QString getName();
    QString getGender();
    QString getAge();
    QString getDepartment();
    QString getMobileNumber();
    QString getCnic();
    int getSalary();
    float getExperienceInYears();
    int getNoOfLeaves;
};

#endif // EMPLOYEE_H
