#include <iostream>
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944
using namespace std;
class AllPolygon{
    public:
        double edgeLength;
        double edgeCount;
        AllPolygon(){edgeLength=0; edgeCount=0;}
AllPolygon(double edgeLength , double edgeCount ){
            this->edgeLength = edgeLength;
            this->edgeCount = edgeCount;
        }
        double GetArea(){
            return ((edgeCount * edgeLength * edgeLength) / (4 * tan(PI / edgeCount)));
        }};
class Square:public AllPolygon {
    public: Square():AllPolygon(){}
Square(double edgeCo,double edgeLe):AllPolygon(edgeLe,edgeCo){}
double GetPerimeter(){
return (4*edgeLength);}
double GetArea(){
            return (edgeLength * edgeLength);}
            };
class Trapezoid : public AllPolygon{
    public: double height;
    Trapezoid():AllPolygon(){height=0;}
Trapezoid(double edgeco , double length,double heigt): AllPolygon( edgeco,length){height=heigt;}
double GetArea(){
return (edgeLength+edgeLength)*height/2;}
};
class Sphere{
public : double dia;
Sphere(){dia=0;}
Sphere(double d){ dia=d;}
double GetArea() {return  4*PI*dia*dia;  }
};
class Parallelogram{public:
double edge; double height;
Parallelogram (){}
Parallelogram(double ed,double heig){edge=ed; height=heig;}
void SetArea(double e,double h){edge=e; height=h;}
double GetArea(){return edge*height; }};

class Cylindir{public:
double diameter,height;
Cylindir(){diameter=0; height=0;}
Cylindir(double d,double h){diameter=d; height=h;}
double GetSufaceArea(){return 2*PI*diameter*(diameter+height);}
double GetVolume(){return PI*pow(diameter,2)*height;}
};
/*class functions{
public: double x, y,a;
x=pow(x,2)*5;


}; */
int main(){
double x,y;
    cout<<"Please enter a Triangle edge and length: "<<endl;
    cin>>x;
    AllPolygon triangle(x,3);
    AllPolygon rectangle(x, 4);
    AllPolygon pentragon(x, 5);
    //AllPolygon hexagon(x, 6);
    AllPolygon hexagon(x, 500);
    Square square(4,4);
    cout << "Area of geometric shapes :\n"
         << "Triangle Area : " << triangle.GetArea() << endl
         <<"Rectangle Area : "<<rectangle.GetArea()<<endl
         <<"Pentagon Area: "<<pentragon.GetArea()<<endl
         <<"Hexagon Area : "<<hexagon.GetArea()<<endl
         <<"Square Area: "<< square.GetArea()<<endl;

  double c,d;
         cout<<"Enter a paralelogram Area and Height: ";
         cin>>c>>d;
         Parallelogram paralel;
                cout<<"Parallelogram Area:\n "<<paralel.GetArea(c*d)<<endl;
return 0;
/* AllPolygon triangle(6, 6);
    AllPolygon rectangle(6, 6);
    AllPolygon pentragon(6, 6);
    AllPolygon hexagon(6, 6);
    Square square(6,6);
    Trapezoid trape(6,6,5);
    Sphere sp(6);
    Parallelogram pa(6,9);
    Cylindir cy(6,5);
    cout << "Area of geometric shapes :\n"
         << "Triangle: " << triangle.GetArea() << endl
         << "Rectangle: " << rectangle.GetArea() << endl
         << "Pentagon: " << pentragon.GetArea() << endl
         << "Hexagon: " << hexagon.GetArea() << endl
        <<"Square:"<<square.GetArea()<<endl
        <<"Trapezoid:  "<<trape.GetArea()<<endl
        <<"Sphere : "<<sp.GetArea()<<endl
        <<"Parallelogram :  "<<pa.GetArea()<<endl
        <<"Cylindir  Surface Area: "<<cy.GetSufaceArea()<<endl
        <<"Cylindir Volume : "<<cy.GetVolume()<<endl;
return 0; */


        }
