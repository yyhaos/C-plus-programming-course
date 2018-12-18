#pragma once
#include<iostream>
class Clock
{
private:
    int Hour,Minute,Second;
public:
    Clock(int hour,int minute,int second);
    void ShowTime();
    void Tick();
    void SetTime(int NewH,int NewM,int NewS);
    friend class AlarmClock;
};


