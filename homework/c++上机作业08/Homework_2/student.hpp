#pragma once
#include"person.hpp"
using namespace std;
class Student:virtual public Person
{
private:
    string major;
    int StudentID;
public:
    Student(string Name,int Age,string Major,int ID);
    void SetMajor(string Major);
    string GetMajor();
    void SetStudentID(int ID);
    int GetStudentID();
};
