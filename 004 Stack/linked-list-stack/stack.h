
/* Include Guard */

#ifndef _STACK_H_
#define _STACK_H_

#include "exception.h"
#include "node.h"

template <typename T>
class Stack {
private:
    Node<T>* top;
    size_t stackSize;
public:
    Stack();
    ~Stack();
    bool isEmptyStack();
    size_t getStackSize();
    T getTopElement();
    void deleteStack();
    void displayStack();
    void pushElement(T data);
    void pushElement(Node<T>* newNode);
    T popElement();
};

/* constructor */
template<typename T>
Stack<T>::Stack()
 :top{nullptr}, stackSize{0} {

}

/* destructor */
template<typename T>
Stack<T>::~Stack() {
    deleteStack();
}

/* check whether stack is empty */
template<typename T>
bool Stack<T>::isEmptyStack() {
    return Stack<T>::top == nullptr;
}

/* get stack size */
template<typename T>
size_t Stack<T>::getStackSize() {
    return Stack<T>::stackSize;
}

/* get top element */
template<typename T>
T Stack<T>::getTopElement() {
    if (isEmptyStack()) {
        throw UnderflowException{};
    } else {
        return Stack<T>::top->getData();
    }
}

/* delete stack */
template<typename T>
void Stack<T>::deleteStack() {
    Node<T>* tempNodePointer{Stack<T>::top};
    while (tempNodePointer) {
        Stack<T>::top = tempNodePointer->getNext();
        tempNodePointer->setNext(nullptr);
        delete tempNodePointer;
        tempNodePointer = Stack<T>::top;
        Stack<T>::stackSize -= 1;
    }
}

/* display stack content */
template<typename T>
void Stack<T>::displayStack() {
    Node<T>* tempNodePointer{Stack<T>::top};
    while (tempNodePointer) {
        std::cout << tempNodePointer->getData() << std::endl;
        tempNodePointer = tempNodePointer->getNext();
    }
}

/* push operation */
template<typename T>
void Stack<T>::pushElement(T data) {
    /* create node from provided data */
    auto* newNode = new Node<T>(data);

    pushElement(newNode);
}

template<typename T>
void Stack<T>::pushElement(Node<T> *newNode) {
    newNode->setNext(Stack<T>::top);
    Stack<T>::top = newNode;
    Stack<T>::stackSize += 1;
}

/* pop operation */
template<typename T>
T Stack<T>::popElement() {
    if (isEmptyStack()) {
        throw UnderflowException{};
    } else {
        Node<T>* nodeToBeDeleted{Stack<T>::top};
        T deletedData{nodeToBeDeleted->getData()};
        Stack<T>::top = nodeToBeDeleted->getNext();
        nodeToBeDeleted->setNext(nullptr);
        delete nodeToBeDeleted;
        Stack<T>::stackSize -= 1;
        return deletedData;
    }
}

#endif