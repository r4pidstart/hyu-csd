#include<iostream>
using namespace std;

int main(void)
{
    string s, s1="IOI", s2="OI";
    cout << "s=";
    cin >> s;

    int a1=0, a2=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s.substr(i,3)==s1) a1++;
        if(s.substr(i,2)==s2) a2++;
    }
    cout << a1 << '\n' << a2; 
}