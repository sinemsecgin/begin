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
class SquareRoot{
public : double sqrtt;
SquareRoot(){sqrtt=0;}
SquareRoot(double sqr){sqrtt=sqr;}
double GetSquareRoot(){return sqrt(sqrtt);}
};
int main()
{   double choice;
    cout<<"Please Enter a Choice ( to find Logarthim = 1 OR SquareRoot = 2)";
    cin>>choice;
    if(choice==1)
{

  while(1){
    double a;
    cout<<"Please enter a value : ";
    cin>>a;
    Logarithm value(a);
    cout<<"Result : "<<value.GetLogFunc()<<endl;
  if(a==0)
  break;
  }
}
if(choice==2 ){
while(1){
    double b;
    cout<<"Please Enter a Number : ";
    cin>>b;
    SquareRoot value(b);
    cout<<" Square Root Equal to : "<<value.GetSquareRoot()<<endl;
    }
return 0;}}
