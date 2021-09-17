#include<iostream>
using namespace std;

int multi(int a, int b=2)
{
    return a*b;
}

int main(void)
{
    cout << multi(3) << '\n';
    cout << multi(3,3) << '\n';
}