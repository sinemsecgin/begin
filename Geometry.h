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

#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED

#include "definitions_includes.h"

class RegularPolygon{
public:
    double edgeLength, edgeCount;
    RegularPolygon(double edgeLength=0 , double edgeCount=1);
    double Area();
};

class Trapezoid{
public:
    double height, bottom, top;
    Trapezoid(double bottom=0 , double top=0, double height=0);
    double Area();
};

class Sphere{
public:
    double diameter;
    Sphere(double diameter=0);
    double Area();
};

class Parallelogram{
public:
    double edge;
    double height;
    Parallelogram(double edge=0, double height=0);
    double Area();
};

class Cylinder{
public:
    double diameter, height;
    Cylinder(double diameter=0, double height=0);
    double Area();
    double Volume();
};

class Circle{
public:
    double diameter;
    Circle(double diameter=0);
    double Area();
    double Perimeter();
    double SliceArea(double angle);
    double SlicePerimeter(double angle);
    double ArcLength(double angle);
};

#endif // GEOMETRY_H_INCLUDED
