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







/*
The problem with this code is, it supports use of multiple variables in an incomplete way.
While the Value() methods should work correctly while using multiple variables, such as x^2 + 3y, Derivative() and Integral() methods will be incorrect.
Either the whole code should be modified to support only one variable, and as a result do calculations only in 2D space, or support for partial derivatives should be added and integrals should be corrected.
*/
#include "Functions.h"

//-----------------------------Var-------------------------------
Var::Var(std::string letter): letter(letter + ";"){}

double Var::Value(LVal values[], unsigned int valueSize){
    unsigned int i;
    for (i=0; i<valueSize; i++){
        if (letter.find(values[i].letter + ";") != std::string::npos){
            return Value(values[i].value);
        }
    }
    return 0;
}


//-----------------------------Logarithm-------------------------------
Logarithm::Logarithm(double base, std::string letter, double power, double outerCoefficient, double innerCoefficient):
                        Var(letter), base(base), outerCoefficient(outerCoefficient), innerCoefficient(innerCoefficient), power(power){}

double Logarithm::Value(double variable){
    return (outerCoefficient * log(innerCoefficient * pow(variable, power)) / log(base));
}

Var* Logarithm::Derivative(){
    return new Variable(power * outerCoefficient, letter, -1);
}

Var* Logarithm::Integral(){
    Var* temp1[2] = {new Variable(power * -1, letter, 0), this};
    Var* temp2[2] = {new Function(temp1, 2),
                     new Variable(outerCoefficient, letter, 1)};
    return new MultiplyVar(temp2, 2);
}


//-----------------------------Exponential-------------------------------
Exponential::Exponential(double coefficient, double base, double power, std::string letter):
                            Var(letter), coefficient(coefficient), base(base), power(power){}

double Exponential::Value(double variable){
    return (coefficient * pow(base, pow(variable, power)));
}

Var* Exponential::Derivative(){
    Var* temp[2] = {new Variable(power * log(base), letter, power - 1),
                    this};
    return new MultiplyVar(temp, 2);
}

Var* Exponential::Integral(){
    return NULL;       //TO-DO: Add incomplete gamma function class, see https://www.gnu.org/software/gsl/manual/html_node/Incomplete-Gamma-Functions.html#Incomplete-Gamma-Functions and http://www.wolframalpha.com/input/?i=integral+of+5*2^%28x^3%29
}


//-----------------------------Variable-------------------------------
Variable::Variable(double coefficient, std::string letter, double power):
                    Var(letter), power(power), coefficient(coefficient){}

double Variable::Value(double variable){
    return (coefficient * pow(variable, power));
}

Var* Variable::Derivative(){
    return new Variable(coefficient * power,
                    letter,
                    power - 1);
}

Var* Variable::Integral(){
    return new Variable((coefficient / (power + 1)),
                    letter,
                    power + 1);
}


//-----------------------------MultiplyVar-------------------------------
MultiplyVar::MultiplyVar(Var* variables[], unsigned int arraySize):
                        Var(""), variables(variables), arraySize(arraySize){
    unsigned int i;
    for (i=0; i<arraySize; i++){
        letter += variables[i]->letter + ";";
    }
}

double MultiplyVar::Value(LVal values[], unsigned int valueSize){
    double value = 1;
    unsigned int var;
    unsigned int val;
    for (var=0; var<arraySize; var++){
        for (val=0; val<valueSize; val++){
            if (values[val].letter.find(variables[var]->letter + ";") != std::string::npos){
                value *= variables[var]->Value(values[val].value);
            }
        }
    }
    return value;
}

double MultiplyVar::Value(double variable){
    return 0;       //TO-DO:
}

Var* MultiplyVar::Derivative(){
    Var* fin[arraySize];
    Var* temp[arraySize];
    unsigned int inner, outer;
    for (outer=0; outer<arraySize; outer++){
        for (inner=0; inner<arraySize; inner++){
            if (outer == inner){
                temp[inner] = variables[inner]->Derivative();
            }else{
                temp[inner] = variables[inner];
            }
        }
        fin[outer] = new MultiplyVar(temp, arraySize);
    }
    return new Function(fin, arraySize);
}

Var* MultiplyVar::Integral(){
    return NULL;        //TO-DO:
}


//-----------------------------Function-------------------------------
Function::Function(Var* variables[], unsigned int arraySize):
                    Var(""), variables(variables), arraySize(arraySize){}

double Function::Value(LVal values[], unsigned int valueSize){
    double value = 0;
    unsigned int var;
    unsigned int val;
    for (var=0; var<arraySize; var++){
        for (val=0; val<valueSize; val++){
            if (values[val].letter.find(variables[var]->letter + ";") != std::string::npos){
                value += variables[var]->Value(values[val].value);
            }
        }
    }
    return value;
}

double Function::Value(double value){
    return 0;   //TO-DO:
}

Var* Function::Derivative(){
    unsigned int i;
    Var* derivative[arraySize];
    for (i=0; i<arraySize; i++){
        derivative[i] = variables[i]->Derivative();
    }
    return new Function(derivative, arraySize);
}

Var* Function::Integral(){
    return NULL;    //TO-DO:
}
