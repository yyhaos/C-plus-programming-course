#pragma once;
#include"person.hpp"
using namespace std;
class Employee:virtual public Person
{
private:
    string department;
    int EmployeeID;
public:
    Employee(string Name,int Age,string Department,int ID);
    void SetDepartment(string Department);
    string GetDepartment();
    void SetEmployeeID(int ID);
    int GetEmployeeID();
};
