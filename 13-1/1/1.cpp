#include<iostream>
#include<string>
using namespace std;

int Exp(int base, int exp)
{
    if(exp < 0 or base <= 0) throw("Cannot use negative numbers.");
    if(exp==0) return 1;
    return Exp(base, exp-1)*base;
}

int main(void)
{
    int v=0;
    try {
        v = Exp(2, 10);
        cout << "The value of 2 to the power 10 is "<< v <<endl;
        v = Exp(2, -10);
        cout << "The value of 2 to the power -10 is "<< v <<endl;
    }
    catch(const char *s){
        cout << "Exception! "<< s << endl;
    }
}