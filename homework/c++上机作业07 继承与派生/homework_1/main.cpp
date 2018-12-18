#include"shape.hpp"
#include<iostream>
#include"shape.cpp"
using namespace std;
int main ()
{
    //Shape a(1,1);
    Rectangle R1(2,2,3,4);

    cout<<"R1："<<endl;
    R1.Display();

    cout<<"R1向右平移3向上平移4后："<<endl;
    R1.Move(3,4);
    R1.Display();

    Circle C1(1,2,3);

    cout<<"C1："<<endl;
    //cout<<"C1："<<endl;
    C1.Display();

    cout<<"C2："<<endl;
    Circle C2(C1);
    C2.Display();

    cout<<"C2向右平移3向上平移4后："<<endl;
    C2.Move(3,4);
    C2.Display();

    Circle Cs[3];
    Cs[0].Set(0,0,1);
    Cs[1].Set(1,1,2);
    Cs[2].Set(5,5,5);

    for(int i=0;i<=2;i++)
    {
        cout<<"Cs["<<i<<"]："<<endl;
        Cs[i].Display();
    }

    return 0;
}
