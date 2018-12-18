#include"FamliyElecPower.hpp"
#include<iostream>
#include<fstream>
using namespace std;

int FamliyElecPower::m_nCount=0;
FamliyElecPower::FamliyElecPower(string name,int *Array)
{
    m_nCount++;
    m_nID=m_nCount;
    m_strFamliyName=name;
    for(int i=0;i<12;i++)
        m_array[i]=Array[i];
}
int CalTotalEPower(FamliyElecPower a)
{
    int sum=0;
    for(int i=0;i<12;i++)
        sum+=a.m_array[i];
    return sum;
}
double CalAveEPower(FamliyElecPower a)
{
    return CalTotalEPower(a)/12.0;
}

void FamliyElecPower::Show(ofstream& out)
{
    out<<"�û��õ���Ϣ�ǣ�"<<endl;
    out<<"��ţ�"<<m_nID<<"\t���ƣ�"<<m_strFamliyName<<endl;
    out<<"12���µ��õ�����";
    for(int i=0;i<12;i++)
        out<<m_array[i]<<" ";
    out<<endl;
    out<<"���ܵ�����"<<CalTotalEPower(*this)<<"\t��ƽ��������"<<CalAveEPower(*this)<<"\t"<<endl;
}
