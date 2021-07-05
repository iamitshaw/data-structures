#include "iterative.h"

/* random input of array elements */
int main(int argc, char* argv[]) {

    /* define a seed value for random_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_generator with a seeded value */
    std::mt19937 random_generator(seed);

    /* define an range for random numbers */
    ssize_t left_bound{-37}, right_bound{37};
    std::uniform_int_distribution<int64_t> distinct_element(left_bound, right_bound);

    /* define array_size */
    size_t array_size{11};

    /* allocate memory to store array elements */
    auto* array = new int64_t[array_size];

    /* read array elements */
    for (size_t i{0}; i < array_size; i+=1) {
        array[i] = distinct_element(random_generator);
    }

    /* print original array elements */
    std::cout << "\nArray elements:" << std::endl;
    for (ssize_t i{0}; i < array_size; i++) {
        std::cout << array[i] << " ";
    }

    /* sort array elements */
    merge_sort(array, array_size);

    /* print sorted array elements */
    std::cout << "\nSorted elements:" << std::endl;
    for (ssize_t i{0}; i < array_size; i++) {
        std::cout << array[i] << " ";
    }

    /* de-allocate heap memory */
    delete [] array;

    return 0;
}