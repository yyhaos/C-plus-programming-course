#include<iostream>
using namespace std;

typedef struct Student
{	string department;		//ϵ��
    char gender;			//�Ա�: ��-��m��,Ů-��f��
    int num;				//ѧ��
    string name;			//����
} STUDENT;

STUDENT InputStudent(int num1=2017001,string de="Computer",string namel="XXX",char g='m');
int main ()
{
    STUDENT stu[6];
    stu[0]=InputStudent(2017001,"Computer","��ΰ",'m');
    stu[1]=InputStudent(2017002,"Mathematics","������",'f');
    stu[2]=InputStudent(2017003,"Computer","������",'m');
    stu[3]=InputStudent(2016085,"Physical","������",'m');
    stu[4]=InputStudent(2017009,"Computer","�ڶ�÷",'f');
    stu[5]=InputStudent(2016007,"Computer","����ɽ",'m');
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
