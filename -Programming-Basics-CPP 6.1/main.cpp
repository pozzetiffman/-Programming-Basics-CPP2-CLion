#include <iostream>
using namespace std;

#include "math/math.h"
#include "output/output.h"

int main()
{
    double num1{}, num2{};
    double sum{};
    int choice{};

    while (true) {
        cout << "Введите первое число: " ;    cin  >> num1;
        cout << "Введите второе число: " ;    cin  >> num2;
        cout << "Выберите операцию (1 - сложение, 2 вычитание,"
                "3 - умножение, 4 - деление, 5 - возведение в степень): ";   cin  >> choice;

        switch (choice) {
            case 1: sum = add(num1, num2); printResult(sum); cout << endl;   break;
            case 2: sum = sub(num1, num2); printResult(sum); cout << endl;     break;
            case 3: sum = mult(num1, num2); printResult(sum); cout << endl;  break;
            case 4: sum = dev(num1, num2); printResult(sum); cout << endl;   break;
            case 5: sum = expon(num1, num2); printResult(sum); cout << endl; break;
        }
    }
}






