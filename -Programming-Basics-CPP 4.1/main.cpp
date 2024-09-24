#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Address {
private:
    string city;
    string street;
    int house;
    int apartment;

public:
    // Конструктор по умолчанию
    // Инициализирует переменные пустыми значениями и нулями
    Address() : city(""), street(""), house(0), apartment(0) {}

    // Конструктор с параметрами
    // Инициализирует переменные конкретными значениями, переданными в параметры
    Address(string city, string street, int house, int apartment) {
        this->city = city;          // Присваиваем переданный город
        this->street = street;      // Присваиваем переданную улицу
        this->house = house;        // Присваиваем номер дома
        this->apartment = apartment;// Присваиваем номер квартиры
    }

    // Метод для установки значений адреса (аналог конструктора с параметрами)
    // Он позволяет изменить существующий объект, передавая в него новые данные
    void setAddress(const string& city, const string& street, int house, int apartment) {
        this->city = city;          // Присваиваем город
        this->street = street;      // Присваиваем улицу
        this->house = house;        // Присваиваем номер дома
        this->apartment = apartment;// Присваиваем номер квартиры
    }

    // Статический метод для чтения данных из файла и создания массива адресов
    // Возвращает указатель на массив объектов Address
    static Address* AddAdressCount(const string& filename, int& count) {
        ifstream file(filename);  // Открываем файл для чтения
        if (!file.is_open()) {    // Проверяем, удалось ли открыть файл
            cerr << "File not opened" << endl;  // Сообщаем об ошибке
            return nullptr;       // Возвращаем nullptr при ошибке
        }

        // Чтение первого числа из файла - это количество адресов
        file >> count;
        // Создаем динамический массив объектов Address размером count
        Address* address = new Address[count];

        // Переменные для временного хранения значений из файла
        string city, street;
        int house, apartment;

        // Цикл для чтения данных об адресах
        for (int i = 0; i < count; i++) {
            file >> city >> street >> house >> apartment;  // Читаем город, улицу, дом, квартиру
            // Устанавливаем считанные значения в объект массива
            address[i].setAddress(city, street, house, apartment);
        }
        file.close();  // Закрываем файл
        return address;  // Возвращаем указатель на массив адресов
    }

    // Статический метод для переворота массива адресов (реверс)
    // Принимает указатель на массив address и количество count
    // Возвращает указатель на тот же массив, но уже перевернутый
    static Address* reverse(Address* address, int& count) {
        for (int i = 0; i < count / 2; i++) {
            // Обмен значениями между элементом i и его "зеркальным" элементом с конца
            Address temp = address[i];  // Сохраняем значение элемента i
            address[i] = address[count - 1 - i];  // Меняем местами
            address[count - 1 - i] = temp;  // Восстанавливаем значение с конца
        }
        return address;  // Возвращаем перевернутый массив
    }

    // Статический метод для записи массива адресов в файл
    // Принимает имя файла, указатель на массив address и количество адресов count
    static void AddAddressWriteDown(const string& filename, Address* address, int& count) {
        ofstream file(filename);  // Открываем файл для записи
        if (!file.is_open()) {    // Проверяем, удалось ли открыть файл
            cerr << "File not opened" << endl;
            return;  // Прерываем выполнение в случае ошибки
        }

        // Записываем количество адресов в файл
        file << count << endl;
        // Цикл для записи каждого адреса в файл
        for (int i = 0; i < count; i++) {
            // Записываем город, улицу, номер дома и квартиры
            file << address[i].city << " " << address[i].street << " "
                 << address[i].house << " " << address[i].apartment << endl;
        }
        file.close();  // Закрываем файл
    }

    // Метод для вывода адреса в консоль
    void display() {
        cout << "City: " << city << ", Street: " << street
             << ", House: " << house << ", Apartment: " << apartment << endl;
    }
};

int main() {
    int count;  // Переменная для хранения количества адресов
    // Загружаем адреса из файла "addresses.txt" и получаем указатель на массив Address
    // Address* address = Address::AddAdressCount("/Users/admin/Desktop/CLion/-Programming-Basics-CPP CLion/-Programming-Basics-CPP 4.1/cmake-build-debug/addresses.txt", count);
    Address* address = Address::AddAdressCount("addresses.txt", count);

    // Если загрузка данных прошла успешно (указатель не равен nullptr)
    if (address != nullptr) {
        cout << "Addresses loaded from file:" << endl;
        // Выводим все загруженные адреса на экран
        for (int i = 0; i < count; i++) {
            address[i].display();  // Вызываем метод display() для каждого объекта
        }

        // Переворачиваем массив адресов
        address = Address::reverse(address, count);

        // Записываем перевернутый массив в файл "out.txt"
        // Address::AddAddressWriteDown("/Users/admin/Desktop/CLion/-Programming-Basics-CPP CLion/-Programming-Basics-CPP 4.1/cmake-build-debug/out.txt", address, count);
        Address::AddAddressWriteDown("out.txt", address, count);

        // Удаляем динамически созданный массив для освобождения памяти
        delete[] address;
    } else {
        cerr << "File not opened" << endl;  // Выводим сообщение об ошибке, если файл не был открыт
    }

    return 0;
}