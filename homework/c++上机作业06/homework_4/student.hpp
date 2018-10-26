#pragma once;
using namespace std;
#include<string>
class student
{
private:
    string name;
    int credit;
    int score;
public:
    student(string Name="XXX",int Credit=0,int Score=0);
    string get_name();
    void change_name(string Name);
    Show();
    //friend void teacher::change_credit(student a,int Credit);
    //friend void teacher::change_score(student a,int Score);
    friend class teacher;
};
