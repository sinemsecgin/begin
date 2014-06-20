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


Exponential::Exponential(double coefficient, double base, std::string letter):
                            coefficient(coefficient), base(base), Var(letter){}

double Exponential::Value(double variable){
    return (coefficient * pow(base, variable));
}


Variable::Variable(double coefficient, std::string letter, double power):
                    power(power), coefficient(coefficient), Var(letter){}

double Variable::Value(double variable){
    return (coefficient * pow(variable, power));
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
