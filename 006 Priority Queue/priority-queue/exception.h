
/* Include Guard */

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <bits/stdc++.h>

class Exception final: public std::exception {
private:
    char* message;
public:

    /* constructor */
    explicit Exception(char* error_message) noexcept {
        Exception::message = error_message;
    }

    /* destructor */
    ~Exception() final = default;

    const char* what() const noexcept final  {
        /* return error message */
        return message;
    }
};
#endif