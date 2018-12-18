#include <iostream>
#include<string.h>
using namespace std;

template<class T>
void myswap(T *x, T *y)
{
   //cout<<"T swap"<<endl;
    T temp = *x;
    *x = *y;
    *y = temp;
}
template<>
void myswap(char x[5], char y[5])
{
    //cout<<"char* swap"<<endl;
    char * temp=new char[5];
    strcpy(temp,x);
    strcpy(x,y);
    strcpy(y,temp);
}

template <class T>
void mysort(T* a,int n)
{
    //cout<<"T* sort"<<endl;
    for (int i=0;i<n-1;i++)
    {
        int leastindex=i;
        for(int j=i+1;j<n;j++)
            if(a[j] < a[leastindex])
                leastindex = j;
        myswap(a+i,a+leastindex);
    }
}
template <>
void mysort(char a[5][5],int n)
{
    //cout<<"char* sort"<<endl;
    for (int i=0;i<n-1;i++)
    {
        int leastindex=i;
        for(int j=i+1;j<n;j++)
            if(strcmp(a[j],a[leastindex])<0)
                leastindex = j;
        myswap(a[i], a[leastindex]);
    }
}

template<class T>
void show(T a,int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main ()
{
    int a[]={1,5,2,4,3};
    char b[][5]={"234","123","456","qwe","asd"};
    string c[5]={"123","234","qwe","456","asd"};

    mysort(a,5);
    show(a,5);

    mysort(b,5);
    show(b,5);

    mysort(c,5);
    show(c,5);

    return 0;
}
