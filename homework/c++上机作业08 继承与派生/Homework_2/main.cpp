#include<string>
#include"employee.hpp"
#include"student.hpp"
#include"studentemployee.hpp"
#include"person.hpp"
#include<iostream>
using namespace std;

int main ()
{
    while(1)
    {
        string name,major,departement;
        int age,stu_id,work_id;
        cout<<"学生兼职人员输入系统："<<endl;
        cout<<"请输入学生姓名：";
        cin>>name;
        cout<<"请输入学生年龄：";
        cin>>age;
        cout<<"请输入学生专业：";
        cin>>major;
        cout<<"请输入学生学号：";
        cin>>stu_id;
        cout<<"请输入学生工号：";
        cin>>work_id;
        cout<<"请输入学生院系：";
        cin>>departement;

        StudentEmployee a(name,age,major,stu_id,departement,work_id);
        cout<<"您输入的学生兼职人员信息如下："<<endl;
        cout<<"姓名："<<a.GetName()<<endl;
        cout<<"年龄："<<a.GetAge()<<endl;
        cout<<"专业："<<a.GetMajor()<<endl;
        cout<<"学号："<<a.GetStudentID()<<endl;
        cout<<"工号："<<a.GetEmployeeID()<<endl;
        cout<<"院系："<<a.GetDepartment()<<endl;

        cout<<"还要继续吗？（Y/N）："<<endl;
        char flag;
        cin>>flag;
        if(flag=='N')
            break;
    }
    return 0;
}
