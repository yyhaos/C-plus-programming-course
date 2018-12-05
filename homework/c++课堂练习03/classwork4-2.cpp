#include <iostream>
#include <string.h>
using namespace std;
class Clock {
private:
	int hour, minute, second;
	char *caption;   //指向保存时区说明的字符串。
public:
	void setHour(int h) { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSecond(int s) { second = s; }
    void setCaption(char* cs);
    void dispTime() {
		std::cout << "Now is: ";
        std::cout << hour << ":" << minute << ":" << second;
        std::cout << std::endl;
    }
	char* getCaption() { return caption; }
	void Destroy() { delete[]caption; }
	Clock(const Clock& p);
	Clock();
};

Clock::Clock(const Clock& p)
{
    hour=p.hour,minute=p.minute,second=p.second;
    caption = new char[strlen(p.caption)+1];
    strcpy(caption,p.caption);
}

Clock::Clock()
{

}

void Clock::setCaption(char* cs) {
    int len = strlen(cs);
    caption = new char[len + 1];
    strcpy(caption, cs);
}

int main(void){
    Clock aClock;
    aClock.setMinute(12);
    aClock.setHour(16);
    aClock.setSecond(27);
    aClock.setCaption("From Beijing Time.");
    Clock bClock = aClock;
    aClock.Destroy();
    bClock.dispTime();
    std::cout << bClock.getCaption() << std::endl;
    return 0;
}
