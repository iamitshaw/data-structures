
/* Include Guard */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "exception.h"
#include "node.h"

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    size_t queueSize;
public:
    Queue();
    ~Queue();
    T getFrontElement();
    T getRearElement();
    size_t getQueueSize();
    void deleteQueue();
    void displayQueue();
    bool isEmptyQueue();
    void EnQueue(T data);
    void EnQueue(Node<T>* nodePointer);
    T deQueue();
};

/* constructor */
template <typename T>
Queue<T>::Queue()
:front{nullptr}, rear{nullptr}, queueSize{0} {

}

/* destructor */
template <typename T>
Queue<T>::~Queue() {
    deleteQueue();
}

/* delete queue */
template <typename T>
void Queue<T>::deleteQueue() {
    /* set the initial node Pointer */
    Node<T>* initialNodePointer{Queue<T>::front};

    /* navigate through linked-list-queue */
    while (initialNodePointer) {

        /* de-attach the initial-Node */
        Queue<T>::front = Queue<T>::front->getNext();
        initialNodePointer->setNext(nullptr);

        /* de-allocate the heap memory */
        delete initialNodePointer;

        /* re-set the initialNodePointer */
        initialNodePointer = Queue<T>::front;
        Queue<T>::queueSize -= 1;
    }

    /* as the linked-list-queue
     * don't have any element */
    Queue<T>::rear = nullptr;
}

/* get front element of linked-list-queue */
template <typename T>
T Queue<T>::getFrontElement() {
    if (isEmptyQueue()) {
        throw UnderflowException{};
    } else {
        return Queue<T>::front->getData();
    }
}

/* get rear element of linked-list-queue */
template <typename T>
T Queue<T>::getRearElement() {
    if (isEmptyQueue()) {
        throw UnderflowException{};
    } else {
        return Queue<T>::rear->getData();
    }
}

/* get queueSize */
template <typename T>
size_t Queue<T>::getQueueSize() {
    return Queue<T>::queueSize;
}

/* display linked-list-queue content */
template <typename T>
void Queue<T>::displayQueue() {
    Node<T>* tempNodePointer{Queue<T>::front};

    /* navigate through linked-list queue */
    while (tempNodePointer) {
        std::cout << tempNodePointer->getData() << " ";
        tempNodePointer = tempNodePointer->getNext();
    }

    /* move cursor to next line */
    std::cout << std::endl;
}

/* check whether linked-list-queue is empty */
template <typename T>
bool Queue<T>::isEmptyQueue() {
    return !Queue<T>::front && !Queue<T>::rear;
}

/* insert an element */
template <typename T>
void Queue<T>::EnQueue(T data) {
    /* create a node with specified data */
    auto* nodePointer = new Node<T>(data);

    /* */
    EnQueue(nodePointer);
}

template <typename T>
void Queue<T>::EnQueue(Node<T> *nodePointer) {
    if (isEmptyQueue()) {
        Queue<T>::front = Queue<T>::rear = nodePointer;
    } else {
        Queue<T>::rear->setNext(nodePointer);
        Queue<T>::rear = nodePointer;
    }

    /* increase queueSize */
    Queue<T>::queueSize += 1;
}

/* delete an element */
template <typename T>
T Queue<T>::deQueue() {
    if (isEmptyQueue()) {
        throw UnderflowException{};
    } else {
        Node<T>* tempNodePointer{Queue<T>::front};
        T deletedData{tempNodePointer->getData()};

        if (Queue<T>::front == Queue<T>::rear) {
            /* exactly single element is
             * in the linked-list-queue */
            Queue<T>::front = Queue<T>::rear = nullptr;
        } else {
            Queue<T>::front = Queue<T>::front->getNext();
            tempNodePointer->setNext(nullptr);
        }

        /* de-allocate heap memory */
        delete tempNodePointer;

        /* decrease queueSize */
        Queue<T>::queueSize -= 1;

        return deletedData;
    }
}

#endif
