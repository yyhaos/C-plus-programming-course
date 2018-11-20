#pragma once
const int Msize_x=80;
const int Msize_y=40;
#include<iostream>
using namespace std;
class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    void GetInfo()
    {
        cout<<"这是一个";
        Show();
        cout<<endl<<"它的面积是"<<Area()<<endl;
        cout<<"它的周长是"<<Perimeter()<<endl;
    }
    static int M[Msize_y+1][Msize_x+1];
    virtual void Draw()=0;
    virtual void Show()=0;
    virtual double Area()=0;
    virtual double Perimeter()=0;
    void ClearM()
    {
        for(int i=0;i<=Msize_y;i++)
            for(int j=0;j<=Msize_x;j++)
        {
            M[i][j]=0;
        }
    }
    void DrawM()
    {
        for(int i=Msize_y;i>=0;i--)
        {
            for(int j=0;j<=Msize_x;j++)
            {
                switch(M[i][j])
                {
                case 0:
                    cout<<'+';break;
                case 1:
                    cout<<'C';break;
                case 2:
                    cout<<'R';break;
                case 3:
                    cout<<'T';break;
                }
            }
            cout<<endl;
        }
    }
};
int Shape::M[Msize_y+1][Msize_x+1]={0};
