#include<iostream>
#include<string>
#include<ostream>
#include<istream>
#pragma once
using namespace std;
class RMB
{
private:
    char flag;
    int Yuan,Jiao,Fen;
public:
    RMB(char fl,int y,int j,int f=0);
    RMB(char fl,int tot=0);
    RMB(int tot=0);
    int tot();
    void trans(int total);
    RMB operator +(RMB &b);
    RMB operator -(RMB &b);
    RMB operator ++();
    RMB operator ++(int);
    friend RMB operator --(RMB &a);
    friend RMB operator --(RMB &a,int);
    friend ostream& operator << (ostream& os,const RMB& tm);
    friend istream& operator >> (istream& is,RMB& tm);
};
