#include "student.hpp"
#include<string>
#include<iostream>
using namespace std;
student::student(string Name,int Credit,int Score)
{
    name=Name;
    credit=Credit;
    score=Score;
}
student::Show()
{
    cout<<name<<"\t"<<credit<<"\t"<<score<<endl;
}
void student::change_name(string Name)
{
    name=Name;
}
string student::get_name()
{
    return name;
}
