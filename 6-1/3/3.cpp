#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

// vector<string> split(string s)
// {
//     vector<string> ret;
//     stringstream ss(s);
//     string tmp;

//     while(getline(ss, tmp, ' '))
//         ret.push_back(tmp);
    
//     return ret;
// }

int main(void)
{
    map<string, int> m; 
    string s; getline(cin, s);

    // split
    stringstream ss(s);
    vector<string> word;
    while(ss >> s) word.push_back(s);

    for(auto& it : word)
        if(m.find(it)==m.end()) m[it]=1;
        else m[it]++;

    for(auto& it : m)
        cout << it.first << ": " << it.second << '\n';
}