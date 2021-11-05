#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Container
{
    public:
        virtual void push_back(int value) = 0;
        virtual void pop_back() = 0;
        virtual int front() = 0;
        virtual int back() = 0;
        virtual int getVectorArr(int index) = 0;
        virtual void setVectorArr(int index, int value) = 0; 
};

class MyVector : public Container
{
    private:
        int max_size, now, *arr;
        void resize(double value)
        {
            max_size*=value;
            if(max_size==0) max_size=1;
            int* tmp=new int[max_size];
            for(int i=0; i<now; i++)
                tmp[i]=arr[i];
            delete[] arr;
            arr=tmp;
        }
        void check(int index)
        {
            if(index<0 or now<=index)
            {
                cout << "error";
                exit(EXIT_FAILURE);
            }
        }
    public:
        MyVector(int size):max_size(size)
        {
            arr=new int[max_size], now=0;
        }
        ~MyVector()
        {
            delete[] arr;
        }
        virtual void push_back(int value)
        {
            if(now==max_size) resize(2);
            arr[now++]=value;
        }
        virtual void pop_back()
        {
            check(0);
            cout<<arr[--now]<<" ";
            if(now < max_size/4) resize(0.5);
        }
        virtual int front()
        {
            check(0);
            return arr[0];
        }
        virtual int back()
        {
            check(0);
            return arr[now-1];
        }
        virtual int getVectorArr(int index)
        {
            check(index);
            return arr[index];
        }
        virtual void setVectorArr(int index, int value)
        {
            check(index);
            arr[index]=value;
        }
};

int main() {
    Container* v = new MyVector(5);
    for (int i = 0; i < 10; i++) 
    {
        v->push_back(i * 10);
    }
    cout << v->front() << endl;
    cout << v->back() << endl;
    cout << v->getVectorArr(3) << endl;
    v->setVectorArr(0, 1);
    for (int j = 0; j < 10; j++) 
    {
        v->pop_back();
        cout << v->back() << ' ';
        cout << v->front() << '\n';
    }
    cout << endl;
    v->back();
    delete v;
}