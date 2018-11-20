#include"shape.hpp"
#include"point.hpp"
using namespace std;
#include<string>
#include<math.h>
#include<iostream>
class Triangle:public Shape
{
private:
    Point p1,p2,p3;
public:
    double static dis(Point a1,Point a2){return sqrt((a1.x()-a2.x())*(a1.x()-a2.x())+(a1.y()-a2.y())*(a1.y()-a2.y()));}
    Triangle(double x1,double y1,double x2,double y2,double x3,double y3):
        p1(x1,y1),p2(x2,y2),p3(x3,y3){}
    virtual ~Triangle(){}
    virtual void Show(){cout<<"Èý½ÇÐÎ";}
    virtual double Area(){return 0.5*(p1.x()*p2.y()+p2.x()*p3.y()+p3.x()*p1.y()-p1.x()*p3.y()-p2.x()*p1.y()-p3.x()*p2.y());}
    virtual double Perimeter(){return dis(p1,p2)+dis(p2,p3)+dis(p1,p3);}
    virtual void Draw()
    {
        for(int i=0;i<=Msize_x;i++)
            for(int j=0;j<=Msize_y;j++)
        {
            if(Point(j,i).inTriangle(p1,p2,p3))
                if(i>=0 && i<=Msize_x && j>=0 && j<=Msize_y)
                    M[j][i]=3;
        }
    }
};
