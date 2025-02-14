//
// Created by admin on 1.11.2024.
//

#ifndef FIGURE_H
#define FIGURE_H
#include <string>

class Figure {
    protected:
    std::string name;
    public:
    explicit Figure(std::string f_name);
    virtual void print_info() const;
};

#endif //FIGURE_H
