#include<iostream>
#include<string.h>
using namespace std;
struct Student//Student �ṹ ���9.4
{	int id;
	float gpa;
    Student(int Id=0,int Gpa=0):id(Id),gpa(Gpa){}//�ʼû��дĬ�ϲ��� ����
    friend ostream& operator<<(ostream& os,const Student &a);
};
ostream& operator<<(ostream& os,const Student &a)//����test()�����ֵ� cout<<top()
{
    os<<"ID:"<<a.id<<" GPA:"<<a.gpa<<" ";
    return os;
}
template<class T>//ģ����stack����
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
    T pop();//��ƫ�ػ����� string ��
    void resize(int new_max);
    int size();
    void show();
    T operator=(const T &b){//=�������ֱ��д������ ��ƫ�ػ�����
        delete date;
        top=b.top;
        date=new T[b.max_size];
        memcpy(date,b.date,sizeof(T)*(top+1));
        max_size=b.max_size;
        return *this;
    }
};

template<class T>//ģ����Ĺ��캯��
stack<T>::stack():top(-1),max_size(50){
    date=new T[50];
}
template<class T>//ģ�������������
stack<T>::~stack(){delete date;}//ע��new�Ķ���Ҫdelete��
template<class T>//ģ��������ù��캯��
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
template<class T>//ģ������жϿպ���
bool stack<T>::empty()
{
    if(top<0)
        return true;
    return false;
}
template<class T>//ģ�������վ����
void stack<T>::push(T a)
{
    if(top+1>=max_size)
    {
        resize(max_size+50);//ջ��С����Ҫ�Ӵ�
    }
    date[top+1]=a;
    top++;
}
template<class T>//ģ����ĸı�size�Ĳ���
void stack<T>::resize(int new_max)
{
    if(new_max<top+1)//̫С�� Ҫ�Ӵ�Ҳ���Ա���
    {
        new_max=top+1;
    }
    T *tmp=new T[new_max];
    memcpy(tmp,date,sizeof(T)*(top+1));
    delete date;
    date=new T[new_max];
    memcpy(date,tmp,sizeof(T)*(top+1));
}
template <class T>//ģ����ĳ�ջ����
T stack<T>::pop()
{
    if(top<0)
        return  NULL;
    T ans(date[top]);
    top--;
    return ans;
}
//template <>//ģ����ĳ�ջ���� string�ػ�
//string stack<string>::pop()
//{
//    if(top<0)
//        return "";
//    string ans(date[top]);
//    top--;
//    return ans;
//}
template<class T>//ģ����Ŀ���С����
int stack<T>::size()
{
    return top+1;
}
template<class T>//ģ�����show����
void stack<T>::show()
{
    for(int i=0;i<=top;i++)
        cout<<date[i]<<" ";
    cout<<endl;
}
//operator = (T& a,T b)
template<class T>//�Լ���test����
void test()
{
    stack<T> a;
    for(int i=100;i<=121;i++)
    {
        a.push((const T)i);//push ����
    }
    a.show();
    cout<<a.pop()<<endl;//pop����
    a.resize(1999);//�ض����С
    a.show();
    stack<T> b;
    b=a;//���¸�ֵ����
    b.show();
    cout<<endl;
}
string Test[5]={"123","234","345","456","567"};

template<>//test���� string�ػ�
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
template<>//Student�ػ�  test����
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
