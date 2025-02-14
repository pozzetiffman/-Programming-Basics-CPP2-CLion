//
// Created by admin on 30.01.2025.
//
#include <string>

#ifndef GREETING_LIBRARY_H
#define GREETING_LIBRARY_H

class Greeter {
    protected:
    std::string greet;

    public:
    explicit Greeter(std::string greet);

    [[nodiscard]] std::string get_greet() const;

    void print_info() const ;
};

#endif //GREETING_LIBRARY_H
