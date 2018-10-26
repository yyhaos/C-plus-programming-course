#pragma once
#include<string>
using namespace std;
class Rice
{
private:
    double Weight;
    string Place;
    static double TotalWeight;
public:
    Rice(double weight=0,string place="XXX");
    Rice(const Rice&);
    ~Rice();
    static double GetTotal(){return TotalWeight;};
};
