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
        cout<<"����������ʱ��ֵ���� �� �� ʱ �� �룩��"<<endl;
        cin>>year>>month>>day>>hour>>minute>>second;
        CMyDateTime a(year,month,day,hour,minute,second);

        cout<<"���ڵ�����ʱ��ֵ�ǣ�";
        a.Display();
        cout<<endl;
        a.Next();
        cout<<"��һ������ʱ��ֵ�ǣ�";
        a.Display();
        cout<<endl;
        cout<<"�����𣿣�Y/N����"<<endl;
        cin>>flag;
        if(flag!='Y')
            break;
    }

    return 0;
}
