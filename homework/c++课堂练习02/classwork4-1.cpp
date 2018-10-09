#include <iostream>
using std::cout;
using std::endl;

class Desk {
public:
	void setWeight(int w) { weight = w; }
	void printInfo();
    Desk(int newwei,int newlen,int newwid,int newhei);
    Desk();
private:
	int weight, length, width, height;
};

Desk::Desk(int newwei,int newlen,int newwid,int newhei)
{
    weight=newwei,length=newlen,width=newwid,height=newhei;
    //return; //?
}

Desk::Desk()
{

}

void Desk:: printInfo() {
    cout << "Desk weight: " << weight << endl;
	cout << "Desk length: " << length << endl;
	cout << "Desk width: " << width << endl;
	cout << "Desk height: " << height << endl;
}

int main(void) {
	Desk d(2, 3, 3, 5);
	d.printInfo();
    Desk da[10];

	for (int i = 0; i < 10; i++)
		da[i].printInfo();
	return 0;
}

