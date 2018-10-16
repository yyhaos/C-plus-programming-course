#include<iostream>
using namespace std;

class Fraction
{
private:
    int num,den;
public:
    Fraction(int n =0,int d=1);
    void Standerdize(void);
    int GCD(void);
    void Set(int ,int );
    void Display();
    Fraction Add(Fraction x);
    Fraction Sub(Fraction x);
    Fraction Mul(Fraction x);
    Fraction Div(Fraction x);
    bool BigOrEqual(Fraction);
};
Fraction::Fraction(int n,int d)
{
    num=n;
    den=d;
    Standerdize();
}
void Fraction::Standerdize(void)
{
    int gcd=GCD();
    num/=gcd;
    den/=gcd;
    if(den<0)
    {
        den*=-1;
        num*=-1;
    }
}
void Fraction::Display()
{
    cout<<num;
    if(den!=1)
        cout<<"/"<<den<<endl;
    else
        cout<<endl;
}
int Fraction::GCD ()
{
    int td,n=num,d=den;
    while(d!=0)
    {
        td=d;
        d=n%d;
        n=td;
    }
    return n;
}
void Fraction::Set(int a,int b)
{
    num=a;
    den=b;
    Standerdize();
}
Fraction Fraction::Add(Fraction x)
{
    Fraction ans;
    ans.den=den*x.den;
    ans.num=num*x.den+x.num*den;
    ans.Standerdize();
    return ans;
}
Fraction Fraction::Sub(Fraction x)
{
    Fraction ans;
    ans.den=den*x.den;
    ans.num=num*x.den-x.num*den;
    ans.Standerdize();
    return ans;
}
Fraction Fraction::Mul(Fraction x)
{
    Fraction ans;
    ans.den=den*x.den;
    ans.num=num*x.num;
    ans.Standerdize();
    return ans;
}
Fraction Fraction::Div(Fraction x)
{
    if(x.num==0)
    {
        cout<<"除数不能为0"<<endl;
        return *this;
    }
    else
    {
        Fraction ans;
        ans.num=num*x.den;
        ans.den=den*x.num;
        ans.Standerdize();
        return ans;
    }
}
bool Fraction::BigOrEqual(Fraction x)
{
    Standerdize();
    x.Standerdize();
    int n1=num*x.den;
    int n2=x.num*den;
    if(n1<n2)   //<
        return false;
    return true;    //>=
}
int main ()
{
    Fraction a,b,c(4,-6),d,e,f,g;
    //cout<<c.GCD();
    a.Set(1,2);
    cout<<"a=";
    a.Display();

    b.Set(3,4);
    cout<<"b=";
    b.Display();

    cout<<"c=4/-6=";
    c.Display();

    d=a.Add(b);
    cout<<"d=a+b=";
    d.Display();

    e=a.Sub(b);
    cout<<"e=a-b=";
    e.Display();

    f=a.Mul(b);
    cout<<"e=a*b=";
    f.Display();

    g=a.Div(b);
    cout<<"e=a/b=";
    g.Display();

    cout<<"a>=b ? "<<a.BigOrEqual(b)<<endl;
    return 0;
}
