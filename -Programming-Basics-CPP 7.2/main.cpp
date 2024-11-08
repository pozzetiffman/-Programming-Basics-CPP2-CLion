#include <iostream>
#define _SUB(a,b)(a -(b))

int main() {
    int a = 6;
    int b = 5;
    int c = 2;
    std::cout << _SUB(a, b)<< std::endl;
    std::cout << _SUB(a, b) * c << std::endl;
    std::cout << _SUB(a, b + c) * c << std::endl;
}
