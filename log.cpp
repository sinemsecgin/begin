#include<iostream>
#include<cmath>
using namespace std;
class Logaritma{
public:

double lo;
Logaritma(){lo=0;}
Logaritma(double l){lo=l;}
double GetLogFunc(){ return log(lo); }

};
main()
{
    double a;
    Logaritma value(a);
    cout<<"Please enter a value : ";
    cin>>a;
    cout<<"Result : "<<value.GetLogFunc()<<endl;
return 0;
}
