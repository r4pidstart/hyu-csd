#include<iostream>
#include<string>
using namespace std;

class Container {
    public:
        virtual void push_back(int value) = 0;
        virtual void pop_back() = 0;
        virtual int getVectorArr(int index) = 0;
        virtual void setVectorArr(int index, int value) = 0;
};

class MyVector : public Container
{
    private:
        int* arr;
        int size;
        int idx;
        void resize()
        {
            int* tmp=new int[size*2];
            for(int i=0; i<size; i++)
                tmp[i]=arr[i];
            delete[] arr;
            arr=tmp;
            size*=2;
        }
    public:
        MyVector(int s)
        {
            size=s;
            arr=new int[5];
            idx=0;
        }
        ~MyVector()
        {
            delete[] arr;
        }
        void push_back(int value)
        {
            if(size==idx) resize();
            arr[idx++]=value;
        }
        void pop_back()
        {
            if(idx==0) throw("nothing to pop");
            cout << arr[--idx] << " ";
        }
        int getVectorArr(int index)
        {
            if(!(0<=index and index<idx)) throw("Out of range error");
            return arr[index];
        }
        void setVectorArr(int index, int value)
        {
            if(!(0<=index and index<idx)) throw("Out of range error");
            arr[index]=value;
        }
};

int main() {
    Container* v = new MyVector(5);
    for (int i = 0; i < 10; i++) {
        v->push_back(i * 10);
    }
    try{
        v->setVectorArr(11, 20);
        cout << v->getVectorArr(10) << endl;
    }
    catch(const char* msg){
        cerr<<msg<<endl;
    }
    for (int j = 0; j < 11; j++) {
        try{
            v->pop_back();
        }
        catch(const char* msg){
            cerr<<msg<<endl;
        }
    }
    cout << endl;
}