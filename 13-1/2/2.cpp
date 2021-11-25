#include<iostream>
#include<string>
using namespace std;

struct Exception
{
    string s;
    Exception(string str):s(str){}
    void print(void)
    {
        cout << s;
    }
};

class DivideByZeroException : public Exception
{
    public:
    DivideByZeroException(string str):Exception(str){}
};

class InvalidInputException : public Exception
{
    public:
    InvalidInputException(string str):Exception(str){}
};

int divide(int x, int y)
{
    if(y==0) throw(DivideByZeroException("Divide by zero exception."));
    if(x<0 or y<0) throw(InvalidInputException("Negative value input exception."));
    return x/y;
}

int main(void)
{
    int x, y;
    double result;
    try {
        cout << "Division. Input two numbers >> ";
        cin >> x >> y;
        result = divide(x, y);
        cout << result << endl;
    }
    catch(DivideByZeroException &e) {
        e.print();
    }
    catch(InvalidInputException &e) {
        e.print();
    }
}