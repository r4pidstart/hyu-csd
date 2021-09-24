#include<iostream>
using namespace std;

int n; 

void max(int* numBox, int* max)
{
    for(int i=0; i<n; i++)
        if(*max < numBox[i]) *max=numBox[i];
}

void min(int* numBox, int* min)
{
    for(int i=0; i<n; i++)
        if(*min > numBox[i]) *min=numBox[i];
}

void avg(int* numBox, double* avg)
{
    for(int i=0; i<n; i++)
        *avg+=numBox[i];
    *avg/=n;
}

int main(void)
{
    cin >> n;
    int *maxi=new int(-0x7FFFFFFF), *mini=new int(0x7FFFFFFF), *arr=new int[n];
    double *avgi=new double;
    for(int i=0; i<n; i++) cin >> arr[i];
    max(arr, maxi);
    min(arr, mini);
    avg(arr, avgi);
    cout << "max:" << *maxi << '\n' << "min:" << *mini << '\n' << "avg:" << *avgi;
    delete maxi, mini, avgi;
    delete[] arr;
}