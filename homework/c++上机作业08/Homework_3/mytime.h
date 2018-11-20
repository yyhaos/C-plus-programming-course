#pragma once
using namespace std;
class CMyTime
{
private:
    int Hour,Minute,Second;
public:
    CMyTime(int hour=0,int minute=0,int second=0);
    void Set(int hour,int minute,int second);
    bool Next();
    void Display() const;
};
