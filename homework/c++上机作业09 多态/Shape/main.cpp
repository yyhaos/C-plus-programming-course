#include"shape.hpp"
#include"rectangle.hpp"
#include"circle.hpp"
#include"triangle.hpp"
#include<iostream>
#include<string>
using namespace std;

int main ()
{
    cout<<"你打算建立几个形状：(画布大小：80*40)";
    int n;
    cin>>n;
    Shape *s[150];
    for(int i=1;i<=n;i++)
    {
        cout<<endl;
        cout<<"请输入形状"<<char('0'+i)<<"（C--圆、R--矩形、T--三角形）：";
        char flag;
        cin>>flag;
        double x1,y1,x2,y2,x3,y3,x,y,r;
        switch(flag)
            {
            case 'C':
                cout<<"请输入圆心的坐标和半径：";
                cin>>x>>y>>r;
                s[i]=new Circle(x,y,r);
                cout<<"圆已经建立。"<<endl;
                break;
            case 'R':
                cout<<"请输入矩形对角的两个顶点的坐标：";
                cin>>x1>>y1>>x2>>y2;
                s[i]=new Rectangle(x1,y1,x2,y2);
                cout<<"矩形已经建立。"<<endl;
                break;
            case 'T':
                cout<<"请输入三角形三个顶点的坐标：";
                cin>>x1>>y1>>x2>>y2>>x3>>y3;
                s[i]=new Triangle(x1,y1,x2,y2,x3,y3);
                cout<<"三角形已经建立。"<<endl;
            }
    }
    cout<<"下面是"<<n<<"个形状的信息："<<endl;
    s[1]->ClearM();
    for(int i=1;i<=n;i++)
    {
        cout<<"形状"<<i<<"："<<endl;
        s[i]->GetInfo();
        s[i]->Draw();
    }
    s[1]->DrawM();
    return 0;
}
