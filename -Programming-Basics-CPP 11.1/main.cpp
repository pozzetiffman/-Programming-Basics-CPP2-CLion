#include <iostream>
#include "lib/greeting_library.h"

int main() {

    Greeter* greeter;
    std::string greeting;
    std::cout << "Введите имя: ";
    std::cin >> greeting;
    greeter = new Greeter(greeting);
    greeter->print_info();

    return 0;
}
