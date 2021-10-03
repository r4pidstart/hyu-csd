#include<iostream>
#include<string>
using namespace std;
class Distance
{
    private:
        double _meter;
    public:
        Distance()
        {
            _meter=0;
        }
        void setDis(double meter)
        {
            this->_meter=meter;
        }
        double getDis(void)
        {
            return this->_meter;
        }        
};

double addDis(double dis1, double dis2)
{
    return dis1+dis2;
}

double subDis(double dis1, double dis2)
{
    double ret=dis1-dis2;
    return ret<0 ? -ret:ret;
}

int main(void)
{
    Distance D1=Distance(), D2=Distance();
    double dist;
    cout << "Enter distance1 value of meters : "; cin >> dist;
    D1.setDis(dist);
    cout << "Enter distance2 value of meters : "; cin >> dist;
    D2.setDis(dist);

    cout << "The sum between the two distance :" << addDis(D1.getDis(), D2.getDis()) << " m\n";
    cout << "The difference between the two distance :" << subDis(D1.getDis(), D2.getDis()) << " m\n";
}