#include<iostream>
#include<string>
using namespace std;

void Swap(int& a,int &b);
void Swap(float& a,float& b);
void Swap(string& a,string& b);
int main ()
{
    int a1,b1;
    float a2,b2;
    string a3,b3;

    cout<<"Please input 2 integers"<<endl;
    cin>>a1>>b1;
    Swap(a1,b1);
    cout<<a1<<" "<<b1<<endl;

    cout<<"Please input 2 floats"<<endl;
    cin>>a2>>b2;
    Swap(a2,b2);
    cout<<a2<<" "<<b2<<endl;

    cout<<"Please input 2 strings"<<endl;
    cin>>a3>>b3;
    Swap(a3,b3);
    cout<<a3<<" "<<b3<<endl;
    return 0;
}
void Swap(int& a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void Swap(float& a,float& b)
{
    float t=a;
    a=b;
    b=t;
}
void Swap(string& a,string& b)
{
    string t=a;
    a=b;
    b=t;
}
