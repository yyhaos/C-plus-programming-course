#include<iostream>
#include<math.h>
using namespace std;
const double INF=1e18;
class Number
{
private:
    double n1,n2;
public:
    Number(double a=0,double b=0);
    double addition(void);
    double subtration(void);
    double multipalication(void);
    double division(void);
};
Number::Number(double a,double b)
{
    n1=a;
    n2=b;
}
double Number::addition(void)
{
    return n1+n2;
}
double Number::subtration(void)
{
    return n1-n2;
}
double Number::multipalication(void)
{
    return n1*n2;
}
double Number::division(void)
{
    if(fabs(n2)<=0.0001)
        return INF;
    //cout<<" chu"<<endl;
    return n1/n2;
}
int main ()
{
    Number a(2,3);
    cout<<"相加:"<<a.addition()<<endl;
    cout<<"相减:"<<a.subtration()<<endl;
    cout<<"相乘:"<<a.multipalication()<<endl;
    cout<<"相除:"<<a.division()<<endl;
    return 0;
}
