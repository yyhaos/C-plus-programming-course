#pragma once
using namespace std;
class Date
{
private:
    int year,month,day;
public:
    Date(int ,int ,int);
    Date();
    ~Date(void);
    void SetDate(int ,int,int);
    void Show();
    int cha_month(Date b);
};
