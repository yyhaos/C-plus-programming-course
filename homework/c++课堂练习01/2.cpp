#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string str="c:/program files/microsof/vs2015";
    int pos=0;
    while(str.find("/")!=string::npos)
    {
        pos=str.find("/");
        str.replace(pos,1,"\\");
    }
    cout<<str<<endl;
    return 0;
}
