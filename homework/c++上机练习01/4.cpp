#include<bits/stdc++.h>
using namespace std;
int main ()
{
    cout<<"使用\"\\t\"来控制输出"<<endl;
    cout<<"一\t二\t三\t四\t五\t六\t日"<<endl;
    for(int i=1;i<=5;i++)
        cout<<"\t";//日历格式要求
    for(int i=1;i<=30;i++)
    {
        if((i+5)%7==0)
            cout<<i<<endl;
        else
            cout<<i<<"\t";
    }

    //也可以使用setw()
    cout<<"使用\"setw()\"来控制输出"<<endl;
    int wid=8;// "\t" 的宽度是8个字符
    cout<<"一"<<setw(wid)<<"二"<<setw(wid)<<"三"
    <<setw(wid)<<"四"<<setw(wid)<<"五"<<setw(wid)<<"六"<<setw(wid)<<"日"<<endl;
    for(int i=1;i<=4;i++)
        cout<<setw(wid)<<"";//日历格式要求 注意输出空字符串""
    for(int i=1;i<=30;i++)
    {
        if((i+5)%7==0)
            cout<<setw(wid)<<i<<endl;
        else if((i+5)%7!=1)
            cout<<setw(wid)<<i;
        else
            cout<<i;
    }
    //对于第一行 我也不知道为什么会差一个字符空位

    return 0;
}
