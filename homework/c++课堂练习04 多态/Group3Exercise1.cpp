//多项式硬核模拟
#include<iostream>
#include<string.h>
using namespace std;
const double eps=1e-10;
bool cmp(const double a,const double b)
{
    if((a-b)<eps && (b-a)<eps)
        return true;
    return false;
}
class Polynomial;
class term
{
    double coefficient;
    int exponent;
public:
    double get_coefficient(){return coefficient;}
    term(double c=0,int e=0):coefficient(c),exponent(e){
        if(cmp(c,0))
            e=0;
    }
    term(const term &tmp):coefficient(tmp.coefficient),
        exponent(tmp.exponent){}
    ~term(){};
    term operator *(const term& tmp) const {
        term a=term(coefficient*tmp.coefficient , exponent+tmp.exponent);
        return a;
    }
    friend class Polynomial;
    friend ostream& operator<<(ostream &os,const term& tmp);
    friend ostream & operator<<(ostream &os,const Polynomial& p);
};
ostream& operator<<(ostream &os,const term& tmp){//单个项输出 配合多项式输出使用 如1,2x,3x2,-4x(-1)
    if(cmp(tmp.coefficient,0))
        return os;
    if(tmp.exponent==0)
    {
        os<<tmp.coefficient;
        return os;
    }
    if(cmp(tmp.coefficient,1))
        os<<"x";
    else if(cmp(tmp.coefficient,-1))
        os<<"-x";
    else
        os<<tmp.coefficient<<"x";
    if(tmp.exponent>1)
        cout<<tmp.exponent;
    if(tmp.exponent<0)
        cout<<"("<<tmp.exponent<<")";
    return os;
}

class Polynomial
{
    term* data;
    int len;
    int capacity;
public:
    Polynomial(int n=0,term a[]=NULL){
        len=0;
        capacity=50;
        data=new term[capacity];
        for(int i=0;i<n;i++){
            Add(a[i]);
        }
        sort();
    }
    Polynomial(const Polynomial& tmp){
        len=tmp.len;
        delete data;
        data=new term[len];
        for(int i=0;i<len;i++)
        {
            data[i]=tmp.data[i];
        }
        sort();
    }
    ~Polynomial(){
        delete data;
    }
    void Add(term a){
        if(len+1<capacity)
            resize(capacity*2);
        data[len]=a;
        len++;
    }
    void resize(int newc){
        if(newc<len)
            newc=len;
        term* tmp=new term[newc];
        memcpy(tmp,data,sizeof(term)*len);
        delete data;
        data=new term[newc];
        memcpy(data,tmp,sizeof(term)*len);
        delete tmp;
    }
    void sort(){//多项式规范。包括去0项、去重复项、按次数排序
        int flag=1;
        for(int i=0;i<len;i+=flag){
            flag=1;
//            cout<<"i:"<<i<<endl;
//            for(int j=0;j<len;j++)
//            {
//                cout<<data[j].coefficient<<"x"<<data[j].exponent<<"+";
//            }
//            cout<<endl;
            while(cmp(data[i].coefficient,0) && i<len){
                data[i]=data[len-1];
                len--;
            }
            for(int j=i+1;j<len;j++){
                while(data[i].exponent==data[j].exponent && j<len){
                    data[i].coefficient+=data[j].coefficient;
                    data[j]=data[len-1];
                    len--;
                    flag=0;
                }
            }
            while(cmp(data[i].coefficient,0) && i<len && i>=0){
                data[i]=data[len-1];
                len--;
            }
        }
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++)
                if(data[i].exponent>data[j].exponent  && j<len){
                    term tmp=data[i];
                    data[i]=data[j];
                    data[j]=tmp;
                }
        }
    }
    friend ostream & operator<<(ostream &os,const Polynomial &p);
    Polynomial operator +(const Polynomial &p){
        term ans[p.len+len];
        for(int i=0;i<len;i++)
            ans[i]=data[i];
        for(int i=0;i<p.len;i++)
            ans[i+len]=p.data[i];
        return Polynomial(p.len+len,ans);
    }
    Polynomial operator -(const Polynomial &p){
        Polynomial tp(p);
        for(int i=0;i<p.len;i++){
            tp.data[i].coefficient*=-1.0;
        }
        return *this+tp;
    }
    Polynomial operator =(const Polynomial &p){
        delete data;
        data=new term[p.capacity];
        len=p.len;
        for(int i=0;i<len;i++){
            data[i]=p.data[i];
        }
        return p;
    }
    Polynomial operator *(const Polynomial & p){
        term ans[p.len*len];
        int cnt=0;
        for(int i=0;i<len;i++){
            for(int j=0;j<p.len;j++){
                ans[cnt++]=data[i]*p.data[j];
            }
        }
        return Polynomial(cnt,ans);
    }
    Polynomial operator +=(const Polynomial & p){
        Polynomial tmp(*this + p);
        *this=tmp;
        return tmp;
    }
    Polynomial operator -=(const Polynomial & p){
        Polynomial tmp(*this - p);
        *this=tmp;
        return tmp;
    }
    Polynomial operator *=(const Polynomial & p){
        Polynomial tmp( (*this) * p);
        *this=tmp;
        return tmp;
    }
};
ostream & operator <<(ostream &os ,const  Polynomial &p){//多项式输出
    int len=p.len;
    if(len==0)
        os<<"0";
    else
        for(int i=0;i<len;i++){
            if(i!=0 && p.data[i].get_coefficient()>eps)//连接的+号
                cout<<"+";
            cout<<p.data[i];//项输出
        }
    //cout<<p.len<<" ";
    return os;
}
int main ()
{
//    term a1[]={term(1,1),term(2,2),term(3,3)};
//    term a2[]={term(1,-1),term(2,0),term(-3,3),term(3,2),term(123124,1234)};
    term a1[]={term(1,0),term(1,1)};
    Polynomial p1(2,a1);
    Polynomial p2;

//    cout << p1 += p2 <<endl;//error
    cout << (p1+=p2) <<endl;//ok

    cout << p1 + p2 <<endl;//ok
    cout << (p1+p2) <<endl;//ok
   // Polynomial p2(5,a2);
  // int a=0;
  // cout<<a+=2<<endl;
    cout<<p1<<endl;
    //cout<<"1"<<endl;
    cout<<p1*p1<<endl;
    cout<<p1-p1<<endl;
    p2=p1;
    //cout<<p1+=p2<<endl;
    cout<<(p1+=p2)<<endl;
    cout<<p1<<endl;
    cout<<p2<<endl;

    p1*=p2;
    cout<<p1<<endl;

    return 0;
}
