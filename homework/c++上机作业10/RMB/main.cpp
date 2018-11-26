#include<iostream>
#include"RMB.hpp"
using namespace std;
/*
+11 22 33
+9 8 18

-1 2 33
+5 7 8
*/
int main ()
{
    char en='1';
    while(en!='N')
    {
        cout<<"请构造两个人民币："<<endl;
        RMB a,b,c;
        cin>>a;cin>>b;
        int cnt=6;
        while(cnt--)
        {
            cout<<"请选择运算(A:+/S:-/Q:++i/H:i++/J:--i/K:i--/): "<<endl;
            char F;
            cin>>F;
            switch (F)
            {
            case 'A':
                cout<<a<<"+"<<b<<"="<<a+b;
                break;
            case 'S':
                cout<<a<<"-"<<b<<"="<<a-b;
                break;
            case 'Q':
                cout<<"++"<<a;
                cout<<"="<<++a;
                cout<<" 人民币1:"<<a;
                break;
            case 'H':
                cout<<a<<"++=";
                cout<<a++;
                cout<<" 人民币1:"<<a;
                break;
            case 'J':
                cout<<"--"<<a;
                cout<<"="<<--a;
                cout<<" 人民币1:"<<a;
                break;
            case 'K':
                cout<<a<<"--";
                cout<<"="<<a--;
                cout<<" 人民币1:"<<a;
                break;

            }
            cout<<endl;
        }
        cout<<"还要继续吗？（Y/N）：";
        cin>>en;
    }


    return 0;
}
