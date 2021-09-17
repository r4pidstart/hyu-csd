#include<iostream>
using namespace std;

string func(string a="Hello", string b="world", string c="")
{
    return a+' '+b+' '+c;
}

int main()
{
    string str_1 = func();
    string str_2 = func("Hello", "Hanyang");
    string str_3 = func("Hello", "C++", "world");
    cout << str_1 << endl;
    cout << str_2 << endl;
    cout << str_3 << endl;
}