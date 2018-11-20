#pragma once
using namespace std;
class Point
{
private:
    double X,Y;
public:
    double x(){return X;}
    double y(){return Y;}
    Point (double x,double y):X(x),Y(y){}
    double CrossProduct(Point a)
    {
        return X*a.y() - Y*a.x();
    }
    bool inTriangle(Point a,Point b,Point c)
    {
        Point PA=Point(a.x()-X,a.y()-Y);
        Point PB=Point(b.x()-X,b.y()-Y);
        Point PC=Point(c.x()-X,c.y()-Y);
        double t1=PA.CrossProduct(PB);
        double t2=PB.CrossProduct(PC);
        double t3=PC.CrossProduct(PA);
        return t1*t2>0 && t1*t3>0;
    }
};
