//
// Created by admin on 1.11.2024.
//

#ifndef A_RIGHT_ANGLED_RIANGLE_H
#define A_RIGHT_ANGLED_RIANGLE_H
#include "../Triangle/Triangle.h"


class A_right_angled_riangle : public Triangle {
    public:
    A_right_angled_riangle(int side_a, int side_b, int side_c, int corner_A, int corner_B, int corner_C);
    void print_info() const override;
};


#endif //A_RIGHT_ANGLED_RIANGLE_H
