#include<iostream>
#include<string>
using namespace std;

class HardwareA;
class HardwareB;

class HardwareA
{
    private:
        int data;
    public:
        HardwareA(int n) : data(n) {}
        void setSpecification(int n) { data=n; }
        void show() {cout << data << '\n'; }
        friend void show(HardwareA&, HardwareB&);
        friend void exchange(HardwareA&, HardwareB&);
        friend void exchange(HardwareA*, HardwareB*);
};

class HardwareB
{
    private:
        int data;
    public:
        HardwareB(int n) : data(n) {}
        void setSpecification(int n) { data=n; }
        void show() {cout << data << '\n'; }
        friend void show(HardwareA&, HardwareB&);
        friend void exchange(HardwareA&, HardwareB&);
        friend void exchange(HardwareA*, HardwareB*);
};

void show(HardwareA& a, HardwareB& b)
{
    cout << "HardwareA, HardwareB : " << a.data << ", " << b.data << '\n';
}

void exchange(HardwareA* a, HardwareB* b)
{
    int tmp=a->data;
    a->data=b->data;
    b->data=tmp;
}

void exchange(HardwareA& a, HardwareB& b)
{
    int tmp=a.data;
    a.data=b.data;
    b.data=tmp;
}


int main() {
    HardwareA hardwareA(10);
    HardwareB hardwareB(20);
    show(hardwareA, hardwareB);
    exchange(hardwareA, hardwareB);
    show(hardwareA, hardwareB);
    exchange(&hardwareA, &hardwareB);
    show(hardwareA, hardwareB);
    return 0;
}