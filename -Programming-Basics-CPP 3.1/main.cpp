#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Calculator {
private:
    double num1;
    double num2;
public: // конструктор
    Calculator(double num1, double num2) {
        this->num1 = num1;
        this->num2 = num2;
    }
    Calculator() : num1(1), num2(1) { }

    // Метод для вычисления
    double add()          {return num1 + num2; } // Возвращает сумму двух чисел
    double multiply()     {return num1 * num2; } // Возвращает произведение двух чисел
    double subtract_1_2() {return num1 - num2; } // Возвращает результат вычитания второго числа из первого
    double subtract_2_1() {return num2 - num1; } // Возвращает результат вычитания первого числа из второго
    double divide_1_2()   {return num1 / num2; } // Возвращает результат деления первого числа на второе
    double divide_2_1()   {return num2 / num1; } // Возвращает результат деления второго числа на первое

    // Метод для установки значения первого числа
    bool set_num1(double num1) {
        if (cin.fail()) { // Проверяем, что введено корректное число
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
            cout << "Error: Please enter a valid number." << endl;
            return false;
        }// если число = 0 ошибка
        if (num1 == 0) {
            cout << "Error: num1 cannot be zero." << endl;
            return false;
        }
        this->num1 = num1; // присвоение
        return true;
    }
    // Метод для установки значения второго числа
    bool set_num2(double num2){
        if (cin.fail()) { // Проверяем, что введено корректное число
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
            cout << "Error: Please enter a valid number." << endl;
            return false;
        } // если число = 0 ошибка
        if (num2 == 0) {cout << "Error: num2 cannot be zero." << endl;
            return false;
        }
        this->num2 = num2; // присвоение
        return true;
    }
};
int main() {
    double num1, num2;
    Calculator calculator; // Создаем объект калькулятора

    while (true) { // Бесконечный цикл
        cout << "Enter the first number: "; cin >> num1;
        if (!calculator.set_num1(num1)) {continue;}

        cout << "Enter the second number: "; cin >> num2;
        if (!calculator.set_num2(num2)) {continue;}

        // Выполняем и выводим результаты операций
        cout << "add = " << calculator.add() << endl; // Сложение
        cout << "multiply = " << calculator.multiply() << endl; // Умножение
        cout << "subtract 1_2 = " << calculator.subtract_1_2() << endl; // Вычитание второго из первого
        cout << "subtract 2_1 = " << calculator.subtract_2_1() << endl; // Вычитание первого из второго
        cout << "divide 1_2 = " << calculator.divide_1_2() << endl; // Деление первого числа на второе
        cout << "divide 2_1 = " << calculator.divide_2_1() << endl; // Деление второго числа на первое
    }
    return 0;
}