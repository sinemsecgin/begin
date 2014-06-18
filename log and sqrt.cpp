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
class Exponential{
public:
double ex;
Exponential()   {ex=0;}
Exponential(double myexp)   {ex=myexp;}
double GetExponential()  {return exp(ex);}
};
int main()
{   double choice;
    cout<<"Please Enter a Choice ( to find Logarthim = 1 OR SquareRoot = 2 OR Exponential=3)";
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
      if(b==0)
  break;
    }
}
    if(choice==3){
    while(1){
        double c;
    cout<<"Please Enter a Number : ";
    cin>>c;
    Exponential value(c);
     cout<<" Exponential Number Equal to : "<<value.GetExponential()<<endl;
      if(c==0)
  break;}
return 0;
}
}
