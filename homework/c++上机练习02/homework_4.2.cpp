#include<iostream>
#include<string.h>
using namespace std;
int main ()
{
    cout<<char (int('A')^int('z'))<<endl;   //破译用：用法见心得体会5
    string c1="(-(*$\"1-421-42(-(*$\"1";    //将"AAAAAAAAAAAAAAAAAAAAAAAAAAAAA"的结果粘贴至这里。注意转义字符!
    string c2="      ";  //将"bbbbbbbbbbbbbbbbbbbbbbbbbbbb"的结果粘贴至这里。 空格是k^b的结果
    string c3="JOJHF@SOVPSOVPJOJHF@SOVPS";   //将"#########################"的结果粘贴至这里。
    string key="";
    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;
    cout<<"c3: "<<c3<<endl;
    cout<<"key:";
    for(int i=0;c1[i] && c2[i] && c3[i];i++)
        key[i]=c1[i]^c2[i]^c3[i],cout<<key[i];
    return 0;
}
