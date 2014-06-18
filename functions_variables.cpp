class Variable {
public:
    char letter;
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
    Variable* variables;
    unsigned int arraySize;
    Function(Variable variables[], unsigned int arraySize){
        this->variables = variables;
        this->arraySize = arraySize;
    }
    double Value(LVal values[], unsigned int valueSize){
        double value = 0;
        unsigned int var;
        unsigned int val;
        for (var=0; var<arraySize; var++){
            for (val=0; val<valueSize; val++){
                if (values[val].letter == variables[var].letter){
                    value += variables[var].Value(values[val].value);
                }
            }
        }
        return value;
    }
};

int main(){
    Variable testVar(4, 'x', 2 );  //4x^2
    Variable doubleVar(-2.3, 'y', -0.5);    //(-2.3)x^(-0.5)

    cout << "4x^2 at x = 3: " << testVar.Value(3) << endl
         << "4x^2 at x = 5: " << testVar.Value(5) << endl
         << "-2.3y^(-0.5) at y = 3.5: " << doubleVar.Value(3.5) << endl;

    Variable vars[2] = {testVar, doubleVar};
    Function func(vars, 2);
    LVal values[2] = {LVal{'x', 3}, LVal{'y', 3.5}};
    double result = func.Value(values, 2);
    cout << "4x^2 - 2.3y^(-0.5) at x = 3, y = 3.5: " << result << endl;
    return 0;

}