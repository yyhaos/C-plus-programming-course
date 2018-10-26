#include<iostream>
#include"Deposit.hpp"
#include"Deposit.cpp"
#include"Date.hpp"
#include"Date.cpp"
using namespace std;
void show_title()
{
    cout<<"�˺�\t"<<"����\t"<<"����\t"<<"���\t"<<"������\t"<<"����ʱ��\t"<<endl;
}
int main ()
{
    Deposit a[5]={ Deposit("����",123456,10000,0.005,Date(2017,3,1)),
                    Deposit("����",112233,20000,0.005,Date(2016,2,1)),
                    Deposit("����",111111,15000,0.005,Date(2017,5,1)),
                    Deposit("����",222222,58000,0.005,Date(2016,7,1)),
                    Deposit("����",888888,50000,0.005,Date(2017,3,1))};
    cout<<"��ʼ����"<<endl;
    show_title();
    for(int i=0;i<5;i++)
        a[i].check();

    cout<<"2017-7-1�գ�"<<endl;
    for(int i=0;i<5;i++)    //count past months of each deposit
    {
        int month_past=a[i].getDate().cha_month(Date(2017,7,1));
        a[i].month_past(month_past);
        //cout<<month_past<<endl;
    }
    show_title();
    for(int i=0;i<5;i++)
        a[i].check();
    cout<<endl;

    cout<<"2017-8-1�գ��޸�����"<<endl;
    Deposit::change_profit(0.004);
    cout<<endl;

    cout<<"2017-9-1�գ�"<<endl;
    for(int i=0;i<5;i++)    //count past months of each deposit
    {
        int month_past=Date(2017,9,1).cha_month(Date(2017,7,1));
        a[i].month_past(month_past);
        //cout<<month_past<<endl;
    }
    show_title();
    for(int i=0;i<5;i++)
        a[i].check();
    cout<<endl;

    cout<<"2017-10-1�գ�"<<endl;
    for(int i=0;i<5;i++)    //count past months of each deposit
    {
        int month_past=Date(2017,10,1).cha_month(Date(2017,9,1));
        a[i].month_past(month_past);
        //cout<<month_past<<endl;
    }
    show_title();
    for(int i=0;i<5;i++)
        a[i].check();
    cout<<endl;
}
