//
// Created by admin on 30.01.2025.
//

#ifndef LEAVE_LIB_H
#define LEAVE_LIB_H
#include <string>


class Leaver {
    protected:
    std::string leave;

    public:
    explicit Leaver(std::string leave);

    std::string get_Leave();

    void print_info();
};




#endif //LEAVE_LIB_H
