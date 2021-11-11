#include<iostream>
#include<string>
#include<algorithm>

class SortedArray {
        int size; // size of array
        int *p; // pointer
        void sort() // sort integer array in increasing order
        {
            std::sort(p, p+size);
        }
    public:
        SortedArray() // initialize p to NULL, size to 0
        {
            p=nullptr, size=0;
        }
        SortedArray(const SortedArray& src) // copy constructor
        {
            size=src.size;
            p=new int[size];
            for(int i=0; i<size; i++)
                p[i]=src.p[i];
        }
        SortedArray(int p[], int size) //constructor
        {
            this->size=size;
            this->p=new int[size];
            for(int i=0; i<size; i++)
                this->p[i]=p[i];
            sort();
        }
        ~SortedArray() //destructor
        {
            delete[] p;
        }
        SortedArray operator+ (const SortedArray& op2) //add op2 array to current array
        {
            int* tmp=new int[size + op2.size];
            for(int i=0; i<size; i++)
                tmp[i]=p[i];

            for(int i=size; i<size+op2.size; i++)
                tmp[i]=op2.p[i-size];
            SortedArray tmpR={tmp, size+op2.size};

            return tmpR;
        }
        SortedArray& operator= (const SortedArray& op2) // copy op2 array to current array
        {
            delete[] p;
            size=op2.size;
            p=new int[size];
            for(int i=0; i<size; i++)
                p[i]=op2.p[i];

            return *this;
        }
        void show()
        {
            std::cout << "Array : ";
            for(int i=0; i<size; i++) 
                std::cout << p[i] << ' ';
            std::cout << '\n';
        }
};

int main() {
    int n[] = {2, 300, 68};
    int m[] = {100, 5, 6, 65};
    SortedArray a(n, 3), b(m, 4), c;
    c = a + b;
    a. show();
    b. show();
    c. show();
}