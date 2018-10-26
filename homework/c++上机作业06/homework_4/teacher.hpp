#pragma once;
#include<string>
#include"student.hpp"
using namespace std;
class teacher
{
private:
    string name;
public:
    string get_name();
    void change_name(string Name);
    teacher(string Name="XXX");
    void change_credit(student& a,int Credit);
    void change_score(student& a,int Score);
};
