
/* Include Guard */

#ifndef _STACK_H_
#define _STACK_H_

#include "exception.h"

template <typename T>
class Stack {
private:
    T* array;
    ssize_t top;
    size_t capacity;
public:
    explicit Stack(size_t sizeOfStack=16);
    ~Stack();
    size_t getStackSize();
    size_t getCapacity();
    ssize_t getTop();
    T getTopElement();
    bool isEmptyStack();
    bool isFullStack();
    T popElement();
    void pushElement(T data);
    void displayStack();
    void deleteStack();
};

/* constructor */
template<typename T>
Stack<T>::Stack(size_t sizeOfStack)
:top{-1}, capacity{sizeOfStack} {
    Stack<T>::array = new T[Stack<T>::capacity];
}

/* destructor */
template<typename T>
Stack<T>::~Stack() {
    /* de-allocate heap memory */
    delete [] Stack<T>::array;
}

/* get stackSize */
template<typename T>
size_t Stack<T>::getStackSize() {
    return Stack<T>::top + 1;
}

/* get stack capacity */
template<typename T>
size_t Stack<T>::getCapacity() {
    return Stack<T>::capacity;
}

/* get top index */
template<typename T>
ssize_t Stack<T>::getTop() {
    return Stack<T>::top;
}

/* get top element */
template<typename T>
T Stack<T>::getTopElement() {
    if (isEmptyStack()) {
        throw UnderflowException{};
    } else {
        return Stack<T>::array[Stack<T>::top];
    }
}

/* check whether stack is completely empty */
template<typename T>
bool Stack<T>::isEmptyStack() {
    return Stack<T>::top == -1;
}

/* check whether stack is completely full */
template<typename T>
bool Stack<T>::isFullStack() {
    return Stack<T>::top == Stack<T>::capacity-1;
}

/* display stack content */
template<typename T>
void Stack<T>::displayStack() {
    for (ssize_t i{Stack<T>::top};i >= 0;i--) {
        std::cout << Stack<T>::array[i] << std::endl;
    }
}

/* delete stack */
template<typename T>
void Stack<T>::deleteStack() {
    /* reset stack attributes */
    Stack<T>::top = -1;
}

/* push operation */
template<typename T>
void Stack<T>::pushElement(T data) {
    if (isFullStack()) {
        throw OverflowException{};
    } else {
        Stack<T>::top += 1;
        Stack<T>::array[Stack<T>::top] = data;
    }
}

/* pop operation */
template<typename T>
T Stack<T>::popElement() {
    if (isEmptyStack()) {
        throw UnderflowException{};
    } else {
        T deletedData{Stack<T>::array[Stack<T>::top]};
        Stack<T>::top -= 1;
        return deletedData;
    }
}

#endif