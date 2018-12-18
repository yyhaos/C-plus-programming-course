#include"Course.hpp"
//#include"Course.cpp"
#pragma once
#include<iostream>
using namespace std;
Common::Common(const float english,const float chinese,const float mathmatic):
    English(english),Chinese(chinese),Mathmatic(mathmatic){}
const float Common::Average() const
{
    return Total()/3.0;
}
const float Common::Total() const
{
    return English+Mathmatic+Chinese;
}
void Common::Show() const
{
    cout<<"Common Total:"<<Total()<<"\tAverage:"<<Average()<<endl;
}

Accounting::Accounting(const float english,const float chinese,const float mathmatic,
               const float accountancy,const float economics):
    Common(english,chinese,mathmatic),
    Accountancy(accountancy),Economics(economics){}
const float Accounting::Average() const
{
    return Total()/5.0;
}
const float Accounting::Total() const
{
    return Common::Total()+Accountancy+Economics;
}
void Accounting::Show() const
{
    //Common::Show();
    cout<<"Accounting Total:"<<Total()<<"\tAverage:"<<Average()<<endl;
}
Chemistry::Chemistry(const float english,const float chinese,const float mathmatic,
                const float organicchemistry,const float chemicalanalysis):
    Common(english,chinese,mathmatic),
    OrganicChemistry(organicchemistry),ChemicalAnalysis(chemicalanalysis){}
const float Chemistry::Average() const
{
    return Total()/5.0;
}
const float Chemistry::Total() const
{
    return Common::Total()+OrganicChemistry+ChemicalAnalysis;
}
void Chemistry::Show() const
{
    //Common::Show();
    cout<<"Chemistry Total:"<<Total()<<"\tAverage:"<<Average()<<endl;
}

