
/* Include Guard */

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <bits/stdc++.h>

class UnderflowException final: public std::exception {
public:
    UnderflowException() noexcept = default;
    ~UnderflowException() final = default;

    const char* what() const noexcept final {
        return "Underflow Condition";
    }
};

class OverflowException final: public std::exception {
public:
    OverflowException() noexcept = default;
    ~OverflowException() final = default;

    const char* what() const noexcept final {
        return "Overflow Condition";
    }
};

#endif