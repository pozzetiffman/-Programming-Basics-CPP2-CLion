//
// Created by admin on 1.11.2024.
//

#ifndef RHOMB_H
#define RHOMB_H

#include "TargetConditionals.h"
#include "../The_quadrilateral/The_quadrilateral.h"

class Rhomb : public The_quadrilateral{
    public:
    Rhomb(int side_a, int side_b, int side_c, int side_d, int corner_A, int corner_B, int corner_C, int corner_D);
    void print_info() const override;
};

#endif //RHOMB_H
