#include <iostream>
#include <string>

using namespace std;

class Line{
    public:
        double x, y, m;
        string label;
        bool minf;
        Line(double x1=0, double y1=0, double x2=0, double y2=0, string label=""){
            x = x1;
            y = y1;
            this->label = label;
            if ((x2 - x1) == 0){    //Division by 0
                minf = true;
                m = 0;
            }else{
                minf = false;
                m = (y2 - y1)/(x2 - x1);
            }
        }
        Line(double x=0, double y=0, double m=0, string label=""){
            this->x = x;
            this->y = y;
            this->m = m;
            this->label = label;
        }
};

struct point{
double x, y;
};

point getIntersection(Line line1, Line line2){
    if (line1.minf && line2.minf){  //Lines are parallel
        return point();
    }else if (line1.minf){  //Handling infinite calculations
        return point{line1.x, (line1.x - line1.x) * line2.m + line2.y};
    }else if(line2.minf){   //Handling infinite calculations
        return point{line2.x, (line2.x - line1.x) * line1.m + line1.y};
    }else{  //lines intersect
        double x = ((line2.x * line2.m) - (line1.x * line1.m)
                    + line1.y - line2.y) / (line2.m - line1.m);
        return point{x, (x - line1.x) * line1.m + line1.y};
    }
}

int main()
{
    Line line1(0, 0, 3, 3, "A");    //Line 'A' passing through (0, 0) and (3, 3)
    Line line2(3, 0, 0, 3, "B");    //Line 'B' passing through (3, 0) and (0, 3)
    Line line3(-6, -3, -0.5, "C");  //Line 'C' with slope -0.5, passing through (-6, -3)
    point intersect1 = getIntersection(line1, line2);
    point intersect2 = getIntersection(line1, line3);
    point intersect3 = getIntersection(line2, line3);
    cout << "Intersection points: \n"
         << "A and B at (" << intersect1.x << ", " << intersect1.y << ")\n"
         << "A and C at (" << intersect2.x << ", " << intersect2.y << ")\n"
         << "B and C at (" << intersect3.x << ", " << intersect3.y << ")\n";
    return 0;
}
