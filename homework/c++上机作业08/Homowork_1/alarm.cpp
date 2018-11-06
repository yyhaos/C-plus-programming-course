#include"alarm.hpp"
#include<iostream>
using namespace std;
#pragma once
AlarmClock::AlarmClock(int hour,int minute,int second,int ahour,int aminute):Clock(hour,minute,second)
{
    AHour=ahour,AMinute=aminute;
}
void AlarmClock::Alarm()
{
    cout<<"beep!\t";
    cout<<'\7'<<'\7'<<'\7';
}
void AlarmClock::SetAlarmTime(int ahour,int aminute)
{
    AHour=ahour,AMinute=aminute;
}
void AlarmClock::Tick()
{
    Clock::Tick();
    if(Clock::Hour==AHour && Clock::Minute==AMinute)
        Alarm();
}

