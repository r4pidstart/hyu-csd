#include<iostream>
#include<string>
using namespace std;

#include<vector>
#include<algorithm>
#include<numeric>

// int sum_odd(const vector<int>& v)
// {
//     int ret=0;
//     auto odd=[&ret] (const int& n) { if(n&1) ret+=n; };
//     for_each(v.begin(), v.end(), odd);
//     return ret;
// }

// int sum_even(const vector<int>& v)
// {
//     int ret=0;
//     auto even=[&ret] (const int& n) { if(!(n&1)) ret+=n; };
//     for_each(v.begin(), v.end(), even);
//     return ret;
// }

// int sum_prime(const vector<int>& v)
// {
//     int ret=0;
//     auto prime=[&ret] (const int& n)
//     {
//         if(n==1) return;
//         for(int i=2; i<n; i++)
//             if(!(n%i)) return;
//         ret+=n;
//     };
//     for_each(v.begin(), v.end(), prime);
//     return ret;
// }

int sum_odd(const vector<int>& v)
{
    return accumulate(v.begin(), v.end(), 0, [](int ret, const int& n) {return ret+=(n&1) ? n:0;});
}

int sum_even(const vector<int>& v)
{
    return accumulate(v.begin(), v.end(), 0, [](int ret, const int& n) {return ret+=(n&1) ? 0:n;});
}

int sum_prime(const vector<int>& v)
{
    return accumulate(v.begin(), v.end(), 0, [](int ret, const int& n)
    {
        if(n==1) return ret;
        for(int i=2; i<n; i++) if(!(n%i)) return ret;
        return ret+=n;
    });
}

int main(void)
{
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    cout << sum_odd(v) << '\n' << sum_even(v) << '\n' << sum_prime(v);
}