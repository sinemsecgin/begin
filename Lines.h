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

#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED

#include "definitions_includes.h"

struct point{
    double x, y;
};

class Line {
public:
    double x, y, m;
    std::string label;
    bool minf;
    Line(double x1=0, double y1=0, double x2=0, double y2=0, std::string label="");
    Line(double x=0, double y=0, double m=0, std::string label="");
};

point getIntersection(Line line1, Line line2);

#endif // LINES_H_INCLUDED
