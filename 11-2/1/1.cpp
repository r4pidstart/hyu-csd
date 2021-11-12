#include<iostream>
#include<string>
using namespace std;

class MyInt;
class MyDouble;

class MyInt
{
    private:
        int num;
    public:
        MyInt(int n):num(n){}
        int getNum(void)
        {
            return num;
        }
        void show(void)
        {
            cout << num;
        }
        MyInt& operator=(MyInt& a)
        {
            num=a.num;
            return *this;
        }
        friend MyInt operator-(MyInt& a, MyInt& b);
        friend MyInt operator+(MyInt& a, MyInt& b);
        friend MyInt operator*(MyInt& a, MyInt& b);
        friend MyInt operator/(MyInt& a, MyInt& b);
        friend ostream& operator<<(ostream& os, MyInt& a);
        friend ostream& operator<<(ostream& os, MyInt&& a);
        friend MyDouble operator+(MyDouble& a, MyInt& b);
        friend MyDouble operator-(MyDouble& a, MyInt& b);
        friend MyDouble operator*(MyDouble& a, MyInt& b);
        friend MyDouble operator/(MyDouble& a, MyInt& b);
        friend MyDouble operator+(MyInt& a, MyDouble& b);
        friend MyDouble operator-(MyInt& a, MyDouble& b);
        friend MyDouble operator*(MyInt& a, MyDouble& b);
        friend MyDouble operator/(MyInt& a, MyDouble& b);
};

class MyDouble
{
    private:
        double num;
    public:
        MyDouble(double n):num(n){}
        double getNum(void)
        {
            return num;
        }
        void show(void)
        {
            cout << num;
        }
        MyDouble& operator=(MyDouble& a)
        {
            num=a.num;
            return *this;
        }
        friend ostream& operator<<(ostream& os, MyDouble& a);
        friend ostream& operator<<(ostream& os, MyDouble&& a);
        friend MyDouble operator+(MyDouble& a, MyDouble& b); 
        friend MyDouble operator-(MyDouble& a, MyDouble& b); 
        friend MyDouble operator*(MyDouble& a, MyDouble& b);
        friend MyDouble operator/(MyDouble& a, MyDouble& b);
        friend MyDouble operator+(MyDouble& a, MyInt& b);
        friend MyDouble operator-(MyDouble& a, MyInt& b);
        friend MyDouble operator*(MyDouble& a, MyInt& b);
        friend MyDouble operator/(MyDouble& a, MyInt& b);
        friend MyDouble operator+(MyInt& a, MyDouble& b);
        friend MyDouble operator-(MyInt& a, MyDouble& b);
        friend MyDouble operator*(MyInt& a, MyDouble& b);
        friend MyDouble operator/(MyInt& a, MyDouble& b);
};

ostream& operator<<(ostream& os, MyInt& a) { os << a.num; return os; }
ostream& operator<<(ostream& os, MyInt&& a) { os << a.num; return os; }
ostream& operator<<(ostream& os, MyDouble& a) { os << a.num; return os; }
ostream& operator<<(ostream& os, MyDouble&& a) { os << a.num; return os; }

MyInt operator-(MyInt& a, MyInt& b) { return MyInt(a.num-b.num); }
MyInt operator+(MyInt& a, MyInt& b) { return MyInt(a.num+b.num); }
MyInt operator*(MyInt& a, MyInt& b) { return MyInt(a.num*b.num); }
MyInt operator/(MyInt& a, MyInt& b) { return MyInt(a.num/b.num); }
MyDouble operator+(MyDouble& a, MyDouble& b) { return MyDouble(a.num+b.num); }
MyDouble operator-(MyDouble& a, MyDouble& b) { return MyDouble(a.num-b.num); }
MyDouble operator*(MyDouble& a, MyDouble& b) { return MyDouble(a.num*b.num); }
MyDouble operator/(MyDouble& a, MyDouble& b) { return MyDouble(a.num/b.num); }

MyDouble operator+(MyDouble& a, MyInt& b) { return MyDouble(a.num+b.num); }
MyDouble operator-(MyDouble& a, MyInt& b) { return MyDouble(a.num-b.num); }
MyDouble operator*(MyDouble& a, MyInt& b) { return MyDouble(a.num*b.num); }
MyDouble operator/(MyDouble& a, MyInt& b) { return MyDouble(a.num/b.num); }
MyDouble operator+(MyInt& a, MyDouble& b) { return MyDouble(a.num+b.num); }
MyDouble operator-(MyInt& a, MyDouble& b) { return MyDouble(a.num-b.num); }
MyDouble operator*(MyInt& a, MyDouble& b) { return MyDouble(a.num*b.num); }
MyDouble operator/(MyInt& a, MyDouble& b) { return MyDouble(a.num/b.num); }

int main(void)
{
    MyInt intNum_1(10), intNum_2(20);
    MyDouble doubleNum_1(100.0), doubleNum_2(70.0);
    cout << intNum_1+intNum_2 << '\n';
    cout << doubleNum_2/intNum_2 << '\n';
    cout << intNum_1*doubleNum_2 << '\n';
    cout << doubleNum_2-doubleNum_1 << '\n';
}