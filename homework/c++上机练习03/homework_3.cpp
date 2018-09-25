#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

const int acc=20;   //���ٱ���
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
void Clock::tick(void)  //����ģ��ʱ�ӵĽ�λ
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
    cout<<"ʱ����"<<setw(2)<<setfill('0')<<hour<<":"
        <<setw(2)<<setfill('0')<<minute<<":"
        <<setw(2)<<setfill('0')<<second;//<<"  �����"<<acc<<"��"<<"\r";
    if(acc>1)
        cout<<"  �����"<<acc<<"��";
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
        cout<<"������ʱ�䣨ʱ �� �룩��";
        cin>>th>>tm>>ts;
        tmp.setTime(th,tm,ts);

        cout<<"���������ʱ�����֣���";
        cin>>addm;

        tmp.showTime();
        //cout<<endl;

        for(int i=1;i<=60*addm;i++)
        {
            Sleep(1000/acc);    //acc = ���ٱ���
            tmp.tick();
            tmp.showTime();
        }
        cout<<endl;

        cout<<"��Ҫ����������Y/N����";
        cin>>flag;
    }
    cout<<"��������ˣ��ټ���"<<endl;
    return 0;
}
