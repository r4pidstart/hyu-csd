#include<iostream>
using namespace std;

class Cat
{
    private:
        int _age;
        int _weight;
    public:
        void showCatInfo(void)
        {
            cout << "Age : " << _age << " months" << '\n' << "Weight : " << _weight << "kg";
        }
        Cat(int age, int weight)
        {
            _age=age, _weight=weight;
        }
};

int main(void)
{
    int a,w;
    cout << "Age : ";
    cin >> a;
    cout << "Weight : ";
    cin >> w;

    Cat cat=Cat(a,w);
    cat.showCatInfo();
}