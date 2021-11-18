#include<iostream>
#include<string>
using namespace std;

template<class T>
void mySwap(T& a, T& b)
{
    T tmp=a;
    a=b;
    b=tmp;
}

template<class T>
void reverseArray(T arr[], int n)
{
    for(int i=0; i<n/2; i++)
        swap(arr[i], arr[n-i-1]);
}

int main() {
    int x[]={1, 10, 100, 3, 5};
    reverseArray(x, 5);
    for(int i=0; i<5; i++)
    cout << x[i]<<" ";
}