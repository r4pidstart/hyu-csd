#include<iostream>
#include<string>
using namespace std;

class Converter 
{
    protected:
        double _ratio;
        virtual double convert(double src)=0;
        virtual string getSrcMetric()=0;
        virtual string getDestMetric()=0;
    public:
        Converter(double ratio): _ratio(ratio){ }
        void run()
        {
            double src;
            cout<<"Convert "<<getSrcMetric()<<" to "<<getDestMetric()<<endl;
            cout<<"Input "<<getSrcMetric()<<" : ";
            cin>>src;
            cout<<"Result : "<<convert(src)<<getDestMetric()<<endl;
        }
};

class DollarToWon : public Converter
{
    private:
        virtual string getSrcMetric()
        {
            return "dollar";
        }
        virtual string getDestMetric()
        {
            return "won";
        }
        virtual double convert(double src)
        {
            return src*_ratio;
        }
    public:
        DollarToWon(double ratio):Converter(ratio) {}
};

int main(void)
{
    DollarToWon dtw(1176.5);
    dtw.run();
}