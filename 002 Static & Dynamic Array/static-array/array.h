
/* Include Guard */

#ifndef _STATIC_ARRAY_H_
#define _STATIC_ARRAY_H_

#include <bits/stdc++.h>

template <typename T, int32_t ArraySize>
class Array {
private:
    int32_t sizeOfArray {ArraySize};
    T values[ArraySize];
public:
    /* overloaded constructor */
    explicit Array(T init_val={}) {
        for (auto &item: Array<T, ArraySize>::values)
            item = init_val;
    }

    /* fill array container */
    void fill(T array_value) {
        for (auto &item: Array<T, ArraySize>::values )
            item = array_value;
    }

    /* get array size */
    int32_t get_size() const {
        return Array<T, ArraySize>::sizeOfArray;
    }

    /* overloaded subscript operator */
    T &operator[](int32_t index) {
        return Array<T, ArraySize>::values[index];
    }

    /* get value at particular index */
    T& at(int32_t index) {
        if (index >= 0 && index < sizeOfArray) {
            return Array<T, ArraySize>::values[index];
        } else {
            throw std::exception{};
        }
    }

    /* display array_elements */
    void display_element() {
        for (const auto& item: Array<T, ArraySize>::values) {
            std::cout << item << std::endl;
        }
    }

    /* get front_element of array */
    T& front_element() {
        return Array<T, ArraySize>::values[0];
    }

    /* get rear_element of array */
    T& rear_element() {
        return Array<T, ArraySize>::values[get_size() - 1];
    }

    /* check whether container is empty */
    bool is_empty() {
        return Array<T, ArraySize>::get_size() <= 0;
    }

    /* get data */
    const T* get_data() {
        if (!Array<T, ArraySize>::is_empty()) {
            return &Array<T, ArraySize>::values[0];
        } else {
            return nullptr;
        }
    }
};

#endif