#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Calculator {
    public:
    // Переменные для хранения двух чисел
    double num1;
    double num2;

    // Метод для ввода двух чисел
    void input() {
        cout << "Enter one number: ";
        cin >> num1; // Ввод первого числа
        cout << "Enter two numbers: ";
        cin >> num2; // Ввод второго числа
    }

    // Метод для сложения двух чисел
    double add() {
        return num1 + num2; // Возвращает сумму двух чисел
    }

    // Метод для умножения двух чисел
    double multiply() {
        return num1 * num2; // Возвращает произведение двух чисел
    }

    // Метод для вычитания второго числа из первого
    double subtract_1_2() {
        return num1 - num2; // Возвращает результат вычитания второго числа из первого
    }

    // Метод для вычитания первого числа из второго
    double subtract_2_1() {
        return num2 - num1; // Возвращает результат вычитания первого числа из второго
    }

    // Метод для деления первого числа на второе
    double divide_1_2() {
        return num1 / num2; // Возвращает результат деления первого числа на второе
    }

    // Метод для деления второго числа на первое
    double divide_2_1() {
        return num2 / num1; // Возвращает результат деления второго числа на первое
    }

    // Метод для установки значения первого числа
    bool set_num1(double num1) {
        if (num1 != 0) { // Проверяем, что переданное число не равно нулю
            this->num1 = num1; // Устанавливаем значение переменной num1
            return true; // Возвращаем true, если установка прошла успешно
        }
        else {
            return false; // Возвращаем false, если число равно нулю
        }
    }

    // Метод для установки значения второго числа
    bool set_num2(double num2){
        if (num2 != 0) { // Проверяем, что переданное число не равно нулю
            this->num2 = num2; // Устанавливаем значение переменной num2
            return true; // Возвращаем true, если установка прошла успешно
        }
        else {
            return false; // Возвращаем false, если число равно нулю
        }
    }
};

int main() {
    Calculator calculator; // Создаем объект калькулятора
    while (true) { // Бесконечный цикл
        calculator.input(); // Вводим два числа

        // Проверяем, что первое число не равно нулю
        if (!calculator.set_num1(calculator.num1)) {
            cout << "Error enter one numbers: ";
            cin >> calculator.num1; // Если первое число равно нулю, просим ввести его заново
        }

        // Проверяем, что второе число не равно нулю
        if (!calculator.set_num2(calculator.num2)) {
            cout << "Error enter two numbers: ";
            cin >> calculator.num2; // Если второе число равно нулю, просим ввести его заново
        }

        // Выполняем и выводим результаты операций
        cout << "add = " << calculator.add() << endl; // Сложение
        cout << "multiply = " << calculator.multiply() << endl; // Умножение
        cout << "subtract 1_2 = " << calculator.subtract_1_2() << endl; // Вычитание второго из первого
        cout << "subtract 2_1 = " << calculator.subtract_2_1() << endl; // Вычитание первого из второго
        cout << "divide 1_2 = " << calculator.divide_1_2() << endl; // Деление первого числа на второе
        cout << "divide 2_1 = " << calculator.divide_2_1() << endl; // Деление второго числа на первое
    }
    return 0; // Завершение программы
}