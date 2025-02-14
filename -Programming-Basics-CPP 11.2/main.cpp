#include <iostream>
#include "lib/leave_lib.h"


int main() {

    Leaver* leaver;
    std::string leavering;
    std::cout << "Введите имя: ";
    std::cin >> leavering;
    leaver = new Leaver(leavering);
    leaver->print_info();

    return 0;
}
