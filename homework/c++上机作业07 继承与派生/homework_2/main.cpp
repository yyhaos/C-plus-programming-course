#include"Course.hpp"
#include"Course.cpp"
#include<iostream>
using namespace std;
int main ()
{
    cout<<"化学专业，成绩分别为公共课：1，2，3 专业课：4，5分的学生："<<endl;
    Chemistry p1(1,2,3,4,5);    //化学专业
    p1.Common::Show();  //公共课的总成绩、平均成绩
    p1.Show();  //所有课程的总成绩、平均成绩

    cout<<"会计专业，成绩分别为公共课：6，7，8 专业课：9，10分的学生："<<endl;
    Accounting p2(6,7,8,9,10);  //会计专业
    p2.Common::Show();
    p2.Show();

    return 0;
}
