
/* Include Guard */

#ifndef _DYNAMIC_ARRAY_
#define _DYNAMIC_ARRAY_

#include <bits/stdc++.h>

template <class T>
class DynamicArray {
private:
    T* dynamicArray;
    int32_t lastElementIndex=0;
    int32_t capacity=0;
public:
    DynamicArray();
    explicit DynamicArray(int32_t capacity);
    ~DynamicArray();

    bool isFullContainer() const;
    int32_t getCapacity() const;
    int32_t getArraySize() const;
    int searchElement(const T &key_value) const;
    bool isEmpty() const;
    T& getAt(int32_t index);
    void setAt(int32_t index, const T& element);

    virtual void add(const T &data);
    bool contains(const T &data) const;
    virtual void remove(const T &key_value);
    virtual void removeAt(int32_t index);

    T *getData() const;
    void resize(int32_t new_capacity);
    void reduce(int32_t new_capacity);
    void clear();
    void display_array();
};

/* Default Constructor */
template <class T>
DynamicArray<T>::DynamicArray()
: DynamicArray<T>::DynamicArray{16} {

}

/* Overloaded Constructor */
template <class T>
DynamicArray<T>::DynamicArray(int32_t capacity)
: capacity{capacity}, lastElementIndex{0} {
    DynamicArray<T>::dynamicArray = new T[DynamicArray<T>::capacity];
}

/* Destructor */
template <class T>
DynamicArray<T>::~DynamicArray() {
    /* releases dynamically allocated memory */
    delete [] DynamicArray<T>::dynamicArray;
    DynamicArray<T>::dynamicArray = nullptr;
}

/* get lastElementIndex */
template<class T>
int32_t DynamicArray<T>::getArraySize() const {
    return DynamicArray<T>::lastElementIndex;
}

/* get capacity */
template <class T>
bool DynamicArray<T>::isFullContainer() const {
    return getArraySize() == getCapacity();
}

/* get capacity  */
template <class T>
int32_t DynamicArray<T>::getCapacity() const {
    return DynamicArray<T>::capacity;
}

/* search element */
template <class T>
int DynamicArray<T>::searchElement(const T& key_value) const {
    for (int32_t i{0}; i < DynamicArray<T>::lastElementIndex; i++) {

        /* evaluate whether or not the current
         * element is the required element */
        if (*(DynamicArray<T>::dynamicArray + i) == key_value) {
            return i;
        }
    }

    /* -1 sentinel is used to indicate
    that the key_value is not found */
    return -1;
}

/* check whether container is empty */
template <class T>
bool DynamicArray<T>::isEmpty() const {
    return DynamicArray<T>::lastElementIndex <= 0;
}

/* add element */
template <class T>
void DynamicArray<T>::add(const T& data) {
    if (DynamicArray<T>::isFullContainer()) {
        DynamicArray<T>::resize(DynamicArray<T>::capacity * 2);
    }

    /* add element to end_of_container */
    DynamicArray<T>::dynamicArray[lastElementIndex] = data;
    DynamicArray<T>::lastElementIndex += 1;
}

/* remove element */
template <class T>
void DynamicArray<T>::remove(const T &key_value) {
    /* get index position of key_value */
    int32_t index{DynamicArray<T>::searchElement(key_value)};

    if (index != -1) {
        DynamicArray<T>::removeAt(index);
    }
}

/* check whether data is available in container */
template <class T>
bool DynamicArray<T>::contains(const T& data) const {
    return searchElement(data) > -1;
}

/* get data */
template <class T>
T* DynamicArray<T>::getData() const {
    return &DynamicArray<T>::dynamicArray[0];
}

/*  releases dynamically allocated data */
template <class T>
void DynamicArray<T>::clear() {
    delete [] DynamicArray<T>::dynamicArray;
    /* reset container to its default state */
    DynamicArray<T>::resize(16);
    lastElementIndex = {0};
}



/* resize_container */
template <class T>
void DynamicArray<T>::resize(int32_t new_capacity) {
    /* create a temporary dynamicArray to
     * store dynamic-dynamicArray elements */
    T* tempArray = new T[new_capacity];

    /* copy current elements into
     * new dynamic-dynamicArray-stack */
    for (int32_t i{0};i < DynamicArray<T>::lastElementIndex; i++) {
        tempArray[i] = DynamicArray<T>::dynamicArray[i];
    }

    /* de-allocate memory assigned for
     * previous dynamic-dynamicArray-stack */
    delete [] DynamicArray<T>::dynamicArray;

    /* previous stack container should
     * point to new stack container */
    DynamicArray<T>::dynamicArray = tempArray;

    /* delete temporaryArray pointer */
    tempArray = nullptr;
    delete [] tempArray;

    /* update queue new_capacity */
    DynamicArray<T>::capacity = new_capacity;
}

/* reduce dynamic_array */
template<class T>
void DynamicArray<T>::reduce(int32_t new_capacity) {
    DynamicArray<T>::resize(new_capacity);
}

/* print dynamicArray-elements */
template<class T>
void DynamicArray<T>::display_array() {
    for (int32_t i{0};i < DynamicArray<T>::getArraySize();i++) {
        std::cout << DynamicArray<T>::dynamicArray[i] << " ";
    }std::cout << std::endl;
}

template<class T>
void DynamicArray<T>::setAt(int32_t index, const T &element) {
    DynamicArray<T>::dynamicArray[index] = element;
}

template<class T>
T &DynamicArray<T>::getAt(int32_t index) {
    return DynamicArray<T>::dynamicArray[index];
}

template<class T>
void DynamicArray<T>::removeAt(int32_t index) {
    if (index >= 0 && index < DynamicArray<T>::getArraySize()) {
        /* deletion should only be performed
         * if index is valid in dynamicArray */
        for (int32_t i{index};i < DynamicArray<T>::lastElementIndex - 1; i++) {
            DynamicArray<T>::dynamicArray[i] = DynamicArray<T>::dynamicArray[i + 1];
        }

        /* decrease numberOfElement in dynamicArray */
        DynamicArray<T>::lastElementIndex -= 1;

        /* reduce dynamicArray */
        if (DynamicArray<T>::lastElementIndex < DynamicArray<T>::capacity / 4) {
            reduce(DynamicArray<T>::capacity/2);
        }
    }
}

#endif