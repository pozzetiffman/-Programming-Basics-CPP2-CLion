#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Calculator {
    public:
    double num1;
    double num2;

    void input() {
        cout << "Enter one numbers: ";
        cin >> num1;
        cout << "Enter two numbers: ";
        cin >> num2;
    }
    double add() {
        return num1 + num2;
    }
    double multiply() {
        return num1 * num2;
    }
    double subtract_1_2() {
        return num1 - num2;
    }
    double subtract_2_1() {
        return num2 - num1;
    }
    double divide_1_2() {
        return num1 / num2;
    }
    double divide_2_1() {
        return num2 / num1;
    }
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else {
            return false;
        }
    }
    bool set_num2(double num2){
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

Calculator calculator;
    while (true) {

        calculator.input();

        if (!calculator.set_num1(calculator.num1)) {
            cout << "Error enter one numbers: ";
            cin >> calculator.num1;
        }
        if (!calculator.set_num2(calculator.num2)) {
            cout << "Error enter two numbers: ";
            cin >> calculator.num2;
        }
        cout << "add = " << calculator.add() << endl;
        cout << "multiply = " << calculator.multiply() << endl;
        cout << "subtract 1_2 = " << calculator.subtract_1_2() << endl;
        cout << "subtract 2_1 = " << calculator.subtract_2_1() << endl;
        cout << "divide 1_2 = " << calculator.divide_1_2() << endl;
        cout << "divide 2_1 = " << calculator.divide_2_1() << endl;
    }
    return 0;
}
