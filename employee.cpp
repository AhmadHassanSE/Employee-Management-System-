#include "employee.h"
using namespace std;
Employee::Employee(QString username, int id, QString name, QString gender, QString age, QString department, QString mobile, QString cnic,
                   int salary, float experienceInYears, int noOfLeaves){
    setUserName(username);
    setId(id);
    setName(name);
    setGender(gender);
    setAge(age);
    setDepartment(department);
    setMobile(mobile);
    setCnic(cnic);
    setSalary(salary);
    setExperienceInYears(experienceInYears);
    setNoOfLeaves(noOfLeaves);
}
// Setters
void Employee::setUserName(QString userName){
    this->username = userName;
}
void Employee::setId(int id){
    if(id > 0)
        this->id = id;
}
void Employee::setName(QString name){
    this->name = name;
}
void Employee::setGender(QString gender){
    if(gender == "male" || gender == "female")
        this->gender = gender;
}
void Employee::setAge(QString age){
    if(age > 0)
        this->age = age;
}
void Employee::setDepartment(QString department){
    this->department = department;
}
void Employee::setMobile(QString mobileNumber){
    if (mobileNumber.length() == 11)
        this->mobileNumber = mobileNumber;
}
void Employee::setCnic(QString cnic){
    if(cnic.length() == 13)
        this->cnic = cnic;
}
void Employee::setSalary(int salary){
    if(salary > 0)
        this->salary = salary;
}
void Employee::setExperienceInYears(float experienceInYears){
    if(experienceInYears > 0.0)
        this->experienceInYears = experienceInYears;
}
void Employee::setNoOfLeaves(int noOfLeaves){
    if(noOfLeaves >= 0)
        this->noOfLeaves = noOfLeaves;
}
// Getters
QString Employee::getUserName(){
    return this->username;
}
