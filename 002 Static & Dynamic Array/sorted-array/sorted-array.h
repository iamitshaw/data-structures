
/* Include Guard */

#ifndef _SORTED_ARRAY_H_
#define _SORTED_ARRAY_H_

#include <bits/stdc++.h>

template <typename T>
class SortedArray {
private:
    T* array;
    int32_t numberOfElement;
    int32_t capacity;
public:
    explicit SortedArray(int32_t capacity);
    ~SortedArray();
    void insertElement(T data);
    void deleteElement(T keyValue);
    int32_t searchElement(T keyValue);
    int32_t getNumberOfElement() const;
    int32_t getCapacity() const;
    T elementAt(int32_t index);
    void displayElement();
    bool is_empty();
};

/* constructor */
template<typename T>
SortedArray<T>::SortedArray(int32_t capacity)
        :numberOfElement{0}, capacity{capacity} {
    SortedArray<T>::array = new T[SortedArray<T>::capacity];
}

/* destructor */
template<typename T>
SortedArray<T>::~SortedArray() {
    delete [] SortedArray<T>::array;
}

/* insert element */
template<typename T>
void SortedArray<T>::insertElement(T data) {
    if (SortedArray<T>::numberOfElement < SortedArray<T>::capacity) {
        /* if slot is available to insert an element then
         * insertion should be done at end of container */
        int32_t i;
        for (i = {numberOfElement - 1};i >= 0 && array[i] > data;i--) {
            SortedArray<T>::array[i + 1] = SortedArray<T>::array[i];
        }

        SortedArray<T>::array[i + 1] = data;

        /* increase number_of_element */
        SortedArray<T>::numberOfElement += 1;
    }
}

/* search element */
template<typename T>
int32_t SortedArray<T>::searchElement(T keyValue) {
    int32_t left{0};
    int32_t right{SortedArray<T>::numberOfElement - 1};
    while (left <= right) {
        int32_t mid{left + (right - left)/2};
        if (*(array + mid) == keyValue) {

            /* evaluate whether or not key_value
             * to be searched is present at middle */
            return mid;
        } else if (*(array + mid) > keyValue) {

            /* if key_value is less than array[mid] then
             * key_value can be present only in the left
             * of current sub-array before middle element */
            right = mid - 1;
        } else {

            /* if key_value is greater than array[mid] then
             * key_value can be present only in the right
             * of current sub-array after middle element */
            left = mid + 1;
        }
    }

    /* -1 sentinel is used to indicate
     * that key_value is not found */
    return -1;
}

/* delete element */
template<typename T>
void SortedArray<T>::deleteElement(T keyValue) {

    /* get index position of keyValue */
    int32_t index{searchElement(keyValue)};

    if (index != -1) {

        /* deletion should only be performed if
         * element keyValue exist in array */
        for (int32_t i{index};i < SortedArray<T>::numberOfElement - 1;i++) {
            SortedArray<T>::array[i] = SortedArray<T>::array[i+1];
        }

        /* decrease number_of_element */
        SortedArray<T>::numberOfElement -= 1;
    }
}

/* get number_of_element */
template<typename T>
int32_t SortedArray<T>::getNumberOfElement() const {
    return SortedArray<T>::numberOfElement;
}

/* get capacity */
template<typename T>
int32_t SortedArray<T>::getCapacity() const {
    return SortedArray<T>::capacity;
}

/* display sorted-array */
template<typename T>
void SortedArray<T>::displayElement() {
    for (int32_t i{0};i < SortedArray<T>::numberOfElement;i++) {
        std::cout << SortedArray<T>::array[i] << " ";
    }std::cout << std::endl;
}

/* get element at specified index */
template<typename T>
T SortedArray<T>::elementAt(int32_t index) {
    if (index >= 0 && index < SortedArray<T>::numberOfElement) {
        return SortedArray<T>::array[index];
    } else {
        throw std::exception();
    }
}

/* check whether container is empty */
template<typename T>
bool SortedArray<T>::is_empty() {
    return SortedArray<T>::getNumberOfElement() <= 0;
}



#endif