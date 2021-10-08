#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void)
{
    int n;
    cout << "N =\n";
    cin >> n;
    map<string, int> m;
    for(int i=0; i<n; i++)
    {
        string s; int score;
        cin >> s >> score;
        m[s]=score;
    }

    cout << "Which student's score?\n";
    string target;
    cin >> target;

    if(m.find(target) != m.end()) cout << target << "'s score: " << m[target];
    else cout << target << " is not in the database.";

}