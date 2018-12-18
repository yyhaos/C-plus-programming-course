#include"shape.hpp"
#include"point.hpp"
using namespace std;
#include<string>
#include<math.h>
#include<iostream>
class Rectangle:public Shape
{
private:
    Point p1,p2;
public:
    Rectangle(double x1,double y1,double x2,double y2):
        p1(x1,y1),p2(x2,y2){}
    virtual ~Rectangle(){}
    virtual void Show(){cout<<"¾ØÐÎ";}
    virtual double Area(){return fabs((p2.x()-p1.x())*(p2.y()-p1.y()));}
    virtual double Perimeter(){return 2.0*(fabs(p2.x()-p1.x())+fabs(p2.y()-p1.y()));}
    virtual void Draw()
    {
        for(int i=p1.x();i<=p2.x();i++)
        {
            for(int j=p1.y();j>=p2.y();j--)
            {
                if(i>=0 && i<=Msize_x && j>=0 && j<=Msize_y)
                    M[j][i]=2;
            }
        }
    }
};
