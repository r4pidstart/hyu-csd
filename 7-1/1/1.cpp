#include<iostream>
#include<string>
using namespace std;

class Shape
{
    public:
        Shape(void)
        {

        }
        Shape(int _width, int _height)
        {
            width=_width, height=_height; 
        }
    protected:
        int width, height;
};

class Triangle : protected Shape
{
    public:
        Triangle(int _width, int _height) : Shape(_width, _height)
        {

        }
        double getArea(void)
        {
            return (double)width*height/2;
        }
};

class Square : protected Shape
{
    public:
        Square(int _width, int _height) : Shape(_width, _height)
        {
    
        }
        double getArea(void)
        {
            return (double)width*height;
        }
};

int main(void)
{
    int w,h; 
    cout << "width : "; cin >> w;
    cout << "height : "; cin >> h;
    
    Triangle tri(w,h);
    Square sq(w,h);

    cout << "Area of Triangle is " << tri.getArea() << '\n' << "Area of Square is " << sq.getArea(); 
}