#include<iostream>
using namespace std;

class Rect
{
    private:
        double length,width;
    public:
        void Set(double l,double w);
        double Area();
};

void Rect::Set(double l,double w)
{
    length=l;
    width=w;
    return;
}

double Rect::Area()
{
    return length*width;
}

int main ()
{
    double tl,tw;
    Rect tmp;
    cout<<"Please input length and width."<<endl;
    cin>>tl>>tw;
    tmp.Set(tl,tw);
    cout<<"The area of this rectangle is "<<tmp.Area()<<"."<<endl;
    return 0;
}
