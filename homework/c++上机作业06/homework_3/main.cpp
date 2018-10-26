#include"FamliyElecPower.hpp"
#include"FamliyElecPower.cpp"
#include<fstream>
#include<iostream>
#include<random>
using namespace std;
FamliyElecPower NewUser(ifstream& in,ofstream& out)
{
    string name;
    int k[12];
    cout<<"请输入用户名称：";
    in>>name;
    cout<<name<<endl;
    if(in.eof())
        return FamliyElecPower();
    cout<<"请分别输入12个月的电量：";
    for(int i=0;i<12;i++)
    {
        in>>k[i];
        cout<<k[i]<<" ";
    }
    cout<<endl;
    FamliyElecPower New(name,k);
    New.Show(out);
    return New;
}
int main ()
{
    //freopen("in.txt","r",stdin);
    ofstream pre_in("in.txt");
    for(int i=1;i<=100;i++)
    {
        int name_len=rand()%4+4+rand()%2;
        pre_in<<char('A'+rand()%26);
        for(int i=2;i<=name_len;i++)
            pre_in<<char('a'+rand()%26);

        for(int j=0;j<12;j++)
            pre_in<<" "<<rand()%200;
        pre_in<<endl;
    }
    pre_in.close();

    ifstream in("in.txt");
    ofstream out("out.txt");
    //out.open;

    while(in.eof()==false)
        NewUser(in,out);

    cout<<"输出在out.txt文件里"<<endl;
    in.close();
    out.close();
    return 0;
}
