
/* Include Guard */

#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "node.h"
#include "exception.h"

template <typename T>
class DoubleEndedQueue {
private:
    Node<T>* front;
    Node<T>* back;
    size_t sizeOfDeQue;
public:
    DoubleEndedQueue();
    void insertFront(T data);
    void insertFront(Node<T>* newNode);
    void insertBack(T data);
    void insertBack(Node<T>* newNode);
    T removeFront();
    T removeBack();
    bool isEmpty();
    size_t getSizeOfDeQue();
    T getFront();
    T getBack();
    void displayDeQue();
    void deleteDeQue();
    void reverseDisplay();
    ~DoubleEndedQueue();
};

/* default constructor */
template<typename T>
DoubleEndedQueue<T>::DoubleEndedQueue()
:front{nullptr}, back{nullptr}, sizeOfDeQue{0} {}

/* insert at front */
template<typename T>
void DoubleEndedQueue<T>::insertFront(T data) {
    /* create node */
    auto* newNode = new Node<T>(data);

    /* insert provided node */
    insertFront(newNode);
}

template<typename T>
void DoubleEndedQueue<T>::insertFront(Node<T> *newNode) {
    if (DoubleEndedQueue<T>::isEmpty()) {
        /* if double-ended-queue is empty */
        DoubleEndedQueue<T>::front = DoubleEndedQueue<T>::back = newNode;
    } else {
        newNode->setNext(DoubleEndedQueue<T>::front);
        DoubleEndedQueue<T>::front->setPrev(newNode);
        DoubleEndedQueue<T>::front = newNode;
    }

    /* increase double-ended-queue size */
    DoubleEndedQueue<T>::sizeOfDeQue += 1;
}

/* insert at back */
template<typename T>
void DoubleEndedQueue<T>::insertBack(T data) {
    /* create node */
    auto* newNode = new Node<T>(data);

    /* insert provided node */
    insertBack(newNode);
}

template<typename T>
void DoubleEndedQueue<T>::insertBack(Node<T> *newNode) {
    if (DoubleEndedQueue<T>::isEmpty()) {
        /* if double-ended-queue is empty */
        DoubleEndedQueue<T>::front = DoubleEndedQueue<T>::back = newNode;
    } else {
        DoubleEndedQueue<T>::back->setNext(newNode);
        newNode->setPrev(DoubleEndedQueue<T>::back);
        DoubleEndedQueue<T>::back = newNode;
    }

    /* increase double-ended-queue size */
    DoubleEndedQueue<T>::sizeOfDeQue += 1;
}

/* remove front node */
template<typename T>
T DoubleEndedQueue<T>::removeFront() {
    if (DoubleEndedQueue<T>::isEmpty()) {
        throw EmptyException();
    } else {
        Node<T>* tempNodePointer{DoubleEndedQueue<T>::front};
        if (DoubleEndedQueue<T>::front == DoubleEndedQueue<T>::back) {
            DoubleEndedQueue<T>::front = {nullptr};
            DoubleEndedQueue<T>::back = {nullptr};;
        } else {
            DoubleEndedQueue<T>::front = DoubleEndedQueue<T>::front->getNext();
            tempNodePointer->setNext(nullptr);
            DoubleEndedQueue<T>::front->setPrev(nullptr);
        }

        /* get data at specified node */
        T data {tempNodePointer->getData()};

        /* de-allocate heap-memory */
        delete tempNodePointer;

        /* decrease double-ended-queue size */
        DoubleEndedQueue<T>::sizeOfDeQue -= 1;

        return data;
    }
}

/* remove rear node */
template<typename T>
T DoubleEndedQueue<T>::removeBack() {
    if (DoubleEndedQueue<T>::isEmpty()) {
        throw EmptyException();
    } else {
        Node<T>* tempNodePointer {DoubleEndedQueue<T>::back};
        if (DoubleEndedQueue<T>::front == DoubleEndedQueue<T>::back) {
            DoubleEndedQueue<T>::front = {nullptr};
            DoubleEndedQueue<T>::back = {nullptr};
        } else {
            DoubleEndedQueue<T>::back = DoubleEndedQueue<T>::back->getPrev();
            tempNodePointer->setPrev(nullptr);
            DoubleEndedQueue<T>::back->setNext(nullptr);
        }

        /* get data at specified node */
        T data {tempNodePointer->getData()};

        /* de-allocate heap-memory */
        delete tempNodePointer;

        /* decrease double-ended-queue size */
        DoubleEndedQueue<T>::sizeOfDeQue -= 1;

        return data;
    }
}

/* double-ended-queue is empty or not? */
template<typename T>
bool DoubleEndedQueue<T>::isEmpty() {
    return !DoubleEndedQueue<T>::front && !DoubleEndedQueue<T>::back;
}

/* get size of double-ended-queue */
template<typename T>
size_t DoubleEndedQueue<T>::getSizeOfDeQue() {
    return DoubleEndedQueue<T>::sizeOfDeQue;
}

/* get front element */
template<typename T>
T DoubleEndedQueue<T>::getFront() {
    if (DoubleEndedQueue<T>::isEmpty()) {
        throw EmptyException();
    } else {
        return DoubleEndedQueue<T>::front->getData();
    }
}

/* get rear element */
template<typename T>
T DoubleEndedQueue<T>::getBack() {
    if (DoubleEndedQueue<T>::isEmpty()) {
        throw EmptyException();
    } else {
        return DoubleEndedQueue<T>::back->getData();
    }
}

/* delete double-ended-queue */
template<typename T>
void DoubleEndedQueue<T>::deleteDeQue() {
    Node<T>* nodeToBeDeleted {DoubleEndedQueue<T>::front};

    /* navigate through each double-ended-queue node */
    while (DoubleEndedQueue<T>::front) {
        DoubleEndedQueue<T>::front = DoubleEndedQueue<T>::front->getNext();

        /* de-attach nodeToBeDeleted */
        nodeToBeDeleted->setNext(nullptr);
        DoubleEndedQueue<T>::front->setPrev(nullptr);

        /* de-allocate heap-memory */
        delete nodeToBeDeleted;

        nodeToBeDeleted = DoubleEndedQueue<T>::front;

        /* decrease double-ended-queue size */
        DoubleEndedQueue<T>::sizeOfDeQue -= 1;
    }

    /* update back-pointer */
    DoubleEndedQueue<T>::back = {nullptr};
}

/* destructor */
template<typename T>
DoubleEndedQueue<T>::~DoubleEndedQueue() {
    DoubleEndedQueue<T>::deleteDeQue();
}

/* display double-ended-queue */
template<typename T>
void DoubleEndedQueue<T>::displayDeQue() {
    Node<T>* tempNodePointer {DoubleEndedQueue<T>::front};

    while (tempNodePointer) {
        std::cout << tempNodePointer->getData() << " ";
        tempNodePointer = tempNodePointer->getNext();
    }

    /* advance cursor to next line */
    std::cout << std::endl;
}

/* display reverse of double-ended-queue */
template<typename T>
void DoubleEndedQueue<T>::reverseDisplay() {
    Node<T>* tempNodePointer {DoubleEndedQueue<T>::back};

    while (tempNodePointer) {
        std::cout << tempNodePointer->getData() << " ";
        tempNodePointer = tempNodePointer->getPrev();
    }

    /* advance cursor to next line */
    std::cout << std::endl;
}

#endif