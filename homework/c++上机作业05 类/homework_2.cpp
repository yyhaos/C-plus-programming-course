#include<string.h>
#include<iostream>
using namespace std;
class Date
{
private:
    int year,month,day;
public:
    Date(int ,int ,int);
    Date();
    ~Date(void);
    void SetDate(int ,int,int);
    void Show();
};
class Person
{
    //class Date{};;
private:
    char * name;
    Date birthday;
    char gender;
public:
    Person(char *,int ,int ,int ,char );
    Person();
    ~Person();
    void SetName(char *);
    void SetBirthday(int ,int,int);
    void SetGender(char);
    char * GetName();
    Date GetBirthday();
    void Show();
};
Date::Date(){cout<<"Date类无参数构造函数调用完毕"<<endl;};
Date::Date(int y,int m,int d)
{
    year=y,month=m,day=d;
    cout<<"Date类含参数构造函数调用完毕"<<endl;
}
Date::~Date(void)
{
    cout<<"Date类析构函数调用完毕"<<endl;
}
void Date::SetDate(int y,int m,int d)
{
    year=y,month=m,day=d;
}
void Date::Show(void)
{
    cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}

Person::Person(){cout<<"Person类无参量构造函数调用完毕"<<endl;};
Person::Person(char * n,int y,int m,int d,char g)
{
    name=new char[strlen(n)+1];
    strcpy(name,n);
    birthday=Date(y,m,d);

    gender=g;
    cout<<"Person类含参量构造函数调用完毕"<<endl;
}

Person::~Person(void)
{
    delete name;
    cout<<"Person类析构函数调用完毕"<<endl;
}
void Person::SetName(char *n)
{
    if(name!=NULL)
        delete name;
    name=new char [strlen(n)+1];
    strcpy(name,n);
}
void Person::SetBirthday(int y,int m,int d)
{
    birthday.SetDate(y,m,d);
}
void Person::SetGender(char g)
{
    gender=g;
}
char * Person::GetName()
{
    return name;
}
Date Person::GetBirthday()
{
    return birthday;
}
void Person::Show()
{
    cout<<"Name:"<<name<<endl;
    cout<<"Birthday:";
    birthday.Show();
    cout<<"Gender:"<<gender<<endl;
}

int main ()
{
    cout<<"第一个人不使用参量构造"<<endl;
    Person a;
    a.SetName("yyhaos");
    a.SetBirthday(1997,11,22);
    a.SetGender('M');
    a.Show();

    cout<<"\n第二个人使用参量构造"<<endl;
    Person b("yyhaos_2",2024,1,1,'F');
    b.Show();

    cout<<"\n程序即将结束"<<endl;
    return 0;
}
