
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string str;
    string target;
    cout<<"find how many target string in original string"<<endl;
    cout<<"input original string."<<endl;
    getline(cin,str);
    cout<<"input target string."<<endl;
    cin>>target;

    int cnt=0;
    int pos=0;
    while(str.length()<=0 ||pos=str.find(target)!=string::npos )
    {
        pos=str.find(target);
        cnt++;
        str.erase(pos,target.length());
    }

    cout<<str<<endl;
    cout<<"���С�"<<target<<"����"<<cnt<<"��."<<endl;

    delete str;
    delete target;
    return 0;
}
