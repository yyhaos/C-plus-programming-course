#include"mydate.h"
#include"mytime.h"
using namespace std;
class CMyDateTime:public CMyDate,public CMyTime
{
public:
    CMyDateTime(int year=2000,int month=1,int day=1,int hour=0,int minute=0,int second=0);
    void Set(int year,int month,int day,int hour,int minute,int second);
    void Next();
    void Display() const;
};
