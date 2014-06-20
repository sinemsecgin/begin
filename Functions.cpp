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
