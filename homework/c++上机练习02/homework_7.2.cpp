#include<iostream>
using namespace std;
void Sort3IntReference(int& a,int& b,int& c);
void Swap(int& a,int &b);
int main ()
{
    int a,b,c;
    cout<<"������3��������";
    cin>>a>>b>>c;
    Sort3IntReference(a,b,c);
    cout<<"���մ�С��������ǣ�"<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}
void Sort3IntReference(int& a,int& b,int& c)
{
    if(a>b)
        Swap(a,b);
    if(b>c)
        Swap(b,c);
    if(a>b)
        Swap(a,b);
}
void Swap(int& a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
