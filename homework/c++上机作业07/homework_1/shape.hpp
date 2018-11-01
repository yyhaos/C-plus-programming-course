#pragma once
using namespace std;

class Shape
{
private:
    int x,y;
public:
    Shape();
    Shape(const int xx,const int yy);
    Shape(const Shape & a);
    ~Shape();
    void Move(const int xOff,const int yOff);
    void Set(const int xx,const int yy);
    void Display() const ;
    void Display2() const ;
};
class Rectangle:public Shape
{
private:
    int w,h;
public:
    Rectangle();
    Rectangle(const int xx,const int yy,const int ww,const int hh);
    Rectangle(const Rectangle &a);
    ~Rectangle();
    void Set(const int xx,const int yy,const int ww,const int hh);
    const float Area() const ;
    const float Circum() const ;
    void Display() const ;
};
class Circle:public Shape
{
private:
    int r;
public:
    Circle();
    Circle(const int xx,const int yy,const int rr);
    Circle(const Circle &a);
    ~Circle();
    void Set(const int xx,const int yy,const int rr);
    const float Area() const ;
    const float Circum() const ;
    void Display() const ;
};
