#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Counter {
    private:
    int count;  // Счетчик
    char team;  // Команда ('+', '-', '=' или 'x')
    string YesNo;  // Ответ пользователя для указания начального значения счетчика

    public:
    // Конструктор по умолчанию, инициализирует начальные значения
    Counter() : count(0), team(' '), YesNo("да") {}

    // Конструктор с параметрами, использует ссылку на строку для оптимизации
    Counter(char s, int y, const string& n) {
        count = y;
        team = s;
        YesNo = n;
    }

    // Метод для увеличения счетчика
    void increment() {count++;}

    // Метод для уменьшения счетчика
    void decrement() {count--;}

    // Метод для отображения текущего значения счетчика
    void display () {cout << "текущие число счетчика: "<< count << endl;}

    // Метод для ввода команды пользователя
    void inputTeam () {
        cout << "ведите команду ('+', '-', '=' или 'x'): ";
        cin >> team;
        // Игнорируем оставшиеся символы в строке после ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Метод для ввода начального значения счетчика, а также обработки "да/нет" от пользователя
    void inputCommand () {
        cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        // Используем getline для ввода строки
        getline(cin, YesNo);

        // Проверка ответа пользователя
        if (YesNo == "да" || YesNo == "Да" || YesNo == "ДА") {
            cout << "введите начальное значение счётчика: ";
            cin  >> count;
        }
        else if (YesNo == "нет" || YesNo == "Нет"|| YesNo == "НЕТ") {
            cout << "при отказе начальное значение установлено 0 : \n";
        }
        else {
            // Если введен неверный ответ, программа завершится
            cout << "не верно! программа завершена, не дури голову";
            exit (0);
        }
    }

    // Метод для получения значения счетчика
    [[nodiscard]] int getCount () const {return count;}

    // Метод для установки значения счетчика
    void setCount (int Ct) {count = Ct;}

    // Метод для получения команды
    [[nodiscard]] char getTeam () const {return team;}

    // Метод для установки команды
    void setTeam (char Tm) {team = Tm;}

    // Метод для получения строки с ответом "да/нет"
    [[nodiscard]] string getYesNo () const {return YesNo;}

    // Метод для установки строки с ответом "да/нет"
    void setYesNo (char Yn) {YesNo = Yn;}

    // Метод обработки команды
    bool set_count() {
        if (team == '+') { // Если команда '+', увеличиваем счетчик
            increment();
            return true;
        }
        else if (team == '-') { // Если команда '-', уменьшаем счетчик
            decrement();
            return true;
        }
        else if (team == '=') { // Если команда '=', отображаем текущее значение счетчика
            display();
            return true;
        }
        else if (team == 'x' || team == 'X') { // Если команда 'x', завершаем программу
            cout << "программа завершена";
            return false;
        }
        else {
            // Если введена неверная команда
            cout << "Неверная команда. Попробуйте снова." << endl;
            return true;
        }
    }
};

int main() {
    Counter counter; // Создаем объект класса Counter
    counter.inputCommand(); // Запрашиваем у пользователя начальное значение счетчика

    // Цикл для ввода команд до тех пор, пока пользователь не введет 'x' для выхода
    while (true) {
        counter.inputTeam(); // Запрашиваем команду
        if (!counter.set_count()) { // Обрабатываем команду и проверяем, если команда 'x' - выйти из цикла
            break;
        }
    }
    return 0;
}