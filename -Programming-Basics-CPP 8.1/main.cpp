#include <iostream>

int function(std::string str, int forbidden_length) {
   if (str.length() > forbidden_length) {
       throw std::invalid_argument("Вы ввели слово запретной длины! До свидания");
   }
}

int function_length (std::string str, int forbidden_length) {
    std::cout << "Длина слова "<< "["<< str << "]"  << " равна " << "[" << str.length()<< "]"<< std::endl;
}

int main() {
    std::string name;
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> name;
        function(name, forbidden_length);
        function_length(name, forbidden_length);
        if (!function(name, forbidden_length)) {
            return 0;
        }
    }
}
