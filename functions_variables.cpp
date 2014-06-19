#include <cmath>
#include <iostream>

#define E 2.718281828459045235360287471352662497757247093699959574966967
//TO-DO: Add e, pi and other constants to a header

using namespace std;

class Var {
public:
    char letter;
    virtual double Value(double) = 0;
};

class Logarithm: public Var{
public:
    double base, coefficient, power;
    Logarithm(double base=E, char letter=' ', double power=1, double coefficient=1): base(base), power(power), coefficient(coefficient){
    this->letter = letter;
    }
    double Value(double variable){
        return (coefficient * log(pow(variable, power)) / log(base));
    }
};

class Exponential: public Var{
public:
    double coefficient, base;
    Exponential(double coefficient=1, double base=1, char letter=' '): coefficient(coefficient), base(base){
        this->letter = letter;
    }
    double Value(double variable){
        return (coefficient * pow(base, variable));
    }
};

class Variable: public Var{
public:
    double power, coefficient;
    Variable(double coefficient=0, char letter=' ', double power=0): power(power), coefficient(coefficient){
        this->letter = letter;
    }
    double Value(double variable){
        return (coefficient * pow(variable, power));
    }
};

struct LVal{
    char letter;
    double value;
};

class Function{
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
    Var* logTest = new Logarithm(9, 'x');
    Var* logDouble = new Logarithm(5.5, 'x', 2, 3);
    Var* expTest = new Exponential(3.5, 2, 'x');

    cout << "4x^2 at x = 3: " << testVar->Value(3) << endl
         << "4x^2 at x = 5: " << testVar->Value(5) << endl
         << "-2.3y^(-0.5) at y = 3.5: " << doubleVar->Value(3.5) << endl
         << "log9(x) at x = 3: " << logTest->Value(3) << endl
         << "3log5.5(x^2) at x= 4.6: " << logDouble->Value(4.6) << endl
         << "3.5*2^x at x = 3.5: " << expTest->Value(3.5) << endl;

    Var* vars[3] = {testVar, doubleVar, logTest};
    Function func(vars, 3);
    LVal values[2] = {LVal{'x', 3}, LVal{'y', 3.5}};
    double result = func.Value(values, 2);
    cout << "4x^2 - 2.3y^(-0.5) + log9(x) at x = 3, y = 3.5: " << result << endl;

    return 0;

}
