#include <iostream>
#define _MODE 1

#ifndef _MODE
#error "необъодимо определить _MODE"
#endif

#if _MODE == 1
int add (int a,int b) {
    return a + b;
}
#endif

int main()
{

    #if _MODE == 0
    std:: cout << "работаю в тренеровочном режиме" << std::endl;
    #endif

    #if _MODE == 1
    std::cout << "работаю в боевом режиме" << std::endl;
    int num1{}, num2{};
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    std::cout << "Результат сложения: " << add(num1,num2) << std::endl;
#endif

    return 0;
}
