#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
template <class T>
T cmpValue(T a,T b)
{
    //cout<<"a:"<<a<<" b:"<<b<<endl;
    if(a>b)a=b;
    return a;
}

template <>
char * cmpValue(char * a,char * b)
{
    //cout<<"char* cmpValue\n";
    if(strcmp(a,b)>0)
        return b;
    return a;
}

template<class T>
void show(T a,T b)
{
    cout<<"max("<<a<<","<<b<<")="<<cmpValue(a,b)<<endl;
}

int main ()
{
    int a1(1),b1(2);
    show(a1,b1);

    float a2(3.0),b2(2.0);
    show(a2,b2);

    string a3("string1"),b3("string2");
    show(a3,b3);

    char a4[]="char1",b4[]="char2";
    show(a4,b4);

    return 0;
}
