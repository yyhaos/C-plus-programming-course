#include"Clock.hpp"
#include"alarm.hpp"
#include<iostream>
using namespace std;
int main ()
{
    int hour=0,minute=0,second=0,Ahour=0,Aminute=0,go_hour=0,go_minute=2,go_second=15;
    while(1)
    {
        cout<<"输入当前时间 按照 \"时 分 秒\"格式： （当输入负数时程序结束）"<<endl;
        cin>>hour;
        if(hour<0)
            break;
        cin>>minute;
        if(minute<0)
            break;
        cin>>second;
        if(second<0)
            break;
        cout<<"输入闹钟时间 按照 \"时 分\"格式："<<endl;
        cin>>Ahour>>Aminute;
        cout<<"输入持续时间 按照 \"时 分 秒\"格式："<<endl;
        cin>>go_hour>>go_minute>>go_second;
        AlarmClock a(hour,minute,second,Ahour,Aminute);

        int total_second=60*60*go_hour+60*go_minute+go_second;
        cout<<"当前时间为"<<hour<<":"<<minute<<":"<<second
            <<"，闹钟时间为"<<Ahour<<":"<<Aminute
            <<"，时长为"<<go_hour<<":"<<go_minute<<":"<<go_second<<" 共计"<<total_second<<"秒"<<endl;


        while(total_second--)
        {
            a.Tick();
            a.ShowTime();
        }
        //a.ShowTime();

        //cout<<"闹钟时间为00:00:00,时长00:02:15"<<endl;
    }
    return 0;
}
