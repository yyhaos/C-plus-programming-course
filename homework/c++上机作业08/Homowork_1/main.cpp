#include"Clock.hpp"
#include"alarm.hpp"
#include<iostream>
using namespace std;
int main ()
{
    int hour=0,minute=0,second=0,Ahour=0,Aminute=0,go_hour=0,go_minute=2,go_second=15;
    while(1)
    {
        cout<<"���뵱ǰʱ�� ���� \"ʱ �� ��\"��ʽ�� �������븺��ʱ���������"<<endl;
        cin>>hour;
        if(hour<0)
            break;
        cin>>minute;
        if(minute<0)
            break;
        cin>>second;
        if(second<0)
            break;
        cout<<"��������ʱ�� ���� \"ʱ ��\"��ʽ��"<<endl;
        cin>>Ahour>>Aminute;
        cout<<"�������ʱ�� ���� \"ʱ �� ��\"��ʽ��"<<endl;
        cin>>go_hour>>go_minute>>go_second;
        AlarmClock a(hour,minute,second,Ahour,Aminute);

        int total_second=60*60*go_hour+60*go_minute+go_second;
        cout<<"��ǰʱ��Ϊ"<<hour<<":"<<minute<<":"<<second
            <<"������ʱ��Ϊ"<<Ahour<<":"<<Aminute
            <<"��ʱ��Ϊ"<<go_hour<<":"<<go_minute<<":"<<go_second<<" ����"<<total_second<<"��"<<endl;


        while(total_second--)
        {
            a.Tick();
            a.ShowTime();
        }
        //a.ShowTime();

        //cout<<"����ʱ��Ϊ00:00:00,ʱ��00:02:15"<<endl;
    }
    return 0;
}
