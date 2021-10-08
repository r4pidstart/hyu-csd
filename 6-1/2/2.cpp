#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<deque>
using namespace std;

template<typename T>
void mergeContainers(vector<T>& container1, const vector<T>& container2)
{
    for(auto& it : container2)
        container1.push_back(it);
}

template<typename T>
void mergeContainers(list<T>& container1, const list<T>& container2)
{
    for(auto& it : container2)
        container1.push_back(it);
}

template<typename T>
void mergeContainers(deque<T>& container1, const deque<T>& container2)
{
    for(auto& it : container2)
        container1.push_back(it);
}

template<typename T1, typename T2>
void mergeContainers(map<T1, T2>& container1, const map<T1, T2>& container2)
{
    for(auto& it : container2)
        if(container1.find(it.first) == container1.end())
            container1[it.first]=it.second;
}

template<typename T>
void mergeContainers(set<T>& container1, const set<T>& container2)
{
    for(auto& it : container2)
        if(container1.find(it) == container1.end())
            container1.insert(it);
}