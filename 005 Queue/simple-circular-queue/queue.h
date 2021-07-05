
/* Include Guard */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "exception.h"

template <typename T>
class Queue {
private:
    T* array;
    ssize_t front;
    ssize_t rear;
    size_t queueSize;
    size_t capacity;
public:
    explicit Queue(size_t maxSize=16);
    ~Queue();
    void enQueue(T data);
    T deQueue();
    bool isEmptyQueue();
    bool isFullQueue();
    size_t getQueueSize();
    size_t getCapacity();
    T getFrontElement();
    T getRearElement();
    ssize_t getFront();
    ssize_t getRear();
    void displayQueue();
    void deleteQueue();
};

/* constructor */
template <typename T>
Queue<T>::Queue(size_t maxSize)
:rear{-1}, front{-1}, queueSize{0}, capacity{maxSize}{
    Queue<T>::array = new T[this->capacity];
}

/* destructor */
template <typename T>
Queue<T>::~Queue() {
    delete [] Queue<T>::array;
}

/* check whether simple-circular-queue is empty */
template <typename T>
bool Queue<T>::isEmptyQueue() {
    return Queue<T>::front == -1 && Queue<T>::rear == -1;
}

/* check whether simple-circular-queue is full */
template <typename T>
bool Queue<T>::isFullQueue() {
    return (Queue<T>::rear+1) % Queue<T>::capacity == Queue<T>::front;
}

/* get count of total elements in queue */
template <typename T>
size_t Queue<T>::getQueueSize() {
    return Queue<T>::queueSize;
}

/* get queue capacity */
template <typename T>
size_t Queue<T>::getCapacity() {
    return Queue<T>::capacity;
}

/* get front index pointer */
template <typename T>
ssize_t Queue<T>::getFront() {
    return Queue<T>::front;
}

/* get rear index pointer */
template <typename T>
ssize_t Queue<T>::getRear() {
    return Queue<T>::rear;
}

/* delete simple-circular-queue */
template <typename T>
void Queue<T>::deleteQueue() {
    /* reset queue attributes
     * to its initial state */
    Queue<T>::front = -1;
    Queue<T>::rear = -1;
    Queue<T>::queueSize = 0;
}

/* display simple-circular-queue */
template <typename T>
void Queue<T>::displayQueue() {
    ssize_t index{Queue<T>::front},j{1};
    while (j <= Queue<T>::queueSize) {
        std::cout << Queue<T>::array[index] << " ";
        index = (index + 1) % Queue<T>::capacity;
        j = j + 1;
    }
    /* move cursor to next line */
    std::cout << std::endl;
}

/* get front element of simple-circular-queue */
template <typename T>
T Queue<T>::getFrontElement() {
    if (isEmptyQueue()) {
        throw UnderflowException{};
    } else {
        return Queue<T>::array[front];
    }
}

/* get rear element of simple-circular-queue */
template <typename T>
T Queue<T>::getRearElement() {
    if (isEmptyQueue()) {
        throw UnderflowException{};
    } else {
        return Queue<T>::array[rear];
    }
}

/* insert an element to simple-circular-queue */
template <typename T>
void Queue<T>::enQueue(T data) {
    if (isFullQueue()) {
        /* if simple-circular-queue is full */
        throw OverflowException{};
    } else {
        if (isEmptyQueue()) {
            /* if simple-circular-queue is empty */
            Queue<T>::front = Queue<T>::rear = 0;
        } else {
            Queue<T>::rear = (Queue<T>::rear + 1) % Queue<T>::capacity;
        }

        /* insert data into simple-circular
         * -queue and increase queueSize */
        Queue<T>::array[rear] = data;
        Queue<T>::queueSize += 1;
    }
}

/* delete an element from simple-circular-queue */
template <typename T>
T Queue<T>::deQueue() {
    if (isEmptyQueue()) {
        /* if single-circular-queue is empty */
        throw UnderflowException{};
    } else {
        /* store the data to be deleted
         * from simple-circular-queue */
        T deletedData{Queue<T>::array[front]};

        if (Queue<T>::front == Queue<T>::rear) {
            /* simple-circular-queue has
             * exactly single element */
            Queue<T>::front = Queue<T>::rear = -1;
        } else {
            Queue<T>::front = (Queue<T>::front+1) % Queue<T>::capacity;
        }

        /* decrease simple-circular-queue size */
        Queue<T>::queueSize -= 1;
        return deletedData;
    }
}

#endif