#include<iostream>
#include<math.h>
using namespace std;
const double eps=1e-6;

/*
因为浮点数比较时有不太精确的现象，特别是判断相等时，
所以采用sig函数来辅助判断
*/
int sig(double a)
{
    if(a>eps)
        return 1;
    else if(a<-eps)
        return -1;
    else
        return 0;
}

string type_name[5]={"一般三角形","等腰三角形","等边三角形",
    "直角三角形","等腰直角三角形"};

class Triangle
{
private:
    double a,b,c;
public:
    Triangle(double na=1,double nb=1,double nc=1);
    void SetValue(double na,double nb,double nc);
    bool Isok(void);    //合法三角形
    bool Isiso(void);   //等腰三角形
    bool Isequ(void);   //等边三角形
    bool Isrig(void);   //直角三角形
    bool Isisorig(void);//等腰直角三角形
    int type(void); //判断类型 1~4 按顺序对应上面各类三角形 共4个
    double Perimeter(void);
    double Area(void);
};

Triangle::Triangle(double na,double nb,double nc)
{
    a=na,b=nb,c=nc;
}

void Triangle::SetValue(double na,double nb,double nc)
{
    a=na,b=nb,c=nc;
}

bool Triangle::Isok(void)
{
    if(sig(a) & sig(b) & sig(c))
    {
        //printf("1\n");
        if(sig(a+b-c)==1 && sig(a+c-b)==1 && sig(c+b-a)==1)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Triangle::Isiso(void)
{
    if(Isok()==false)
        return false;
    if(sig(a-c)==0 || sig(a-b)==0 || sig(c-b==0))
        return true;
    else
        return false;
}

bool Triangle::Isequ(void)
{
    if(Isok()==false)
        return false;
    if(sig(a-c)==0 && sig(a-b)==0 && sig(c-b==0))
        return true;
    else
        return false;
}

bool Triangle::Isrig(void)
{
    if(Isok()==false)
        return false;
    if(sig(a*a+b*b-c*c)==0 || sig(a*a+c*c-b*b)==0 ||
       sig(c*c+b*b-a*a)==0)
    {
        return true;
    }
    return false;
}

bool Triangle::Isisorig(void)
{
    if(Isiso() && Isrig())
        return true;
    return false;
}

int Triangle::type(void)
{
    if(Isisorig())
        return 4;
    if(Isrig())
        return 3;
    if(Isequ())
        return 2;
    if(Isiso())
        return 1;
    return 0;
}

double Triangle::Perimeter(void)
{
    return a+b+c;
}

double Triangle::Area(void)
{
    double hp=Perimeter()/2;
    return sqrt(hp*(hp-a)*(hp-b)*(hp-c));
}

int main ()
{
    double ta,tb,tc;
    cout<<"请输入三个边长"<<endl;
    cin>>ta>>tb>>tc;

    Triangle tmp(ta,tb,tc);
    if(tmp.Isok())
    {
        cout<<"类型:"<<type_name[tmp.type()]<<endl;
        cout<<"周长:"<<tmp.Perimeter()<<endl;
        cout<<"面积:"<<tmp.Area()<<endl;
    }
    else
    {
        cout<<"不是正确的三角形"<<endl;
    }

    return 0;
}
