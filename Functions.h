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

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "definitions_includes.h"

struct LVal{
    std::string letter;
    double value;
};

class Var{
public:
    std::string letter;
    Var(std::string letter="");
    virtual double Value(LVal values[], unsigned int valueSize);
    virtual double Value(double value)=0;
    virtual Var* Derivative()=0;
    virtual Var* Integral()=0;
};

class Logarithm: public Var{
public:
    double base, outerCoefficient, innerCoefficient, power;
    Logarithm(double base=E, std::string letter="", double power=1, double outerCoefficient=0, double innerCoefficient=1);
    double Value(double variable);
    Var* Derivative();
    Var* Integral();
};

class Exponential: public Var{
public:
    double coefficient, base, power;
    Exponential(double coefficient=1, double base=1, double power=0, std::string letter="");
    double Value(double variable);
    Var* Derivative();
    Var* Integral();
};

class Variable: public Var{
public:
    double power, coefficient;
    Variable(double coefficient=0, std::string letter="", double power=0);
    double Value(double variable);
    Var* Derivative();
    Var* Integral();
};

class MultiplyVar: public Var{
public:
    Var* *variables;
    unsigned int arraySize;
    MultiplyVar(Var* variables[], unsigned int arraySize);
    double Value(LVal values[], unsigned int valueSize);
    double Value(double value);
    Var* Derivative();
    Var* Integral();
};

class Function: public Var{
public:
    Var* *variables;
    unsigned int arraySize;
    Function(Var* variables[], unsigned int arraySize);
    double Value(LVal values[], unsigned int valueSize);
    double Value(double value);
    Var* Derivative();
    Var* Integral();
};

#endif // FUNCTIONS_H_INCLUDED
