#include "shape.hpp"
#pragma once
#include<iostream>
using namespace std;
const float PI=3.1415926535;

Shape::Shape():
    x(0),y(0){}
Shape::Shape(const int xx,const int yy):
    x(xx),y(yy){}
Shape::Shape(const Shape & a):
    x(a.x),y(a.y){}
Shape::~Shape(){};
void Shape::Move(const int xOff,const int yOff)
{
    x+=xOff,y+=yOff;
}
void Shape::Set(const int xx,const int yy)
{
    x=xx,y=yy;
}
void Shape::Display() const
{
    cout<<"Shape("<<x<<","<<y<<")"<<endl;
}
void Shape::Display2() const
{
    cout<<"("<<x<<","<<y<<")";
}

Rectangle::Rectangle():
    w(0),h(0),
    Shape(0,0){}
Rectangle::Rectangle(const int xx,const int yy,const int ww,const int hh):
    w(ww),h(hh),
    Shape(xx,yy){}
Rectangle::Rectangle(const Rectangle & a):
    w(a.w),h(a.h),
    Shape(a){}
Rectangle::~Rectangle(){};
void Rectangle::Set(const int xx,const int yy,const int ww,const int hh)
{
    Shape::Set(xx,yy);
    w=ww,h=hh;
}
const float Rectangle::Area() const
{
    return 1.0*w*h;
}
const float Rectangle::Circum() const
{
    return 2.0*w+2.0*h;
}
void Rectangle::Display() const
{
    cout<<"Rectangle(";
    Shape::Display2();
    cout<<w<<","<<h<<"),Area="<<Area()<<",Circum="<<Circum()<<endl;
}

Circle::Circle():
    r(0),
    Shape(0,0){}
Circle::Circle(const int xx,const int yy,const int rr):
    r(rr),
    Shape(xx,yy){}
Circle::Circle(const Circle & a):
    r(a.r),
    Shape(a){}
Circle::~Circle(){};
void Circle::Set(const int xx,const int yy,const int rr)
{
    r=rr;
    Shape::Set(xx,yy);
}
const float Circle::Area() const
{
    return 1.0*PI*r*r;
}
const float Circle::Circum() const
{
    return 2.0*PI*r;
}
void Circle::Display() const
{
    cout<<"Circle(";
    Shape::Display2();
    cout<<r<<"),Area="<<Area()<<",Circum="<<Circum()<<endl;
}

