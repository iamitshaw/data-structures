#include "binary_heap.h"

template <typename T>
void heap_sort(T* array, ssize_t array_size) {
    BinaryHeap<T> binaryHeap(array_size);

    /* build binaryHeap from provided array elements */
    binaryHeap.build_heap(array, array_size);

    /* sorting procedure */
    for (int i = (binaryHeap.heap_size() - 1); i >= 0; i--) {
        array[i] = binaryHeap.extract_max();
    }
}

int main(int argc, char* argv[]) {
    /* define a seed value for random_number_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_number_generator with a seeded value */
    std::mt19937 random_number_generator(seed);

    /* define an range for random numbers */
    ssize_t left_bound{-37}, right_bound{37};
    std::uniform_int_distribution<ssize_t> distinct_element(left_bound, right_bound);

    /* define the  array_size */
    ssize_t array_size{11};

    /* allocate memory to store array elements */
    auto* array = new ssize_t[array_size] ;

    /* read the array elements */
    for (size_t i{0}; i < array_size; i+=1) {
        array[i] = distinct_element(random_number_generator);
    }

    /* print the array elements */
    std::cout << "\nArray elements:" << std::endl;
    for (size_t i{0}; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
    double start {static_cast<double>(clock())};
    heap_sort(array, array_size);
    double end {static_cast<double>(clock())};

    /* required time */
    double required_time {(end - start)/CLOCKS_PER_SEC};
    std::cout << "\nSorting time: " << required_time << std::endl;

    /* print sorted elements */
    std::cout << "\nSorted elements: " << std::endl;
    for (size_t i{0};i < array_size;i++) {
        std::cout << array[i] << " ";
    }
    /* de-allocate the heap memory */
    delete [] array;

    return 0;
}

