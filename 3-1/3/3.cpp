#include<iostream>
using namespace std;

int main(void)
{
    string s1, s2, s;
    getline(cin, s1);
    getline(cin, s2);
    s=s1+' '+s2;
    cout << s;
}