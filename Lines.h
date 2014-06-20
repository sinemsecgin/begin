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
