#include<iostream>
#include<string.h>
using namespace std;
int main ()
{
    cout<<char (int('A')^int('z'))<<endl;   //�����ã��÷����ĵ����5
    string c1="(-(*$\"1-421-42(-(*$\"1";    //��"AAAAAAAAAAAAAAAAAAAAAAAAAAAAA"�Ľ��ճ�������ע��ת���ַ�!
    string c2="      ";  //��"bbbbbbbbbbbbbbbbbbbbbbbbbbbb"�Ľ��ճ������� �ո���k^b�Ľ��
    string c3="JOJHF@SOVPSOVPJOJHF@SOVPS";   //��"#########################"�Ľ��ճ�������
    string key="";
    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;
    cout<<"c3: "<<c3<<endl;
    cout<<"key:";
    for(int i=0;c1[i] && c2[i] && c3[i];i++)
        key[i]=c1[i]^c2[i]^c3[i],cout<<key[i];
    return 0;
}
