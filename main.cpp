#include <iostream>
#include "Geometry.h"
#include "Functions.h"
#include "Lines.h"

using namespace std;

int main()
{
    Var* testVar = new Variable(4, "x", 2 ); //4x^2
    Var* doubleVar = new Variable(-2.3, "y", -0.5); //(-2.3)x^(-0.5)
    Var* logTest = new Logarithm(9, "x");
    Var* logDouble = new Logarithm(5.5, "x", 2, 3);
    Var* expTest = new Exponential(3.5, 2, "x");

    cout << "4x^2 at x = 3: " << testVar->Value(3) << endl
         << "4x^2 at x = 5: " << testVar->Value(5) << endl
         << "-2.3y^(-0.5) at y = 3.5: " << doubleVar->Value(3.5) << endl
         << "log9(x) at x = 3: " << logTest->Value(3) << endl
         << "3log5.5(x^2) at x= 4.6: " << logDouble->Value(4.6) << endl
         << "3.5*2^x at x = 3.5: " << expTest->Value(3.5) << endl;

    cout << "\n\n";

    Var* vars[3] = {testVar, doubleVar, logTest};
    Function func(vars, 3);
    LVal values[2] = {LVal{"x", 3}, LVal{"y", 3.5}};
    double result = func.Value(values, 2);
    cout << "4x^2 - 2.3y^(-0.5) + log9(x) at x = 3, y = 3.5: " << result << endl;

    Line line1(0, 0, 3, 3, "A"); //Line 'A' passing through (0, 0) and (3, 3)
    Line line2(3, 0, 0, 3, "B"); //Line 'B' passing through (3, 0) and (0, 3)
    Line line3(-6, -3, -0.5, "C"); //Line 'C' with slope -0.5, passing through (-6, -3)
    point intersect1 = getIntersection(line1, line2);
    point intersect2 = getIntersection(line1, line3);
    point intersect3 = getIntersection(line2, line3);
    cout << "Intersection points: \n"
         << "A and B at (" << intersect1.x << ", " << intersect1.y << ")\n"
         << "A and C at (" << intersect2.x << ", " << intersect2.y << ")\n"
         << "B and C at (" << intersect3.x << ", " << intersect3.y << ")\n";

    cout << "\n\n";

    RegularPolygon triangle(6, 6);
    RegularPolygon rectangle(6, 6);
    RegularPolygon pentragon(6, 6);
    RegularPolygon hexagon(6, 6);
    Trapezoid trape(6,6,5);
    Sphere sp(6);
    Parallelogram pa(6,9);
    Cylinder cy(6,5);
    cout << "Area of geometric shapes :\n"
         << "Triangle: " << triangle.Area() << endl
         << "Rectangle: " << rectangle.Area() << endl
         << "Pentagon: " << pentragon.Area() << endl
         << "Hexagon: " << hexagon.Area() << endl
         <<"Trapezoid: "<<trape.Area()<<endl
         <<"Sphere : "<<sp.Area()<<endl
         <<"Parallelogram : "<<pa.Area()<<endl
         <<"Cylindir Surface Area: "<<cy.Area()<<endl
         <<"Cylindir Volume : "<<cy.Volume()<<endl;
    return 0;
}
