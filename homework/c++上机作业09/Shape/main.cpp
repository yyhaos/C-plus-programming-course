#include"shape.hpp"
#include"rectangle.hpp"
#include"circle.hpp"
#include"triangle.hpp"
#include<iostream>
#include<string>
using namespace std;

int main ()
{
    cout<<"����㽨��������״��(������С��80*40)";
    int n;
    cin>>n;
    Shape *s[150];
    for(int i=1;i<=n;i++)
    {
        cout<<endl;
        cout<<"��������״"<<char('0'+i)<<"��C--Բ��R--���Ρ�T--�����Σ���";
        char flag;
        cin>>flag;
        double x1,y1,x2,y2,x3,y3,x,y,r;
        switch(flag)
            {
            case 'C':
                cout<<"������Բ�ĵ�����Ͱ뾶��";
                cin>>x>>y>>r;
                s[i]=new Circle(x,y,r);
                cout<<"Բ�Ѿ�������"<<endl;
                break;
            case 'R':
                cout<<"��������ζԽǵ�������������꣺";
                cin>>x1>>y1>>x2>>y2;
                s[i]=new Rectangle(x1,y1,x2,y2);
                cout<<"�����Ѿ�������"<<endl;
                break;
            case 'T':
                cout<<"������������������������꣺";
                cin>>x1>>y1>>x2>>y2>>x3>>y3;
                s[i]=new Triangle(x1,y1,x2,y2,x3,y3);
                cout<<"�������Ѿ�������"<<endl;
            }
    }
    cout<<"������"<<n<<"����״����Ϣ��"<<endl;
    s[1]->ClearM();
    for(int i=1;i<=n;i++)
    {
        cout<<"��״"<<i<<"��"<<endl;
        s[i]->GetInfo();
        s[i]->Draw();
    }
    s[1]->DrawM();
    return 0;
}
