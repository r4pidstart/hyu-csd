#include<iostream>
#include<string>
#include<vector>
using namespace std;

const double pi=3.14;

class Shape 
{
        string name;
    protected:
        int radius, height;
    public:
        Shape(string n, int r, int h):name(n),radius(r),height(h){}
        virtual double getVolume ()=0;
        string getName() const {return name;}
};

class Cone : public Shape
{
        virtual double getVolume()
        {
            return height*pi*radius*radius/3;
        }
    public:
        Cone(string n, int r, int h):Shape(n,r,h){}
};

class Cylinder : public Shape
{
        virtual double getVolume()
        {
            return pi*radius*radius*height;
        }
    public:
        Cylinder(string n, int r, int h):Shape(n,r,h){}
};

int main(void)
{
    vector<Shape*> p(2);
    p[0]= new Cone("Cone",10,20);
    p[1]= new Cylinder("Cylinder",10,20);
    for(int i=0;i<2;i++){
        cout<<p[i]->getName()<<"’s volume is "<<p[i]->getVolume()<<endl;
    }
    return 0;
}