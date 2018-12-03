#include<iostream>
#include<string.h>
using namespace std;
struct Student//Student 结构 借鉴9.4
{	int id;
	float gpa;
    Student(int Id=0,int Gpa=0):id(Id),gpa(Gpa){}//最开始没有写默认参数 报错
    friend ostream& operator<<(ostream& os,const Student &a);
};
ostream& operator<<(ostream& os,const Student &a)//方便test()函数种的 cout<<top()
{
    os<<"ID:"<<a.id<<" GPA:"<<a.gpa<<" ";
    return os;
}
template<class T>//模板类stack声明
class stack
{
private:
    T* date;
    int top;
    int max_size;
public:
    stack();
    ~stack();
    stack(stack &a);
    bool empty();
    void push(T a);
    T pop();//有偏特化函数 string 类
    void resize(int new_max);
    int size();
    void show();
    T operator=(const T &b){//=运算符号直接写里面了 有偏特化函数
        delete date;
        top=b.top;
        date=new T[b.max_size];
        memcpy(date,b.date,sizeof(T)*(top+1));
        max_size=b.max_size;
        return *this;
    }
};

template<class T>//模板类的构造函数
stack<T>::stack():top(-1),max_size(50){
    date=new T[50];
}
template<class T>//模板类的析构函数
stack<T>::~stack(){delete date;}//注意new的对象要delete掉
template<class T>//模板类的引用构造函数
stack<T>::stack(stack &a)
{
    date=new T[a.max_size];
    for(int i=0;i<=a.top;i++)
    {
        date[i]=a.date[i];
    }
    top=a.top;
    max_size=a.max_size;
}
template<class T>//模板类的判断空函数
bool stack<T>::empty()
{
    if(top<0)
        return true;
    return false;
}
template<class T>//模板类的入站操作
void stack<T>::push(T a)
{
    if(top+1>=max_size)
    {
        resize(max_size+50);//栈大小不够要加大
    }
    date[top+1]=a;
    top++;
}
template<class T>//模板类的改变size的操作
void stack<T>::resize(int new_max)
{
    if(new_max<top+1)//太小了 要加大（也可以报错）
    {
        new_max=top+1;
    }
    T *tmp=new T[new_max];
    memcpy(tmp,date,sizeof(T)*(top+1));
    delete date;
    date=new T[new_max];
    memcpy(date,tmp,sizeof(T)*(top+1));
}
template <class T>//模板类的出栈操作
T stack<T>::pop()
{
    if(top<0)
        return  NULL;
    T ans(date[top]);
    top--;
    return ans;
}
//template <>//模板类的出栈操作 string特化
//string stack<string>::pop()
//{
//    if(top<0)
//        return "";
//    string ans(date[top]);
//    top--;
//    return ans;
//}
template<class T>//模板类的看大小函数
int stack<T>::size()
{
    return top+1;
}
template<class T>//模板类的show函数
void stack<T>::show()
{
    for(int i=0;i<=top;i++)
        cout<<date[i]<<" ";
    cout<<endl;
}
//operator = (T& a,T b)
template<class T>//自己的test函数
void test()
{
    stack<T> a;
    for(int i=100;i<=121;i++)
    {
        a.push((const T)i);//push 操作
    }
    a.show();
    cout<<a.pop()<<endl;//pop操作
    a.resize(1999);//重定义大小
    a.show();
    stack<T> b;
    b=a;//重新赋值操作
    b.show();
    cout<<endl;
}
string Test[5]={"123","234","345","456","567"};

template<>//test函数 string特化
void test<string>()
{
    stack<string> a;
    for(int i=0;i<5;i++)
        a.push(Test[i]);
    a.show();
    cout<<a.pop()<<endl;
    a.resize(1999);
    a.show();
    stack<string> b;
    b=a;
    b.show();
    cout<<endl;
}
Student Test2[5]={Student(1,90),Student(2,95),Student(3,100),Student(4,90),Student(5,95)};
template<>//Student特化  test函数
void test<Student>()
{
    stack<Student> a;
    for(int i=0;i<5;i++)
        a.push(Test2[i]);
    a.show();
    cout<<a.pop()<<endl;
    a.resize(1999);
    a.show();
    stack<Student> b;
    b=a;
    b.show();
    cout<<endl;
}
int main ()
{
    test<int>();
    test<double >();
    test<char>();
    test<string>();
    test<Student>();
    return 0;
}
