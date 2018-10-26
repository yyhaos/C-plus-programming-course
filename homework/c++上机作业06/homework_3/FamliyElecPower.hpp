#pragma once
#include<string>
#include<fstream>
using namespace std;
class FamliyElecPower
{
private:
    int m_nID;
    string m_strFamliyName;
    int m_array[12];
    static int m_nCount;
public:
    FamliyElecPower(){}
    FamliyElecPower(string name,int *Array);
    void Show(ofstream& out);
    friend int CalTotalEPower(FamliyElecPower a);
    friend double CalAveEPower(FamliyElecPower a);
};
