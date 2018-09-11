
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    enum balls{red,yellow,blue,white,black};
    string colors[5]={"ºì","»Æ","À¶","°×","ºÚ"};
    //enum balls{"ºì","»Æ","À¶","°×","ºÚ"};
    for(int i=red;i<black;i++)
        for(int j=red;j<black;j++)
            for(int k=red;k<black;k++)
            {
                if(i==j || j==k || i==k)
                    continue;
                cout<<colors[i]<<colors[j]<<colors[k]<<endl;
            }
    return 0;
}
