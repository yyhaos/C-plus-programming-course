#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
#define all(a) a.begin(),a.end()

template<class T, class Tr>
void myTransform(T st,T ed,Tr tr)
{
    for(T i = st ; i!=ed ; i++)
    {
        tr(*i);
    }
}

template<class T>
void show(T st,T ed)
{
    for(T i=st ; i!=ed;i++)
    {
        cout<<*i;
        if(i!=ed-1)
            cout<<" ";
    }
    cout<<endl;
}

template<class T>
class F1
{
private:
    T offset;
public:
    F1(T a=0):
        offset(a){}
    void operator () (T & a)
    {
        a+=offset;
    }
};

class F2
{
public:
    F1(){}
    void operator () (char &a)
    {
        if(a>='a' && a<='z')
            a+='A'-'a';
    }
};
int main ()
{
//    vector<int> ta;
//    for(int i=0;i<=10;i++)
//        ta[i]=i;    //error
    vector<int> a;
    for(int i=1;i<=10;i++)
        a.push_back(i);
//    vector<int> a(10);
//    for(int i=1;i<=10;i++)
//        a[i-1]=i;
    show(a.begin(),a.end());
    F1<int> fun1(10);
    myTransform(a.begin(),a.end(),fun1);
    //myTransform(a.begin(),a.end(),F1<int>(10));
    //myTransform(a.begin(),a.end(),F1(10));  // error
    show(a.begin(),a.end());

    string b="abcABC";
    cout<<b<<endl;
    myTransform(b.begin(),b.end(),F2());
    cout<<b<<endl;
    return 0;
}
