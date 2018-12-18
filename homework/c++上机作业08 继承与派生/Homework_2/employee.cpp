#include"Employee.hpp"
#include<string>
using namespace std;
Employee::Employee(string Name,int Age,string Department,int ID):
    Person(Name,Age),department(Department),EmployeeID(ID){}

void Employee::SetDepartment(string Department)
{
    department=Department;
}
string Employee::GetDepartment()
{
    return department;
}
void Employee::SetEmployeeID(int ID)
{
    EmployeeID=ID;
}
int Employee::GetEmployeeID()
{
    return EmployeeID;
}

