#include"Course.hpp"
#include"Course.cpp"
#include<iostream>
using namespace std;
int main ()
{
    cout<<"��ѧרҵ���ɼ��ֱ�Ϊ�����Σ�1��2��3 רҵ�Σ�4��5�ֵ�ѧ����"<<endl;
    Chemistry p1(1,2,3,4,5);    //��ѧרҵ
    p1.Common::Show();  //�����ε��ܳɼ���ƽ���ɼ�
    p1.Show();  //���пγ̵��ܳɼ���ƽ���ɼ�

    cout<<"���רҵ���ɼ��ֱ�Ϊ�����Σ�6��7��8 רҵ�Σ�9��10�ֵ�ѧ����"<<endl;
    Accounting p2(6,7,8,9,10);  //���רҵ
    p2.Common::Show();
    p2.Show();

    return 0;
}
