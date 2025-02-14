//
// Created by admin on 8.11.2024.
//

#ifndef CHECKING_FOR_ERRORS_H
#define CHECKING_FOR_ERRORS_H
#include <stdexcept>

class checking_for_errors :  public std::domain_error {
public:
    explicit checking_for_errors (const std::string& message);
};
#endif //CHECKING_FOR_ERRORS_H
