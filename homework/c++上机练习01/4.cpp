#include<bits/stdc++.h>
using namespace std;
int main ()
{
    cout<<"ʹ��\"\\t\"���������"<<endl;
    cout<<"һ\t��\t��\t��\t��\t��\t��"<<endl;
    for(int i=1;i<=5;i++)
        cout<<"\t";//������ʽҪ��
    for(int i=1;i<=30;i++)
    {
        if((i+5)%7==0)
            cout<<i<<endl;
        else
            cout<<i<<"\t";
    }

    //Ҳ����ʹ��setw()
    cout<<"ʹ��\"setw()\"���������"<<endl;
    int wid=8;// "\t" �Ŀ����8���ַ�
    cout<<"һ"<<setw(wid)<<"��"<<setw(wid)<<"��"
    <<setw(wid)<<"��"<<setw(wid)<<"��"<<setw(wid)<<"��"<<setw(wid)<<"��"<<endl;
    for(int i=1;i<=4;i++)
        cout<<setw(wid)<<"";//������ʽҪ�� ע��������ַ���""
    for(int i=1;i<=30;i++)
    {
        if((i+5)%7==0)
            cout<<setw(wid)<<i<<endl;
        else if((i+5)%7!=1)
            cout<<setw(wid)<<i;
        else
            cout<<i;
    }
    //���ڵ�һ�� ��Ҳ��֪��Ϊʲô���һ���ַ���λ

    return 0;
}
