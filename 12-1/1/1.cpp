#include<iostream>
#include<string>
using namespace std;

template<class T>
T sum(T arr[], int n)
{
    T ret=0;
    for(int i=0; i<n; i++) ret+=arr[i];
    return ret;
}

int main() {
    float fdata[5];
    int i=0;
    //input 5 numbers
    cout << "\nInput 5 numbers >>" << endl;
    for (i=0; i<5; i++)
    cin >> fdata[i];
    //print sum of 5 numbers
    cout << "\nSum of above inputs is : " << sum(fdata, 5) << endl;
    cin.get();
    return 0;
}