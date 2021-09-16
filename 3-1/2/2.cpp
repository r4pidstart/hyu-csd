#include<iostream>
#include<string>
using namespace std;

namespace selfintro
{
    void name(string s)
    {
        cout << "hello my name is" << s << '\n';
    }
    void major(string s)
    {
        cout << "my major is" << s << '\n';
    }
    void studentID(string s)
    {
        cout << "my student id is" << s << '\n';
    }
}

int main(void)
{
    string name,major,studentID;
    cout << "name :";
    getline(cin, name);
    cout << "major :";
    getline(cin, major);
    cout << "studentID :";
    getline(cin, studentID);
    selfintro::name(name);
    selfintro::major(major);
    selfintro::studentID(studentID);
    
}