
/* Include Guard */
#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include "exception.h"

template<typename T>
class BinaryHeap {
private:
    T* heapArray;
    ssize_t countOfElement;
    ssize_t capacity;
public:
    BinaryHeap();
    explicit BinaryHeap(ssize_t capacity);
    ssize_t left_child(ssize_t index) const ;
    ssize_t right_child(ssize_t index) const ;
    ssize_t parent_node(ssize_t index) const ;
    bool is_empty() const ;
    ssize_t heap_size() const ;
    void clear_heap();
    T get_item(ssize_t index) const;
    ssize_t heap_capacity() const ;
    T get_maximum() const;
    void percolate_down(ssize_t index);
    void percolate_up(ssize_t index);
    T extract_max();
    void insert(T data);
    void resize(ssize_t newSize);
    void build_heap(T array[], ssize_t array_size);
    ~BinaryHeap();


};

/* default constructor */
template<typename T>
BinaryHeap<T>::BinaryHeap()
 :capacity{16}, countOfElement{0} {
    BinaryHeap<T>(this->capacity);
}

/* overloaded constructor */
template<typename T>
BinaryHeap<T>::BinaryHeap(ssize_t capacity)
 :capacity{capacity}, countOfElement{0} {
    BinaryHeap<T>::heapArray = new T[BinaryHeap<T>::capacity];
}

/* get left child */
template<typename T>
ssize_t BinaryHeap<T>::left_child(ssize_t index) const{
    ssize_t left_child_index {2 * index + 1};
    if (left_child_index <= 0 or left_child_index >= BinaryHeap<T>::countOfElement) {
        /* -1 sentinel is used to indicate that their
         * is no left child of the provided node */
        return -1;
    } else {
        /* if left child exist for provided node */
        return left_child_index;
    }
}

/* get right child */
template<typename T>
ssize_t BinaryHeap<T>::right_child(ssize_t index) const{
    ssize_t right_child_index {2*(index + 1)};
    if (right_child_index <= 0 or right_child_index >= BinaryHeap<T>::countOfElement) {
        /* -1 sentinel is used to indicate that their
         * is no right child of the provided node */
        return -1;
    } else {
        /* if right child exist for provided node */
        return right_child_index;
    }
}

/* get parent */
template<typename T>
ssize_t BinaryHeap<T>::parent_node(ssize_t index) const{
    if (!(index > 0 && index < BinaryHeap<T>::countOfElement)) {
        /* -1 sentinel is used to indicate that their
         * exist no parent of the provided node */
        return -1;
    } else {
        ssize_t parent_index{(index - 1)/2};
        /* if parent exist for provided node */
        return parent_index;
    }
}

/* whether or not heap container is empty */
template<typename T>
bool BinaryHeap<T>::is_empty() const{
    return BinaryHeap<T>::countOfElement == 0;
}

/* compute the size of the heap container */
template<typename T>
ssize_t BinaryHeap<T>::heap_size() const {
    return BinaryHeap<T>::countOfElement;
}

/* empty the heap container */
template<typename T>
void BinaryHeap<T>::clear_heap() {

    /* de-allocate heap memory */
    delete [] BinaryHeap<T>::heapArray;

    BinaryHeap<T>::countOfElement = 0;
    BinaryHeap<T>::capacity = 16;

    /* create heap container */
    BinaryHeap<T>::heapArray = new T[capacity];
}

/* get item at specified index */
template<typename T>
T BinaryHeap<T>::get_item(ssize_t index) const {
    if (index >= 0 && index < BinaryHeap<T>::countOfElement) {
        return BinaryHeap<T>::heapArray[index];
    } else {
        char error_message[] {"index out_of_range exception!"};
        throw Exception{error_message};
    }
}

/* get heap capacity */
template<typename T>
ssize_t BinaryHeap<T>::heap_capacity() const {
    /* compute the capacity of the heap container */
    return BinaryHeap<T>::capacity;
}

/* get maximum element */
template<typename T>
T BinaryHeap<T>::get_maximum() const {
    if (is_empty()) {
        char error_message[] {"index out_of_range exception!"};
        throw Exception{error_message};
    } else {
        return BinaryHeap<T>::heapArray[0];
    }
}


template <typename T>
void BinaryHeap<T>::percolate_down(ssize_t index) {
    do {
        /* get the left_child and right_child index
     * of the node present at location index */
        ssize_t left_index{left_child(index)};
        ssize_t right_index{right_child(index)};

        /* declare a pointer to indicate maximum index
         * among node, left child and right child */
        ssize_t max_index{index};

        /* compute the max element among node, left child and right child */
        if (left_index != -1 && this->heapArray[left_index] > this->heapArray[max_index]) {
            /* if left child exist and it's value
             * is greater than its parent node */
            max_index = left_index;
        }
        if (right_index != -1 && this->heapArray[right_index] > this->heapArray[max_index]) {
            /* if right child exist and it's value is
             * greater than max(left_child, parent_node) */
            max_index = right_index;
        }

        /* establish the heap property at current node if max_index
         * and index are pointing to two different node elements */
        if (max_index != index) {
            std::swap(BinaryHeap<T>::heapArray[max_index], BinaryHeap<T>::heapArray[index]);

            /* update index_value */
            index = max_index;
        } else {
            /* no further processing is required as left & right
             * child are smaller than or equal to parent element */
            break;
        }
    } while (true);
}

template <typename T>
T BinaryHeap<T>::extract_max() {
    if (this->is_empty()) {
        char error_message[] {"index out_of_range exception!"};
        throw Exception{error_message};
    } else {
        /* store the data that is about to be deleted */
        T deleted_data{BinaryHeap<T>::heapArray[0]};
        std::swap(this->heapArray[0], this->heapArray[this->countOfElement - 1]);

        /* decrease the size of the heap */
        BinaryHeap<T>::countOfElement--;

        /* percolate_down the element at location 0 */
        percolate_down(0);
        return deleted_data;
    }
}

template <typename T>
void BinaryHeap<T>::insert(T data) {

    /* increase the heap size to store the data item */
    BinaryHeap<T>::countOfElement += 1;

    if (BinaryHeap<T>::capacity < BinaryHeap<T>::countOfElement) {
        resize(BinaryHeap<T>::capacity * 2);
    }

    /* index is pointing to location in heap
     * where new element will get inserted */
    ssize_t index{BinaryHeap<T>::countOfElement - 1};

    /* insert the data into the heap */
    BinaryHeap<T>::heapArray[index] = data;

    percolate_up(index);
}

template <typename T>
void BinaryHeap<T>::percolate_up(ssize_t index) {
    ssize_t parent_index {parent_node(index)};

    /* percolate up until either parent node exist or data to
     * be inserted is greater than it's parent node value */
    while (parent_index != -1 && this->heapArray[index] > this->heapArray[parent_index]) {
        std::swap(BinaryHeap<T>::heapArray[index], BinaryHeap<T>::heapArray[parent_index]);

        /* update value of index and parent_index */
        index = {parent_index};
        parent_index = {parent_node(index)};
    }
}

/* resize array */
template <typename T>
void BinaryHeap<T>::resize(ssize_t newSize) {
    T* temp_array{this->heapArray};
    BinaryHeap<T>::heapArray = new T[newSize];

    /* copy the content of the array */
    for (size_t i{0};i < this->capacity;i++) {
        BinaryHeap<T>::heapArray[i] = temp_array[i];
    }

    /* update the heap capacity */
    BinaryHeap<T>::capacity = newSize;

    /* delete the temp_array */
    delete [] temp_array;
}

/* build heap */
template <typename T>
void BinaryHeap<T>::build_heap(T* array, ssize_t array_size) {
    /* compute the required_size */
    ssize_t required_size{BinaryHeap<T>::countOfElement + array_size};

    /* if required_size is greater than
     * the current capacity of the heap */
    if (required_size > BinaryHeap<T>::capacity) {
        resize(required_size);
    }

    /* append the array elements in the heap */
    for (size_t i{0};i < array_size;i++) {
        BinaryHeap<T>::heapArray[BinaryHeap<T>::countOfElement + i] = array[i];
    }

    /* update the heap size */
    BinaryHeap<T>::countOfElement += array_size;

    /* initialize index with first non-leaf node */
    for (ssize_t index{(BinaryHeap<T>::countOfElement - 1) / 2}; index >= 0; index--) {
        percolate_down(index);
    }
}

/* destructor */
template <typename T>
BinaryHeap<T>::~BinaryHeap() {
    delete [] BinaryHeap<T>::heapArray;
}

#endif