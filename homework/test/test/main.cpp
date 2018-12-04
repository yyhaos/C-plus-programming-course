#include <iostream>
using namespace std;

class A{
private:
    int x;
public:

    A(int xx):x(xx){}

    A operator+(const A& b)const
    {
        return A(this->x + b.x);
    }
    friend ostream& operator<<(ostream& os,  A& a);
};

ostream& operator<<(ostream& os,  A& a)
    {
        os << a.x;
        return os;
    }
int main(void)
{
    A ojbA1(1), objA2(2);

    cout << ojbA1+objA2 << endl;
    cin.get();
    return 0;
}
