#include<iostream>
using namespace std;

typedef struct Student
{	string department;		//系别
    char gender;			//性别: 男-‘m’,女-‘f’
    int num;				//学号
    string name;			//姓名
} STUDENT;

STUDENT InputStudent(int num1=2017001,string de="Computer",string namel="XXX",char g='m');
int main ()
{
    STUDENT stu[6];
    stu[0]=InputStudent(2017001,"Computer","王伟",'m');
    stu[1]=InputStudent(2017002,"Mathematics","刘海华",'f');
    stu[2]=InputStudent(2017003,"Computer","赵天瑞",'m');
    stu[3]=InputStudent(2016085,"Physical","胡文明",'m');
    stu[4]=InputStudent(2017009,"Computer","于冬梅",'f');
    stu[5]=InputStudent(2016007,"Computer","岳海山",'m');
    for(int i=0;i<6;i++)
        cout<<stu[i].department<<"\t"<<stu[i].gender<<"\t"<<stu[i].num<<"\t"<<stu[i].name<<endl;
    return 0;
}

STUDENT InputStudent(int num1,string de,string namel,char g)
{
    STUDENT tmp;
    tmp.name=namel;
    tmp.department=de;
    tmp.num=num1;
    tmp.gender=g;
    return tmp;
}
