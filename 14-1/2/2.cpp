#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
#include<list>
#include<algorithm>
#include<cmath>

#include<iterator>

using namespace std;

template<class T>
void print_stats(const T& seq)
{   
    vector<typename iterator_traits<decltype(seq.begin())>::value_type > v;
    typename iterator_traits<decltype(seq.begin())>::value_type sum=0, sum2=0;
    // v.reserve(seq.size());

    for(const auto& it : seq)
        v.push_back(it), sum+=it, sum2+=it*it;

    sort(v.begin(), v.end());

    auto avg=(double)sum/(int)v.size();
    cout << "\nmin : " << v.front() << 
            "\nmax : " << v.back() <<
            "\nmedian : " << v[(int)v.size()/2] << 
            "\naverage : " << avg << 
            "\nvariance : " <<  (double)sum2/(int)v.size()-avg*avg<<
            "\nstandard deviation : " << sqrt((double)sum2/(int)v.size()-avg*avg); 
}

int main(void)
{
    array<int,3> seq1{65,75,85};
    vector<int> seq2{65,75,85};
    deque<int> seq3{65,75,85};
    list<int> seq4{65,75,85};
    forward_list<int> seq5{65,75,85};
    print_stats(seq1);
    print_stats(seq2);
    print_stats(seq3);
    print_stats(seq4);
    print_stats(seq5);
}