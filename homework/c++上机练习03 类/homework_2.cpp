#include<iostream>
#include<iomanip>
using namespace std;
class Clock
{
    private:
        int hour,minute,second;
    public:
        void setTime(int newH,int newM,int newS);
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
void Clock::showTime()
{
    cout<<"时间是 "<<setw(2)<<setfill('0')<<hour<<":"
        <<setw(2)<<setfill('0')<<minute<<":"
        <<setw(2)<<setfill('0')<<second<<endl;
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
    int th,tm,ts;
    Clock tmp;
    char flag='Y';
    tmp.setTime(1,1,1);
    while(flag!='N')
    {
        cout<<"请输入时间（时 分 秒）：";
        cin>>th>>tm>>ts;
        tmp.setTime(th,tm,ts);

        tmp.showTime();
        cout<<"还要继续测试吗（Y/N）？";
        cin>>flag;
    }
    cout<<"程序结束了，再见！"<<endl;
    return 0;
}
