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
    cout<<"����\tѧ��\t�ܳɼ�"<<endl;
}
int main ()
{
    teacher t[10];
    student s[10];
    cout<<"����Ҫ������λѧ��(M)�ͼ�λ��ʦ(N)��";
    int m,n;
    cin>>m>>n;
    cout<<"������"<<m<<"λѧ����������";
    string tem_name;
    for(int i=0;i<m;i++)
    {
        cin>>tem_name;
        //cout<<'0'<<tem_name<<'0';
        s[i].change_name(tem_name);
    }
    cout<<"������"<<n<<"λ��ʦ��������";
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
        cout<<"��ѡ��һλ��ʦ��";
        cin>>teacher_name;
        for(int i=0;i<n;i++)
        {
            if(strcmp(t[i].get_name().c_str(),teacher_name.c_str())==0)
            {
                teacher_th=i;
                cout<<"��ѡ��һλѧ����";
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
            cout<<"�Ҳ�����ʦ���֡�"<<endl;
        else if(student_th<0)
            cout<<"�Ҳ���ѧ�����֡�"<<endl;
        if(student_th>=0 && teacher_th >=0)
        {
            int credit,score;
            cout<<"������Ҫ���ӵ�ѧ�֣�";
            cin>>credit;
            t[teacher_th].change_credit(s[student_th],credit);

            cout<<"������Ҫ���ӵ��ܳɼ���";
            cin>>score;
            t[teacher_th].change_score(s[student_th],score);
        }
        cout<<"��Ҫ�����𣿣�Y/N����";
        cin>>flag;
    }while(flag=='Y');

    Show_title();
    for(int i=0;i<m;i++)
    {
        s[i].Show();
    }
    return 0;
}
