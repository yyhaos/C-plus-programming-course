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
    cout<<"��ʦ"<<this->name<<"��ѧ��"<<a.name<<"����"<<Credit<<"ѧ�֣������ɹ�"<<endl;
    a.credit+=Credit;
}
void teacher::change_score(student& a,int Score)
{
    cout<<"��ʦ"<<this->name<<"��ѧ��"<<a.name<<"����"<<Score<<"�ܳɼ��������ɹ�"<<endl;
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
