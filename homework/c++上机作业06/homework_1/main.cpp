#include<iostream>
#include "Rice.hpp"
#include "Rice.cpp"
using namespace std;
int main ()
{
    cout<<"�ʼ���������ǣ�"<<Rice::GetTotal()<<endl;
    Rice a(10,"10kg");
    cout<<"�ú�����10kg����a���׺���������ǣ�"<<Rice::GetTotal()<<endl;
    Rice b(a);
    cout<<"������a���׵Ĺ��캯������b���׺���������ǣ�"<<Rice::GetTotal()<<endl;
    Rice c;
    cout<<"��Ĭ�ϵĹ��캯������c���׺���������ǣ�"<<Rice::GetTotal()<<endl;
    return 0;
}
