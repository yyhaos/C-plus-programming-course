#include"clock.hpp"
#pragma once
class AlarmClock:public Clock
{
private:
    int AHour,AMinute;
public:
    AlarmClock(int hour,int minute,int second,int ahour,int aminute);
    void Alarm();
    void SetAlarmTime(int ahour,int aminute);
    void Tick();
};
