#include<iostream>
#include<string>
using namespace std;

class Point
{
    protected:
        int x,y;
    public:
        Point(int x, int y):x(x), y(y) {}
        void move(int _x, int _y)
        {
            x=_x, y=_y;
        }
};

class ColorPoint : Point
{
    private:
        string color;
    public:
        ColorPoint(int x, int y, string color):Point(x,y), color(color) {}
        void setPoint(int _x, int _y)
        {
            move(_x, _y);
        }
        void setColor(string _color)
        {
            color=_color;
        }
        void show(void)
        {
            cout << "The point's color is " << color << " which is on (" << x << ',' << y << ").\n";
        }
};

int main(void)
{
    ColorPoint cp(5, 5, "RED");
    cp.show();
    cp.setPoint(10,20);
    cp.setColor("BLUE");
    cp.show();
}