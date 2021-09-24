#include<iostream>
using namespace std;

const double pi=3.14;

void circle(double *rad)
{
    *rad=*rad**rad*pi;
}

int main(void)
{
    double radius;
    cin >> radius;
    circle(&radius);
    cout << radius;
}