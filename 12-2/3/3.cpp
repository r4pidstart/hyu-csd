#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <class InputIt, class OutputIt>
void MyCopy(InputIt beg, InputIt end, OutputIt target)
{
    for(auto it1=target, it2=beg; it2!=end; it1++, it2++)
        *it1=*it2;
}

template <class InputIt1, class InputIt2, class OutputIt>
void MyMerge(InputIt1 beg1, InputIt1 end1, InputIt2 beg2, InputIt2 end2, OutputIt target)
{
    for(auto it=target; ; it++)
    {
        if(beg1==end1 and beg2==end2) break;
        else if(beg1==end1) *it=*beg2, beg2++;
        else if(beg2==end2) *it=*beg1, beg1++;
        else if(*beg1 < *beg2) *it=*beg1, beg1++;
        else *it=*beg2, beg2++;
    }
}

int main() {
    int first[] = { 5,10,15,20,25 };
    int second[] = { 10, 20, 30, 40, 50 };
    vector<int> v(10);
    vector<int> myVector(5);
    MyCopy(first, first + 5, myVector.begin());
    cout << "myVector contains:";
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
    cout << ' ' << *it;
    cout << endl;
    MyMerge(first, first + 5, second, second + 5, v.begin());
    cout << "the resulting vector contains:";
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    cout << ' ' << *iter;
    cout << '\n';
    return 0;
 }