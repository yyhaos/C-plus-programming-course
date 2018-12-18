#include"student.hpp"
using namespace std;
Student::Student(string Name,int Age,string Major,int ID):
    Person(Name,Age),major(Major),StudentID(ID){};

void Student::SetMajor(string Major)
{
    major=Major;
}
string Student::GetMajor()
{
    return major;
}
void Student::SetStudentID(int ID)
{
    StudentID=ID;
}
int Student::GetStudentID()
{
    return StudentID;
}
