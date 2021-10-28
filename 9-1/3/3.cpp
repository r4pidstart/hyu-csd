#include<iostream>
#include<string>
#include<vector>
using namespace std;

const double PI=3.14;

class Shape
{
    private:
        string name;
    protected:
        int width, height;
    public:
        Shape(string n, int w, int h):name(n), width(w), height(h){};
        // virtual ~Shape(){}
        virtual double getArea()
        {
            return 0;
        }
        string getName() const
        {
            return name;
        }
};

class Ellipse : public Shape
{
    public:
        Ellipse(string n, int w, int h):Shape(n,w,h){};
        virtual double getArea()
        {
            return width*height*PI;
        }
};

class Rect : public Shape
{
    public:
        Rect(string n, int w, int h):Shape(n,w,h){};
        virtual double getArea()
        {
            return width*height;
        }
};

class Triangle: public Shape
{
    public:
        Triangle(string n, int w, int h):Shape(n,w,h){};
        virtual double getArea()
        {
            return width*height/2;
        }
};

int main(void)
{
    vector<Shape*> p(3);
    p[0]= new Ellipse("Ellipse",10,20);
    p[1]= new Rect("Rectangle",30,40);
    p[2]= new Triangle("Triangle",30,40);
    for(int i=0;i<3;i++){
    cout<<p[i]->getName()<<"’s area is "<<p[i]->getArea()<<endl;
    }
    for(int i=0;i<3;i++) delete p[i];
    return 0;
}