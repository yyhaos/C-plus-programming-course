#pragma once
using namespace std;
class Common
{
private:
    float English,Chinese,Mathmatic;
public:
    Common(const float english,const float chinese,const float mathmatic);
    Common(){};
    const float Average() const ;
    const float Total() const ;
    void Show() const ;
};
class Accounting:public Common
{
private:
    float Accountancy,Economics;
public:
    Accounting(const float english,const float chinese,const float mathmatic,
               const float accountancy,const float economics);
    Accounting(){};
    const float Average() const ;
    const float Total() const ;
    void Show()const ;
};
class Chemistry :public Common
{
private:
    float OrganicChemistry,ChemicalAnalysis;
public:
    Chemistry(const float english,const float chinese,const float mathmatic,
                const float organicchemistry,const float chemicalanalysis);
    Chemistry(){};
    const float Average() const ;
    const float Total() const ;
    void Show() const ;
};
