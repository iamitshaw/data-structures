
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
    void resizeStack(size_t sizeOfStack);
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

    /* de-allocate heap memory */
    delete [] Stack<T>::array;

    /* default stack capacity */
    Stack<T>::capacity = 16;

    /* create space for stack elements */
    Stack<T>::array = new T[Stack<T>::capacity];
}

/* push operation */
template<typename T>
void Stack<T>::pushElement(T data) {
    if (isFullStack()) {
        /* if space isn't available */
        resizeStack(2 * Stack<T>::capacity);
    }

    /* if space is available */
    Stack<T>::top += 1;
    Stack<T>::array[Stack<T>::top] = data;
}

/* pop operation */
template<typename T>
T Stack<T>::popElement() {
    if (isEmptyStack()) {
        throw UnderflowException{};
    } else {
        T deletedData{Stack<T>::array[Stack<T>::top]};
        Stack<T>::top -= 1;

        /* reduce stack size */
        if (getStackSize() < Stack<T>::capacity/4) {
            resizeStack(Stack<T>::capacity/2);
        }

        return deletedData;
    }
}

template<typename T>
void Stack<T>::resizeStack(size_t sizeOfStack) {
    /* create a temporary array to store
     * dynamic-array-stack elements */
    T* tempArray = new T[sizeOfStack];

    /* copy current elements into
     * new dynamic-array-stack */
    for (size_t i{0};i < Stack<T>::capacity;i++) {
        tempArray[i] = Stack<T>::array[i];
    }

    /* de-allocate memory assigned for
     * previous dynamic-array-stack */
    delete [] Stack<T>::array;

    /* previous stack container should
     * point to new stack container */
    Stack<T>::array = tempArray;

    /* delete temporaryArray pointer */
    tempArray = nullptr;
    delete [] tempArray;

    /* update queue capacity */
    Stack<T>::capacity = sizeOfStack;
}

#endif