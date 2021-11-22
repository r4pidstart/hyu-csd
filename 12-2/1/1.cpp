#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

template<typename T>
class Container {
    public:
        Container(){}
        virtual void push(T value) = 0;
        virtual T pop() = 0;
        virtual bool isEmpty() = 0;
        virtual ~Container() {}
};

template<class T>
class MyStack : public Container<T>
{
    private:
        int size, ri;
        T* arr;
    public:
        MyStack(int size)
        {
            this->size=size;
            arr=new T[size];
            ri=0;
        }
        void push(T value)
        {
            if(ri==size-1)
            {
                T* tmp=new T[size*2];
                for(int i=0; i<size; i++)
                    tmp[i]=arr[i];
                size*=2;
                delete[] arr;
                arr=tmp;
            }
            arr[ri++]=value;
        }
        T pop(void)
        {
            if(ri) return arr[--ri];
            else 
            {
                cout << "error";
                exit(EXIT_FAILURE);
            }
        }
        bool isEmpty(void)
        {
            return !ri;
        }
        virtual ~MyStack()
        {
            delete[] arr;
        }
};

int main() {
    Container<int>* myStack = new MyStack<int>(5);
    Container<double>* myStack_2 = new MyStack<double>(5);
    for (int i = 0; i < 10; i++) {
    myStack->push(i * 10);
    myStack_2->push(i * 10 + 0.5);
    }
    for (int i = 0; i < 10; i++) {
    int num = myStack->pop();
    cout << num << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
    double num_2 = myStack_2->pop();
    cout << num_2 << " ";
    }
    cout << endl;
    delete myStack;
    delete myStack_2;
}