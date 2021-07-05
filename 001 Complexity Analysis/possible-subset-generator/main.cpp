#include <bits/stdc++.h>

template <typename T>
void generateSubsets(T* array, int32_t start_index, int32_t end_index, std::vector<T>& set_element) {
    /* count total generated subset */
    static int32_t counter{1};

    if (start_index <= end_index) {
        /* include corresponding element */
        set_element.push_back(array[start_index]);
        generateSubsets(array,start_index+1,end_index,set_element);

        /* exclude corresponding element */
        set_element.pop_back();
        generateSubsets(array,start_index+1,end_index,set_element);
    } else {
        /* print obtained sub-set */
        std::cout.width(2);
        std::cout.fill('0') ;
        std::cout << counter << ". { ";

        for (const auto& element: set_element) {
            std::cout << element << " ";
        }

        std::cout << "}" << std::endl;
        counter += 1;
    }
}

int32_t main(int32_t argc, char* argv[]) {
    /* declare size_of_array */
    int32_t array_size{10};

    /* declare left_bound & right_bound for array elements */
    int32_t left_bound{-91}, right_bound{91};

    /* declare an array */
    auto* array = new int32_t[array_size];

    /* initialize random_seed */
    auto random_seed {std::chrono::system_clock::now().time_since_epoch().count()};
    std::mt19937 random_generator(random_seed);

    std::uniform_int_distribution<int32_t> distinct(left_bound, right_bound);

    /* get random element for array elements */
    for (int32_t i{0}; i < array_size; i++) {
        *(array + i) = distinct(random_generator);
    }

    std::cout << "\nArray Elements: " << std::endl;

    /* print the array elements */
    for (size_t i{0}; i < array_size; i++) {
        std::cout << *(array + i) << " ";
    }std::cout << "\n" << std::endl;

    /*generate possible sub-sets of provided set */

    std::vector<int32_t> set_element;
    generateSubsets(array,0,array_size-1,set_element);

    return 0;
}