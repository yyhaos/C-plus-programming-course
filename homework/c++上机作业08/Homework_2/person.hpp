//#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#pragma once
class Person
{
private:
    string name;
    int age;
public:
    Person(string Name=" ",int Age=0);
    void SetName(string Name);
    string GetName();
    void SetAge(int Age);
    int GetAge();
};
