#include<iostream>
#include<string>
using namespace std;

template <class T>
class Calculator {
    private:
    T num1, num2;
    public:
    Calculator(T n1, T n2) 
    {
    num1 = n1;
    num2 = n2;
    }

    void Result() 
    {
        cout << "Numbers:" << num1 << " and " << num2 << "\n";
        cout << num1 << " + " << num2 << " = " << num1+num2 << "\n"; 
        cout << num1 << " - " << num2 << " = " << num1-num2 << "\n"; 
        cout << num1 << " * " << num2 << " = " << num1*num2 << "\n"; 
        cout << num1 << " / " << num2 << " = " << num1/num2 << "\n"; 
    }
};


int main() {
    int n1;
    float n2;
    cout << "Input 2 numbers. 1st an Integer, 2nd a Rational number" << endl;
    cin >> n1;
    cin >> n2;
    Calculator<double> doubleCalc(n1, n2);
    cout << endl << "Results:" << endl;
    doubleCalc.Result();
    return 0;
}