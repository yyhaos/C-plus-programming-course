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
        cout<<"ѧ����ְ��Ա����ϵͳ��"<<endl;
        cout<<"������ѧ��������";
        cin>>name;
        cout<<"������ѧ�����䣺";
        cin>>age;
        cout<<"������ѧ��רҵ��";
        cin>>major;
        cout<<"������ѧ��ѧ�ţ�";
        cin>>stu_id;
        cout<<"������ѧ�����ţ�";
        cin>>work_id;
        cout<<"������ѧ��Ժϵ��";
        cin>>departement;

        StudentEmployee a(name,age,major,stu_id,departement,work_id);
        cout<<"�������ѧ����ְ��Ա��Ϣ���£�"<<endl;
        cout<<"������"<<a.GetName()<<endl;
        cout<<"���䣺"<<a.GetAge()<<endl;
        cout<<"רҵ��"<<a.GetMajor()<<endl;
        cout<<"ѧ�ţ�"<<a.GetStudentID()<<endl;
        cout<<"���ţ�"<<a.GetEmployeeID()<<endl;
        cout<<"Ժϵ��"<<a.GetDepartment()<<endl;

        cout<<"��Ҫ�����𣿣�Y/N����"<<endl;
        char flag;
        cin>>flag;
        if(flag=='N')
            break;
    }
    return 0;
}
