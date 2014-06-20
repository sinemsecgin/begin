#include "Geometry.h"

RegularPolygon::RegularPolygon(double edgeLength, double edgeCount):
                                edgeLength(edgeLength), edgeCount(edgeCount){}

double RegularPolygon::Area(){
    return ((edgeCount * edgeLength * edgeLength) / (4 * tan(PI / edgeCount)));
}


Trapezoid::Trapezoid(double bottom, double top, double height):
                        bottom(bottom), top(top), height(height){}

double Trapezoid::Area(){
    return (((top + bottom) * height )/ 2);
}


Sphere::Sphere(double diameter): diameter(diameter){}

double Sphere::Area(){
    return  (4 * PI * diameter * diameter);
}


Parallelogram::Parallelogram(double edge, double height):
                                edge(edge), height(height){}

double Parallelogram::Area(){
    return (edge * height);
}


Cylinder::Cylinder(double diameter, double height):
                    diameter(diameter), height(height){}

double Cylinder::Area(){
    return 2 * PI * diameter * (diameter + height);
}

double Cylinder::Volume(){
    return (PI * diameter * diameter * height);
}


Circle::Circle(double diameter):
                diameter(diameter){}

double Circle:: Area(){
    return (PI*diameter*diameter);
}

double Circle::Perimeter(){
    return (2*PI*diameter);
}

double Circle::SliceArea(double angle){
    return ((PI * diameter * diameter * angle )/ CIRCLE);
}

double Circle::SlicePerimeter(double angle){
    if (angle == CIRCLE) return Area();
    return (ArcLength(angle) + 2 * diameter);
}

double Circle::ArcLength(double angle){
    return ((2 * PI * diameter * angle) / CIRCLE);
}
