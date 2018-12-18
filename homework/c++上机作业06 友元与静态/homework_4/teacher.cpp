#include "teacher.hpp"
#include<string>
#include<iostream>
using namespace std;
teacher::teacher(string Name)
{
    name=Name;
}
void teacher::change_credit(student& a,int Credit)
{
    cout<<"教师"<<this->name<<"给学生"<<a.name<<"增加"<<Credit<<"学分，操作成功"<<endl;
    a.credit+=Credit;
}
void teacher::change_score(student& a,int Score)
{
    cout<<"教师"<<this->name<<"给学生"<<a.name<<"增加"<<Score<<"总成绩，操作成功"<<endl;
    a.score+=Score;
}
void teacher::change_name(string Name)
{
    name=Name;
}
string teacher::get_name()
{
    return name;
}
