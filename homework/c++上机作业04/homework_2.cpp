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
    cout<<"�޲ι��캯��������"<<endl;
}
CMoney::CMoney(int newY,int newJ,int newF)
{
    Fen=newF%10;
    newJ+=newF/10;
    Jiao=newJ%10;
    newY+=newJ/10;
    Yuan=newY;
    cout<<"�в������캯��������"<<endl;
}
CMoney::CMoney(const CMoney &p)
{
    Yuan=p.Yuan,Jiao=p.Jiao,Fen=p.Fen;
    cout<<"�������캯��������"<<endl;
}
CMoney::~CMoney()
{
    cout<<"��������������"<<endl;
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
    cout<<"�ܼ��� "<<Yuan<<"Ԫ"<<Jiao<<"��"<<Fen<<"��"<<endl;
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
    cout<<"ʹ���޲������춨��"<<endl;
    CMoney m;
    cout<<"\nʹ�ÿ������춨��"<<endl;
    CMoney m2=m;
    cout<<"\nʹ���в������춨��"<<endl;
    int ty,tj,tf;
    cout<<"����������Ԫ�Ƿ�"<<endl;
    cin>>ty>>tj>>tf;
    CMoney tmp(ty,tj,tf);
    tmp.Show();

    cout<<"\n������ͨ����"<<endl;
    CMoney m3;
    cout<<"\n����ָ��"<<endl;
    CMoney * pm = new CMoney;
    cout<<"\n��������"<<endl;
    CMoney money[5];

    cout<<"\n�������"<<endl;
    return 0;
}
