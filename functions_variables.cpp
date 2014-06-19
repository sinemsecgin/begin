#include <cmath>
#include <iostream>

using namespace std;

class Var {
public:
    char letter;
    virtual double Value(double) = 0;
};

class Variable: public Var {
public:
    double power;
    double coefficient;
    Variable(double coefficient=0, char letter=' ', double power=0) {
        this->letter = letter;
        this->power = power;
        this->coefficient = coefficient;
    }
    double Value(double variable) {
        return (coefficient * pow(variable, power));
    }
};

struct LVal{
    char letter;
    double value;
};

class Function {
public:
    Var* *variables;
    unsigned int arraySize;
    Function(Var* variables[], unsigned int arraySize){
        this->variables = variables;
        this->arraySize = arraySize;
    }
    double Value(LVal values[], unsigned int valueSize){
        double value = 0;
        unsigned int var;
        unsigned int val;
        for (var=0; var<arraySize; var++){
            for (val=0; val<valueSize; val++){
                double tmp = values[val].value;

                if (values[val].letter == variables[var]->letter){
                    value += variables[var]->Value(values[val].value);
                }
            }
        }
        return value;
    }
};

int main(){
    Var* testVar = new Variable(4, 'x', 2 );            //4x^2
    Var* doubleVar = new Variable(-2.3, 'y', -0.5);    //(-2.3)x^(-0.5)

    cout << "4x^2 at x = 3: " << testVar->Value(3) << endl
         << "4x^2 at x = 5: " << testVar->Value(5) << endl
         << "-2.3y^(-0.5) at y = 3.5: " << doubleVar->Value(3.5) << endl;

    Var* vars[2] = {testVar, doubleVar};
    Function func(vars, 2);
    LVal values[2] = {LVal{'x', 3}, LVal{'y', 3.5}};
    double result = func.Value(values, 2);
    cout << "4x^2 - 2.3y^(-0.5) at x = 3, y = 3.5: " << result << endl;
    return 0;

}
