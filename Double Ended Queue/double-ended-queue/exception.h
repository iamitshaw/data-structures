
/* Include Guard */

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <bits/stdc++.h>

class EmptyException final: public std::exception {
public:
    EmptyException() noexcept = default;
    ~EmptyException() final = default;

    const char* what() const noexcept final {
        return "Double-Ended-Queue is empty!";
    }
};

#endif