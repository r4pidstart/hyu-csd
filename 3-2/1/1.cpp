#include<iostream>
using namespace std;

int main(void)
{
    string s; 
    while(1)
    {
        int flag=0;
        cout << "write lowercase string :";
        cin >> s;
        for(int i=0; i<s.length(); i++)
            if(!('a'<=s[i] && s[i]<='z'))
                flag++;

        if("EXIT"==s) break;

        if(flag) 
        {
            cout << "\"warning\"\n";
            continue;    
        }

        for(int i=0; i<s.length(); i++)
            if(s[i]>='a') s[i]=s[i]-'a'+'A';

        cout << s << '\n';
    }
}