#include<iostream>
using namespace std;

int main(void)
{
    int n;
    cout << "S=";
    cin >> n;

    int ans=0;
    for(int i=0; i<n; i++)
    {
        string s;
        while(1)
        {
            int flag=0;
            cin >> s;

            for(int i=0; i<s.length(); i++)
                if(!('a'<=s[i] && s[i]<='z'))
                    flag++;
            if(!flag) break;
            else cout << "\"warning\"\n";
        }
        int alp[26]={}, flag=0; char prev=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=prev)
            {
                if(alp[s[i]-'a']) flag++;
                else alp[s[i]-'a']=1;
            }
            prev=s[i];
        }
        if(!flag) ans++;
    }
    cout << ans;
}