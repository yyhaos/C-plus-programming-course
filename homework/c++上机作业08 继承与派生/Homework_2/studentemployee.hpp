#include"employee.hpp"
#include"student.hpp"
#pragma once
using namespace std;
class StudentEmployee:public Student,public Employee
{
public:
    StudentEmployee(string Name,int Age,string Major,int studentID,
                    string Department,int employeeID):
                        Person(Name,Age),
                        Student(Name,Age,Major,studentID),
                        Employee(Name,Age,Department,employeeID){};
};
