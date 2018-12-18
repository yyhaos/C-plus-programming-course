#include<iostream>
#include<string.h>
using namespace std;
int main ()
{
    cout<<char (int('A')^int('z'))<<endl;   //ÆÆÒëÓÃ£ºÓÃ·¨¼ûÐÄµÃÌå»á5
    string c1="(-(*$\"1-421-42(-(*$\"1";    //½«"AAAAAAAAAAAAAAAAAAAAAAAAAAAAA"µÄ½á¹ûÕ³ÌùÖÁÕâÀï¡£×¢Òâ×ªÒå×Ö·û!
    string c2="      ";  //½«"bbbbbbbbbbbbbbbbbbbbbbbbbbbb"µÄ½á¹ûÕ³ÌùÖÁÕâÀï¡£ ¿Õ¸ñÊÇk^bµÄ½á¹û
    string c3="JOJHF@SOVPSOVPJOJHF@SOVPS";   //½«"#########################"µÄ½á¹ûÕ³ÌùÖÁÕâÀï¡£
    string key="";
    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;
    cout<<"c3: "<<c3<<endl;
    cout<<"key:";
    for(int i=0;c1[i] && c2[i] && c3[i];i++)
        key[i]=c1[i]^c2[i]^c3[i],cout<<key[i];
    return 0;
}
