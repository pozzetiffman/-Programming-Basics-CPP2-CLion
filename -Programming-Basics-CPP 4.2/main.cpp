#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class Address {
private:
    string city;
    string street;
    int house;
    int apartment;

public:
    Address() : city(""), street(""), house(0), apartment(0) {}  // Конструктор по умолчанию  Инициализирует переменные пустыми значениями и нулями

    Address(string city, string street, int house, int apartment) { // Конструктор с параметрами Инициализирует переменные конкретными значениями, переданными в параметры
        this->city = city;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }

    // Метод для установки значений адреса (аналог конструктора с параметрами) Он позволяет изменить существующий объект, передавая в него новые данные
    void setAddress(const string& city, const string& street, int house, int apartment) {
        this->city = city;          // Присваиваем город
        this->street = street;      // Присваиваем улицу
        this->house = house;        // Присваиваем номер дома
        this->apartment = apartment;// Присваиваем номер квартиры
    }

    string getCiti () const {
        return city;
    }

    // Статический метод для чтения данных из файла и создания массива адресов Возвращает указатель на массив объектов Address
    static Address* AddAdressCount(const string& filename, int& count) {
        ifstream file(filename);  // Открываем файл для чтения
        if (!file.is_open()) {    // Проверяем, удалось ли открыть файл
            cerr << "File not opened" << endl;  // Сообщаем об ошибке
            return nullptr;       // Возвращаем nullptr при ошибке
        }
        file >> count;  // Чтение первого числа из файла - это количество адресов
        Address* address = new Address[count];// Создаем динамический массив объектов Address размером count

        // Переменные для временного хранения значений из файла
        string city, street;
        int house, apartment;

        for (int i = 0; i < count; i++) { // Цикл для чтения данных об адресах
            file >> city >> street >> house >> apartment;  // Читаем город, улицу, дом, квартиру
            address[i].setAddress(city, street, house, apartment);  // Устанавливаем считанные значения в объект массива
        }
        file.close();  // Закрываем файл
        return address;  // Возвращаем указатель на массив адресов
    }

    // Этот метод сортирует массив адресов по названию городов в алфавитном порядке, используя стандартную функцию sort() с лямбда-функцией для сравнения городов.
    static Address* sortAddress (Address* address, int& count) {
        sort(address, address + count, [](const Address& a, const Address& b) {return a.getCiti() < b.getCiti(); });
        return address;
    }

    // Статический метод для записи массива адресов в файл Принимает имя файла, указатель на массив address и количество адресов count
    static void AddAddressWriteDown(const string& filename, Address* address, int& count) {
        ofstream file(filename);  // Открываем файл для записи
        if (!file.is_open()) {    // Проверяем, удалось ли открыть файл
            cerr << "File not opened" << endl;
            return;  // Прерываем выполнение в случае ошибки
        }
        file << count << endl; // Записываем количество адресов в файл
        for (int i = 0; i < count; i++) {// Цикл для записи каждого адреса в файл
            file << address[i].city << " " << address[i].street << " "
                 << address[i].house << " " << address[i].apartment << endl;// Записываем город, улицу, номер дома и квартиры
        }
        file.close();  // Закрываем файл
    }
    void display() { // Метод для вывода адреса в консоль
        cout << "City: " << city << ", Street: " << street
             << ", House: " << house << ", Apartment: " << apartment << endl;
    }
};

int main() {
    int count;  // Переменная для хранения количества адресов
    // Загружаем адреса из файла "addresses.txt" и получаем указатель на массив Address
    // Address* address = Address::AddAdressCount("/Users/admin/Desktop/CLion/-Programming-Basics-CPP CLion/-Programming-Basics-CPP 4.1/cmake-build-debug/addresses.txt", count);
    Address* address = Address::AddAdressCount("addresses.txt", count);

    if (address != nullptr) { // Если загрузка данных прошла успешно (указатель не равен nullptr)
        cout << "Addresses loaded from file:" << endl <<  "before sorting" << endl; // Выводим все загруженные адреса на экран до сортировки
        for (int i = 0; i < count; i++) {
            address[i].display();  // Вызываем метод display() для каждого объекта
        }
        address = Address::sortAddress(address, count);

        cout << "Sorted addresses:" << endl;
        for (int i = 0; i < count; i++) {   // Выводим все загруженные адреса на экран после сортировки
            address[i].display();  // Вызываем метод display() для каждого объекта
        }
        // Записываем перевернутый массив в файл "out.txt"
        // Address::AddAddressWriteDown("/Users/admin/Desktop/CLion/-Programming-Basics-CPP CLion/-Programming-Basics-CPP 4.1/cmake-build-debug/out.txt", address, count);
        Address::AddAddressWriteDown("out.txt", address, count);
        cout << "file data overwritten" << endl;  // Выводим сообщение что файл перезаписан

        delete[] address;  // Удаляем память
    } else {
        cerr << "File not opened" << endl;  // Выводим сообщение об ошибке, если файл не был открыт
    }

    return 0;
}
