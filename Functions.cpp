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

#include "Functions.h"

Var::Var(std::string letter): letter(letter){}

Logarithm::Logarithm(double base, std::string letter, double power, double coefficient):
                        Var(letter), base(base), power(power), coefficient(coefficient){}

double Logarithm::Value(double variable){
    return (coefficient * log(pow(variable, power)) / log(base));
}

Var* Logarithm::Derivative(){
    return new Logarithm();     //TO-DO: ADD THESE LATER!
}

Var* Logarithm::Integral(){
    return new Logarithm();     //TO-DO: ADD THESE LATER!
}

Exponential::Exponential(double coefficient, double base, std::string letter):
                            coefficient(coefficient), base(base), Var(letter){}

double Exponential::Value(double variable){
    return (coefficient * pow(base, variable));
}

Var* Exponential::Derivative(){
    return new Exponential();       //TO-DO: ADD THESE LATER!
}

Var* Exponential::Integral(){
    return new Exponential();       //TO-DO: ADD THESE LATER!
}

Variable::Variable(double coefficient, std::string letter, double power):
                    power(power), coefficient(coefficient), Var(letter){}

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

Function::Function(Var* variables[], unsigned int arraySize): variables(variables), arraySize(arraySize){}

double Function::Value(LVal values[], unsigned int valueSize){
    double value = 0;
    unsigned int var;
    unsigned int val;
    for (var=0; var<arraySize; var++){
        for (val=0; val<valueSize; val++){
            if (values[val].letter == variables[var]->letter){
                value += variables[var]->Value(values[val].value);
            }
        }
    }
    return value;
}

Function Function::Derivative(){
    unsigned int i;
    Var* derivative[arraySize];
    for (i=0; i<arraySize; i++){
        derivative[i] = variables[i]->Derivative();
    }
    return Function(derivative, arraySize);
}
