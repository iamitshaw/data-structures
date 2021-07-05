
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
    void resizeQueue(size_t sizeOfQueue);
    void reduceQueue(size_t sizeOfQueue);
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
    Queue<T>::array = new T[Queue<T>::capacity];
}

/* destructor */
template <typename T>
Queue<T>::~Queue() {
    delete [] Queue<T>::array;
}

/* check whether dynamic-circular-queue is empty */
template <typename T>
bool Queue<T>::isEmptyQueue() {
    return Queue<T>::front == -1 && Queue<T>::rear == -1;
}

/* check whether dynamic-circular-queue is full */
template <typename T>
bool Queue<T>::isFullQueue() {
    return (Queue<T>::rear+1) % Queue<T>::capacity == Queue<T>::front;
}

/* get count of total elements
 * in dynamic-circular-queue */
template <typename T>
size_t Queue<T>::getQueueSize() {
    return Queue<T>::queueSize;
}

/* get dynamic-circular-queue capacity */
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

/* delete dynamic-circular-queue */
template <typename T>
void Queue<T>::deleteQueue() {
    /* reset queue attributes
     * to its initial state */
    Queue<T>::front = -1;
    Queue<T>::rear = -1;
    Queue<T>::queueSize = 0;

    /* de-allocate heap memory */
    delete [] Queue<T>::array;

    /* default capacity */
    Queue<T>::capacity = 16;

    /* create a queue of default size */
    Queue<T>::array = new T[capacity];
}

/* display dynamic-circular-queue */
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

/* get front element of dynamic-circular-queue */
template <typename T>
T Queue<T>::getFrontElement() {
    if (isEmptyQueue()) {
        throw UnderflowException{};
    } else {
        return Queue<T>::array[front];
    }
}

/* get rear element of dynamic-circular-queue */
template <typename T>
T Queue<T>::getRearElement() {
    if (isEmptyQueue()) {
        throw UnderflowException{};
    } else {
        return Queue<T>::array[rear];
    }
}

/* insert an element to dynamic-circular-queue */
template <typename T>
void Queue<T>::enQueue(T data) {
    if (isFullQueue()) {
        /* if dynamic-circular-queue is full */
        resizeQueue(Queue<T>::capacity * 2);
        Queue<T>::rear = (Queue<T>::rear + 1) % Queue<T>::capacity;
    } else {
        if (isEmptyQueue()) {
            /* if dynamic-circular-queue is empty */
            Queue<T>::front = Queue<T>::rear = 0;
        } else {
            Queue<T>::rear = (Queue<T>::rear + 1) % Queue<T>::capacity;
        }
    }
    /* insert data into dynamic-circular
     * -queue and increase queueSize */
    Queue<T>::array[rear] = data;
    Queue<T>::queueSize += 1;
}

/* delete an element from dynamic-circular-queue */
template <typename T>
T Queue<T>::deQueue() {
    if (isEmptyQueue()) {
        /* if dynamic-circular-queue is empty */
        throw UnderflowException{};
    } else {
        /* store the data to be deleted
         * from dynamic-circular-queue */
        T deletedData{Queue<T>::array[front]};

        if (Queue<T>::front == Queue<T>::rear) {
            /* dynamic-circular-queue has
             * exactly single element */
            Queue<T>::front = Queue<T>::rear = -1;
        } else {
            Queue<T>::front = (Queue<T>::front+1) % Queue<T>::capacity;
        }

        /* decrease dynamic-circular-queue size */
        Queue<T>::queueSize -= 1;

        /* reduce queueSize*/
        if (Queue<T>::queueSize < Queue<T>::capacity/4) {
            reduceQueue(Queue<T>::capacity/2);
        }

        return deletedData;
    }
}

template<typename T>
void Queue<T>::resizeQueue(size_t sizeOfQueue) {
    /* create a temporary array to store
     * dynamic-circular-queue elements */
    T* tempArray = new T[sizeOfQueue];

    /* copy current elements into
     * new dynamic-circular-queue */
    for (size_t i{0};i < Queue<T>::capacity;i++) {
        tempArray[i] = Queue<T>::array[i];
    }

    /* de-allocate memory assigned for
     * previous dynamic-circular-queue */
    delete [] Queue<T>::array;

    /* previous queue container should
     * point to new queue container */
    Queue<T>::array = tempArray;

    /* delete temporaryArray pointer */
    tempArray = nullptr;
    delete [] tempArray;

    if (Queue<T>::front > Queue<T>::rear) {
        /* relocate the dynamic-circular-queue elements
         * which are below the Queue<T>::front pointer */
        for (size_t i{0};i < Queue<T>::front;i++) {
            Queue<T>::array[i + Queue<T>::capacity] = Queue<T>::array[i];
        }
        /* update value of Queue<T>::rear pointer */
        Queue<T>::rear += Queue<T>::capacity;
    }

    /* update queue capacity */
    Queue<T>::capacity = sizeOfQueue;
}

template<typename T>
void Queue<T>::reduceQueue(size_t sizeOfQueue) {
    /* create a temporary array to store
     * dynamic-circular-queue elements */
    T* tempArray = new T[sizeOfQueue];

    ssize_t i{Queue<T>::front}, j{0};

    /* copy current elements into
     * new dynamic-circular-queue */
    while (j < Queue<T>::queueSize) {
        tempArray[j] = Queue<T>::array[i];
        i = (i + 1) % Queue<T>::capacity;
        j += 1;
    }

    /* de-allocate memory assigned for
     * previous dynamic-circular-queue */
    delete [] Queue<T>::array;

    /* previous queue container should
     * point to new queue container */
    Queue<T>::array = tempArray;

    /* delete temporaryArray pointer */
    tempArray = nullptr;
    delete [] tempArray;

    /* update dynamic-circular-queue
     * member fields accordingly */

    /* update Queue<T>::front */
    isEmptyQueue()? Queue<T>::front = -1:Queue<T>::front = 0;

    /* update value of Queue<T>::rear pointer */
    Queue<T>::rear = Queue<T>::queueSize - 1;

    /* update queue capacity */
    Queue<T>::capacity = sizeOfQueue;
}

#endif