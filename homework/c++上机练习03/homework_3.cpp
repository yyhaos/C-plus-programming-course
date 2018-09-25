#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

const int acc=20;   //加速倍数
class Clock
{
    private:
        int hour,minute,second;
    public:
        void setTime(int newH,int newM,int newS);
        void tick();
        void showTime();
        int getHour();
        int getMinute();
        int getSecond();
};
void Clock::setTime(int newH,int newM,int newS)
{
    hour=newH;
    minute=newM;
    second=newS;
    return;
}
void Clock::tick(void)  //必须模拟时钟的进位
{
    second++;
    if(second>=60)
    {
        second=0;
        minute++;
        if(minute>=60)
        {
            minute=0;
            hour++;
            if(hour>=24)
            {
                hour=0;
            }
        }
    }
    return;
}
void Clock::showTime()
{
    cout<<"时间是"<<setw(2)<<setfill('0')<<hour<<":"
        <<setw(2)<<setfill('0')<<minute<<":"
        <<setw(2)<<setfill('0')<<second;//<<"  快进了"<<acc<<"倍"<<"\r";
    if(acc>1)
        cout<<"  快进了"<<acc<<"倍";
    cout<<"\r";
}
int Clock::getHour()
{
    return hour;
}
int Clock::getMinute()
{
    return minute;
}
int Clock::getSecond()
{
    return second;
}
int main ()
{
    int th,tm,ts,addm;
    Clock tmp;
    char flag='Y';
    tmp.setTime(1,1,1);
    while(flag!='N')
    {
        cout<<"请输入时间（时 分 秒）：";
        cin>>th>>tm>>ts;
        tmp.setTime(th,tm,ts);

        cout<<"请输入测试时长（分）：";
        cin>>addm;

        tmp.showTime();
        //cout<<endl;

        for(int i=1;i<=60*addm;i++)
        {
            Sleep(1000/acc);    //acc = 加速倍数
            tmp.tick();
            tmp.showTime();
        }
        cout<<endl;

        cout<<"还要继续测试吗（Y/N）？";
        cin>>flag;
    }
    cout<<"程序结束了，再见！"<<endl;
    return 0;
}
