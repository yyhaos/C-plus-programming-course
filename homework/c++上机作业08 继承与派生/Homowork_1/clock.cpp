#include"Clock.hpp"
#pragma once
#include<iomanip>
#include<windows.h>
using namespace std;
Clock::Clock(int hour,int minute,int second)
{
    Hour=hour,Minute=minute,Second=second;
}
void Clock::ShowTime()
{
    cout<<setw(2)<<setfill('0')<<Hour<<":"<<setw(2)<<setfill('0')<<Minute<<":"<<setw(2)<<setfill('0')<<Second<<'\r';
}
void Clock::Tick()
{
    Sleep(1000);
    Second++;
    if(Second==60)
    {
        Second=0;
        Minute++;
        if(Minute==60)
        {
            Hour++;
            Minute=0;
            if(Hour==24)
            {
                Hour=0;
            }
        }
    }
}
void Clock::SetTime(int NewH,int NewM,int NewS)
{
    Hour=NewH,Minute=NewM,Second=NewS;
}


