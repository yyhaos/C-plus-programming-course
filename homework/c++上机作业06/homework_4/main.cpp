#include"teacher.hpp"
#include"teacher.cpp"
#include"student.hpp"
#include"student.cpp"
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
void Show_title()
{
    cout<<"名字\t学分\t总成绩"<<endl;
}
int main ()
{
    teacher t[10];
    student s[10];
    cout<<"您需要建立几位学生(M)和几位教师(N)：";
    int m,n;
    cin>>m>>n;
    cout<<"请输入"<<m<<"位学生的姓名：";
    string tem_name;
    for(int i=0;i<m;i++)
    {
        cin>>tem_name;
        //cout<<'0'<<tem_name<<'0';
        s[i].change_name(tem_name);
    }
    cout<<"请输入"<<n<<"位老师的姓名：";
    for(int i=0;i<n;i++)
    {
        cin>>tem_name;
        //cout<<'0'<<tem_name<<'0';
        t[i].change_name(tem_name);
    }
    char flag;
    do
    {
        int teacher_th=-1,student_th=-1;
        string teacher_name,student_name;
        cout<<"请选择一位教师：";
        cin>>teacher_name;
        for(int i=0;i<n;i++)
        {
            if(strcmp(t[i].get_name().c_str(),teacher_name.c_str())==0)
            {
                teacher_th=i;
                cout<<"请选择一位学生：";
                cin>>student_name;
                for(int j=0;j<m;j++)
                {
                    if(strcmp(s[j].get_name().c_str(),student_name.c_str())==0)
                    {
                        student_th=j;
                        break;
                    }
                }
                break;
            }
        }
        if(teacher_th<0)
            cout<<"找不到老师名字。"<<endl;
        else if(student_th<0)
            cout<<"找不到学生名字。"<<endl;
        if(student_th>=0 && teacher_th >=0)
        {
            int credit,score;
            cout<<"请输入要增加的学分：";
            cin>>credit;
            t[teacher_th].change_credit(s[student_th],credit);

            cout<<"请输入要增加的总成绩：";
            cin>>score;
            t[teacher_th].change_score(s[student_th],score);
        }
        cout<<"还要继续吗？（Y/N）：";
        cin>>flag;
    }while(flag=='Y');

    Show_title();
    for(int i=0;i<m;i++)
    {
        s[i].Show();
    }
    return 0;
}
