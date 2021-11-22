#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <class InputIt, class T>
InputIt MyFind(InputIt beg, InputIt end, T target)
{
    for(auto it=beg; it!=end; it++)
        if(*it == target) return it;
    return end;
}

int main() {
    int myInts[] = { 10, 20, 30, 40 };
    int* p;
    vector<int> myVector(myInts, myInts + 4);
    vector<int>::iterator it;

    p = MyFind(myInts, myInts + 4, 50);
    if (p != myInts + 4)
    cout << "Element found in myInts: " << *p << '\n';
    else
    cout << "Element not found in myInts\n";
    it = MyFind(myVector.begin(), myVector.end(), 30);
    if (it != myVector.end())
    cout << "Element found in myVector: " << *it << '\n';
    else
    cout << "Element not found in myVector\n";
    return 0;
}