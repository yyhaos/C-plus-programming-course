//#pragma once
#include "Rice.hpp"
#include<string>

//using namespace std;
double Rice::TotalWeight=0; //±ØÐëÌí¼Ó
Rice::Rice(double weight,string place)
{
    Weight=weight;
    Place=place;
    TotalWeight+=weight;
}
Rice::Rice(const Rice& a)
{
    Weight=a.Weight;
    Place=a.Place;
    TotalWeight+=Weight;
}
Rice::~Rice()
{
    TotalWeight-=Weight;
}

//double Rice::GetTotal()
//{
//    return Rice::TotalWeight;
//}
