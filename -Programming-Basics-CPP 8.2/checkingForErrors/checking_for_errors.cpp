//
// Created by admin on 8.11.2024.
//
#include <string>
#include "checking_for_errors.h"

checking_for_errors::checking_for_errors(const std::string& message)
    : std::domain_error(message){}
