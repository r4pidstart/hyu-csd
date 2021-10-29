#include<iostream>
#include<cstdlib> // exit
using namespace std;

class Container
{
    public:
        Container(){}
        virtual void push(int value) {}
        virtual int pop() {return 0;}
        virtual bool isEmpty() {return false;}
        virtual ~Container() {}
};
  
class MyQueue : public Container
{
    private:
        int maxSize, le, ri;
        int* arr;
    public:
        MyQueue(int maxSize) : Container(), maxSize(maxSize) 
        {
            arr=new int[maxSize];
            le=0, ri=0;
        }
        virtual void push(int value)
        {
            if(ri==maxSize-1)
            {
                int* tmp= new int[maxSize*2];
                for(int i=0; i<maxSize; i++)
                    tmp[i]=arr[i];
                maxSize*=2;
                delete arr;
                arr=tmp;
            }
            arr[ri++]=value;
        }
        virtual int pop()
        {
            if(isEmpty()) 
            {
                cout << "Queue is empty.\n";
                exit(EXIT_FAILURE);
            }
            else return arr[le++];
        }
        virtual bool isEmpty()
        {
            return le==ri;
        }
        ~MyQueue()
        {
            delete arr;
        }
};

class MyStack : public Container
{
    private:
        int maxSize, le, ri;
        int* arr;
    public:
        MyStack(int maxSize) : Container(), maxSize(maxSize) 
        {
            arr=new int[maxSize];
            le=0, ri=0;
        }
        virtual void push(int value)
        {
            if(ri==maxSize-1)
            {
                int* tmp= new int[maxSize*2];
                for(int i=0; i<maxSize; i++)
                    tmp[i]=arr[i];
                maxSize*=2;
                delete arr;
                arr=tmp;
            }
            arr[ri++]=value;
        }
        virtual int pop()
        {
            if(isEmpty()) 
            {
                cout << "Stack is empty.\n";
                exit(EXIT_FAILURE);
            }
            else return arr[--ri];
        }
        virtual bool isEmpty()
        {
            return le==ri;
        }
        ~MyStack()
        {
            delete arr;
        }
};

int main(void)
{
    Container *myStack = new MyStack(5);
    Container *myQueue = new MyQueue(5);
    for(int i=0; i<10; i++){
    myStack->push(i*10+1);
    myQueue->push(i*10+1);
    }
    for(int i=0; i<10; i++){
    int n = myStack->pop();
    cout << n << " " << myStack->isEmpty() << "\n";
    }
    cout << endl;
    for(int i=0; i<5; i++){
    int n = myQueue->pop();
    cout << n << " ";
    }
    cout << "\n";
    delete myStack;
    delete myQueue;
}