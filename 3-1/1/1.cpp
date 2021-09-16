#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    string name,major,studentID;
    cout << "name :";
    getline(cin, name);
    cout << "major :";
    getline(cin, major);
    cout << "studentID :";
    getline(cin, studentID);
    cout << "hello, my name is " << name << '\n' << "my major is" << major << '\n' << "my studentID is" << studentID;
}