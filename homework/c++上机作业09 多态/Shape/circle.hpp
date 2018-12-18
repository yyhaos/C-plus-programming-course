#include"shape.hpp"
#include"point.hpp"
using namespace std;
#include<string>
#include<iostream>
class Circle:public Shape
{
private:
    Point P;
    double R;
public:
    const double PI=3.1415926535;
    Circle(double x,double y,double r):
        P(x,y),R(r){}
    virtual ~Circle(){}
    virtual void Show(){cout<<"Բ";}
    virtual double Area(){return R*R*PI;};
    virtual double Perimeter(){return 2.0*PI*R;}
    virtual void Draw()
    {
        for(int i=0;i<=Msize_y;i++)
            for(int j=0;j<=Msize_x;j++)
        {
            double xx=(i-P.x()),yy=(j-P.y());
            if(xx*xx+yy*yy<=R*R+1)
            {
                M[i][j]=1;
            }
        }
    }
};
