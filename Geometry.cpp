/*
    Begin: an all-purpose maths program.
    Copyright (C) 2014 Sinem Seçgin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
