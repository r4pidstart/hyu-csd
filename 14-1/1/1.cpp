#include<iostream>
#include<string>
using namespace std;

int add_int(const int& a, const int& b)
{
    return a+b;
}

double add_double(const double& a, const double& b)
{
    return a+b;
}

template<class A, class B>
auto add_any(const A& a, const B& b) -> decltype(auto)
{
    return a+b;
}

int main(void)
{
    cout << add_any((double)5.5, (int)4) << '\n' << add_any((string)"add", (string)"any");
}