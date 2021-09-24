#include<iostream>
using namespace std;

void mySwap(int& a, int& b)
{
    int tmp=a;
    a=b;
    b=tmp;
}

int main(void)
{
    int x,y; cin >> x >> y;
    std::cout<< "Before Call by reference – x : " << x<< ", y : " << y<< endl;
    mySwap(x,y);
    std::cout<< "After Call by reference – x : " << x<< ", y : " << y<< endl;
}