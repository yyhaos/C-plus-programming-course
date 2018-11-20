#include"person.hpp"
#include<string>

using namespace std;

Person::Person(string Name,int Age)
{
    name=Name,age=Age;
}
int Person::GetAge()
{
    return age;
}
string Person::GetName()
{
    return name;
}
void Person::SetAge(int Age)
{
    age=Age;
}
void Person::SetName(string Name)
{
    name=Name;
}
