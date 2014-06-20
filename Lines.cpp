#include "Lines.h"

Line::Line(double x1, double y1, double x2, double y2, std::string label):
                x(x1), y(y1), label(label){
    if ((x2 - x1) == 0){   //Division by 0
        minf = true;
        m = 0;
    }else{
        minf = false;
        m = (y2 - y1) / (x2 - x1);
    }
}

Line::Line(double x, double y, double m, std::string label):
                x(x), y(y), m(m), label(label){}

point getIntersection(Line line1, Line line2) {
    if (line1.minf && line2.minf) { //Lines are parallel
        return point();
    } else if (line1.minf) { //Handling infinite calculations
        return point {line1.x, (line1.x - line1.x)* line2.m + line2.y};
    } else if(line2.minf) {  //Handling infinite calculations
        return point {line2.x, (line2.x - line1.x)* line1.m + line1.y};
    } else { //lines intersect
        double x = ((line2.x * line2.m) - (line1.x * line1.m)
                    + line1.y - line2.y) / (line2.m - line1.m);
        return point {x, (x - line1.x)* line1.m + line1.y};
    }
}
