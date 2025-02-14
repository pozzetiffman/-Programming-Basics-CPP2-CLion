#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Counter {
private:
    int cislo;
public:
    Counter(int cislo) { this->cislo = cislo;}

    int getCislo() {return cislo;}
    void setCislo(int cs) {this->cislo = cs;}
};
int main() {
    string YesNo;
    string comand;
    int newCislo;

    Counter* CS = nullptr;

    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    // Используем getline для ввода строки
     getline(cin, YesNo);

    // Проверка ответа пользователя
    if (YesNo == "да" || YesNo == "Да" || YesNo == "ДА") {
        cout << "введите начальное значение счётчика: ";
        cin  >> newCislo;
        CS = new Counter(newCislo);
    }
    else if (YesNo == "нет" || YesNo == "Нет"|| YesNo == "НЕТ") {
        cout << "при отказе начальное значение установлено 0 : \n";
        CS = new Counter(0);
    }
    else {
        // Если введен неверный ответ, программа завершится
        cout << "не верно! программа завершена"; return 0;
    }
    while (true) {
        cout << "ведите команду ('+', '-', '=' или 'x'): ";
        cin >> comand;
        // Игнорируем оставшиеся символы в строке после ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Если команда '+', увеличиваем счетчик
        if (comand == "+") { CS->setCislo(CS->getCislo() + 1);}
        // Если команда '-', уменьшаем счетчик
        else if (comand == "-") { CS->setCislo(CS->getCislo() - 1);}
        // Если команда '=', отображаем текущее значение счетчика
        else if (comand == "=") { cout << "текущие число счетчика "<< CS->getCislo() << endl;}
        // Если команда 'x', завершаем программу
        else if (comand == "x" || comand == "X" || comand == "х" || comand == "Х") { cout << "программа завершена"; break;}
        // Если введена неверная команда
        else { cout << "Неверная команда. Попробуйте снова." << endl;}
    }
    // удоляем память
    delete CS;
    return 0;
}