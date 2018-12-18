#include<iostream>
#include<string.h>
using namespace std;

const string key="ilikecplusplus";

void encode(void);
int main ()
{
    encode();
    return 0;
}
void encode()
{
    string str;
    //char str[10000];
    cin>>str;
    for(int i=0;str[i];)
    {
        for(int j=0;key[j] && str[i];j++,i++)
        {
            cout<<str[i]<<"->";
            str[i]=str[i]^key[j];
            cout<<str[i]<<endl;
        }
    }
    cout<<"Encode: ";
    cout<<str<<endl;

    for(int i=0;str[i];)
        for(int j=0;key[j] && str[i];j++,i++)
            str[i]=str[i]^key[j];
    cout<<"Decode: "<<str<<endl;
    return ;
}
