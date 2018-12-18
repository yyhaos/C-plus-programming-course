#include<iostream>
#include<iomanip>
using namespace std;
class CMoney
{
    private:
        int Yuan,Jiao,Fen;
    public:
        void SetValue(int newY,int newJ,int newF);
        void Show();
        int GetYuan();
        int GetJiao();
        int GetFen();
        CMoney();
        CMoney(int newY,int newJ,int newF);
        CMoney(const CMoney&p);
        ~CMoney();
};
CMoney::CMoney()
{
    Yuan=0,Jiao=0,Fen=0;
    cout<<"无参构造函数被调用"<<endl;
}
CMoney::CMoney(int newY,int newJ,int newF)
{
    Fen=newF%10;
    newJ+=newF/10;
    Jiao=newJ%10;
    newY+=newJ/10;
    Yuan=newY;
    cout<<"有参数构造函数被调用"<<endl;
}
CMoney::CMoney(const CMoney &p)
{
    Yuan=p.Yuan,Jiao=p.Jiao,Fen=p.Fen;
    cout<<"拷贝构造函数被调用"<<endl;
}
CMoney::~CMoney()
{
    cout<<"析构函数被调用"<<endl;
}
void CMoney::SetValue(int newY,int newJ,int newF)
{
    Yuan=newY;
    Jiao=newJ;
    Fen=newF;
    return;
}
void CMoney::Show()
{
    cout<<"总价是 "<<Yuan<<"元"<<Jiao<<"角"<<Fen<<"分"<<endl;
    return;
}
int CMoney::GetYuan()
{
    return Yuan;
}
int CMoney::GetJiao()
{
    return Jiao;
}
int CMoney::GetFen()
{
    return Fen;
}

int main ()
{
    cout<<"使用无参数构造定义"<<endl;
    CMoney m;
    cout<<"\n使用拷贝构造定义"<<endl;
    CMoney m2=m;
    cout<<"\n使用有参数构造定义"<<endl;
    int ty,tj,tf;
    cout<<"请依次输入元角分"<<endl;
    cin>>ty>>tj>>tf;
    CMoney tmp(ty,tj,tf);
    tmp.Show();

    cout<<"\n定义普通变量"<<endl;
    CMoney m3;
    cout<<"\n定义指针"<<endl;
    CMoney * pm = new CMoney;
    cout<<"\n定义数组"<<endl;
    CMoney money[5];

    cout<<"\n程序结束"<<endl;
    return 0;
}
