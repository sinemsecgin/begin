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
    virtual double Value(double variable)=0;
};

class Logarithm: public Var{
public:
    double base, coefficient, power;
    Logarithm(double base=E, std::string letter="", double power=1, double coefficient=1);
    double Value(double variable);
};

class Exponential: public Var{
public:
    double coefficient, base;
    Exponential(double coefficient=1, double base=1, std::string letter="");
    double Value(double variable);
};

class Variable: public Var{
public:
    double power, coefficient;
    Variable(double coefficient=0, std::string letter="", double power=0);
    double Value(double variable);
};

class Function{
public:
    Var* *variables;
    unsigned int arraySize;
    Function(Var* variables[], unsigned int arraySize);
    double Value(LVal values[], unsigned int valueSize);
};

#endif // FUNCTIONS_H_INCLUDED
