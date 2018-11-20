#include"mydatetime.h"
#include<iostream>
using namespace std;
int main ()
{
    freopen("test.txt","r",stdin);
    int year,month,day,hour,minute,second;
    char flag;
    while(1)
    {
        cout<<"请输入日期时间值（年 月 日 时 分 秒）："<<endl;
        cin>>year>>month>>day>>hour>>minute>>second;
        CMyDateTime a(year,month,day,hour,minute,second);

        cout<<"现在的日期时间值是：";
        a.Display();
        cout<<endl;
        a.Next();
        cout<<"下一个日期时间值是：";
        a.Display();
        cout<<endl;
        cout<<"继续吗？（Y/N）："<<endl;
        cin>>flag;
        if(flag!='Y')
            break;
    }

    return 0;
}
