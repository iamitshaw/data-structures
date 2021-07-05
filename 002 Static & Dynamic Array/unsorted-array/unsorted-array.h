
/* Include Guard */

#ifndef _UNSORTED_ARRAY_H_
#define _UNSORTED_ARRAY_H_

#include <bits/stdc++.h>

template <typename T>
class UnsortedArray {
private:
    T* array;
    int32_t numberOfElement;
    int32_t capacity;
public:
    explicit UnsortedArray(int32_t capacity);
    ~UnsortedArray();
    void insertElement(T data);
    void deleteElement(T keyValue);
    int32_t searchElement(T keyValue);
    int32_t getNumberOfElement() const;
    int32_t getCapacity() const;
    T elementAt(int32_t i);
    void displayElement();
    bool is_empty();
};

/* constructor */
template<typename T>
UnsortedArray<T>::UnsortedArray(int32_t capacity)
        :numberOfElement{0}, capacity{capacity} {
    UnsortedArray<T>::array = new T[UnsortedArray<T>::capacity];
}

/* destructor */
template<typename T>
UnsortedArray<T>::~UnsortedArray() {
    delete [] UnsortedArray<T>::array;
}

/* insert element */
template<typename T>
void UnsortedArray<T>::insertElement(T data) {
    if (UnsortedArray<T>::numberOfElement < UnsortedArray<T>::capacity) {
        /* if slot is available to insert an element then
         * insertion should be done at end of container */
        UnsortedArray<T>::array[UnsortedArray<T>::numberOfElement] = data;
        UnsortedArray<T>::numberOfElement += 1;
    }
}

/* search element */
template<typename T>
int32_t UnsortedArray<T>::searchElement(T keyValue) {
    for (int32_t i{0}; i < UnsortedArray<T>::numberOfElement; i++) {

        /* evaluate whether or not the current
         * element is the required element */
        if (*(UnsortedArray<T>::array + i) == keyValue) {
            return i;
        }
    }

    /* -1 sentinel is used to indicate
    that the key_value is not found */
    return -1;
}

/* delete element */
template<typename T>
void UnsortedArray<T>::deleteElement(T keyValue) {

    /* get index position of keyValue */
    int32_t index{searchElement(keyValue)};

    if (index != -1) {

        /* deletion should only be performed if
         * element keyValue exist in array */
        for (int32_t i{index};i < UnsortedArray<T>::numberOfElement - 1;i++) {
            UnsortedArray<T>::array[i] = UnsortedArray<T>::array[i+1];
        }

        /* decrease numberOfElement in array */
        UnsortedArray<T>::numberOfElement -= 1;
    }
}

/* get number_of_element */
template<typename T>
int32_t UnsortedArray<T>::getNumberOfElement() const {
    return UnsortedArray<T>::numberOfElement;
}

/* get capacity */
template<typename T>
int32_t UnsortedArray<T>::getCapacity() const {
    return UnsortedArray<T>::capacity;
}

/* display unsorted-array */
template<typename T>
void UnsortedArray<T>::displayElement() {
    for (int32_t i{0};i < UnsortedArray<T>::numberOfElement;i++) {
        std::cout << UnsortedArray<T>::array[i] << " ";
    }

    /* move cursor to next line */
    std::cout << std::endl;
}

/* get element at index i */
template<typename T>
T UnsortedArray<T>::elementAt(int32_t i) {
    if (i >= 0 && i < UnsortedArray<T>::numberOfElement) {
        return UnsortedArray<T>::array[i];
    } else {
        throw std::exception();
    }
}

/* check whether container is empty */
template<typename T>
bool UnsortedArray<T>::is_empty() {
    return UnsortedArray<T>::getNumberOfElement() <= 0;
}

#endif