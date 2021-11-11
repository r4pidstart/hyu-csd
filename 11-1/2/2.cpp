#include<iostream>
#include<string>
using namespace std;

class Circle
{
    private:
        int radius;
    public:
        Circle(int radius=0) : radius(radius){}
        void show()
        {
            cout << "Circle's radius = "<<radius <<"\n";
        }
    friend Circle& operator++(Circle& a);
    friend Circle operator++(Circle& a, int b);
};

Circle& operator++(Circle& a) // ++a
{
    ++a.radius;
    return a;
}

Circle operator++(Circle& a, int b) // a++
{
    Circle tmp(a);
    a.radius++;
    return tmp;
}

int main(void)
{
    Circle a(5), b;
    b=++a;
    a.show(); b.show();
    b=a++;
    a.show(); b.show();
}