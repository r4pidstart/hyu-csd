#include<iostream>
#include<string>
using namespace std;

class Converter {
protected:
    double _ratio;
    virtual double convert(double src)=0;
    virtual string getSrcMetric()=0;
    virtual string getDestMetric()=0;
public:
    Converter(double ratio): _ratio(ratio){ }
    void run(){
        double src;
        cout<<"Convert"<<getSrcMetric()<<" to"<<getDestMetric()<<endl;
        cout<<"Input"<<getSrcMetric()<<" : ";
        cin>>src;
        if(src < 0) throw(domain_error("Exception! Cannot convert negative value"));
        cout<<"Result : "<<convert(src)<<getDestMetric()<<endl;
    }
};

class DollarToWon : public Converter{
public:
    DollarToWon(double ratio=0.0) : Converter(ratio) {}
    double convert(double src) {return src*_ratio;}
    string getSrcMetric() {return " dollar";}
    string getDestMetric() {return " won";}
};

int main() {
    try
    {
        DollarToWon dtw(1176.5);
        dtw.run();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}