#include<iostream>
#include<cmath>
using namespace std;
class Logarithm{
public:
double Lo;
Logarithm(){Lo=0;}
Logarithm(double L){Lo=L;}
double GetLogFunc(){ return log(Lo); }
};

main()
{
    while(1){
    double a;
    cout<<"Please enter a value : ";
    cin>>a;
    Logarithm value(a);
    cout<<"Result : "<<value.GetLogFunc()<<endl;
}return 0;
}
