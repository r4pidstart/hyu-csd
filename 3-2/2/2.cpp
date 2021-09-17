#include<iostream>
using namespace std;

int main(void)
{
    string s;
    int n=2;
    while(n--)
    {
        while(1)
        {
            int flag=0;
            cout << "s=";
            cin >> s;

            for(int i=0; i<s.length(); i++)
                if(!('A'<=s[i] && s[i]<='Z'))
                    flag++;
            if(!flag) break;
            else cout << "\"warning\"\n";
        }

        int a1=0, a2=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s.substr(i,3)=="IOI") a1++;
            if(s.substr(i,2)=="OI") a2++;
        }
        cout << a1 << '\n' << a2 << '\n'; 
    }
}