#include<iostream>
#include "Rice.hpp"
#include "Rice.cpp"
using namespace std;
int main ()
{
    cout<<"最开始的总重量是："<<Rice::GetTotal()<<endl;
    Rice a(10,"10kg");
    cout<<"用含参数10kg创建a大米后的总重量是："<<Rice::GetTotal()<<endl;
    Rice b(a);
    cout<<"用引用a大米的构造函数创建b大米后的总重量是："<<Rice::GetTotal()<<endl;
    Rice c;
    cout<<"用默认的构造函数创建c大米后的总重量是："<<Rice::GetTotal()<<endl;
    return 0;
}
