
/* Include Guard */

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <bits/stdc++.h>

template <typename T>
class Object {
private:
    T data;
public:
    Object();
    explicit Object(T data);
    void setData(T data_value);
    T getData();
};

/* default constructor */
template<typename T>
Object<T>::Object()
:data{}{}

/* overloaded constructor */
template<typename T>
Object<T>::Object(T data)
:data{data}{

}

/* setter */
template<typename T>
void Object<T>::setData(T data_value) {
    Object::data = data_value;
}

/* getter */
template<typename T>
T Object<T>::getData() {
    return Object::data;
}

#endif