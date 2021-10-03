#include<iostream>
#include<string>
using namespace std;

class Time
{
    private:
        int _hour, _minute, _second;
    public:
        Time(void)
        {
            _hour=_minute=_second=0;
        }
        void setTime(int hour, int minute, int second)
        {
            this->_hour=hour, this->_minute=minute, this->_second=second;
        }
        void addTime(Time &T1, Time &T2)
        {
            this->_hour=T1._hour+T2._hour;
            this->_minute=T1._minute+T2._minute;
            this->_second=T1._second+T2._second;
            
            this->_minute+=(this->_second/60);
            this->_second%=60;
            this->_hour+=(this->_minute/60);
            this->_minute%=60;
        }
        void showTime(void)
        {
            cout << "Time : " << _hour << ':' << _minute << ':' << _second; 
        }
};

int main(void)
{
    Time T1=Time(), T2=Time(), T3=Time();
    int hour, minute, second;
    
    cout << "hours: "; cin >> hour;
    cout << "minutes: "; cin >> minute;
    cout << "seconds: "; cin >> second;
    T1.setTime(hour, minute, second);
    
    cout << "hours: "; cin >> hour;
    cout << "minutes: "; cin >> minute;
    cout << "seconds: "; cin >> second;
    T2.setTime(hour, minute, second);

    T3.addTime(T1, T2);
    T3.showTime();
}