#include <bits/stdc++.h>

void print_string(char* string) {
    int32_t i{0};

    /* print string characters */
    while (string[i] != '\0') {
        std::cout << string[i];
        i += 1;
    }std::cout << std::endl;
}

void permute_string(char* string, int32_t rightIndex, int32_t leftIndex=0) {
    static int32_t count{0};
    if (leftIndex >= (rightIndex - 1)) {
        /* print permutation */
        std::cout << std::setw(4) << ++count << ".\t";
        print_string(string);
    } else {
        for (int32_t i{leftIndex};i < rightIndex;i++) {
            std::swap(string[i], string[rightIndex-1]);

            /* recursive call */
            permute_string(string, rightIndex, leftIndex+1);

            std::swap(string[i], string[rightIndex-1]);
        }
    }
}

int32_t main(int32_t argc, char* argv[]) {
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /* define a seed value for random_generator */
    auto seed{std::chrono::system_clock::now().time_since_epoch().count()};

    /* declare a random_generator with a seeded value */
    std::mt19937 random_generator(seed);

    /* define an range for random numbers */
    int32_t left_bound{'A'}, right_bound{'Z'};
    std::uniform_int_distribution<int32_t> distinct(left_bound, right_bound);

    /* get size_of_array */
    int32_t size_of_array{6};

    /* get string_elements */
    auto* string = new char[size_of_array-1];

    /* null-terminated string */
    string[size_of_array - 1] = '\0';
    for (int32_t i{0};i < (size_of_array-1);i++) {
        string[i] = distinct(random_generator);
    }

    /* print string */
    std::cout << "\nString:\n";
    print_string(string);

    /* print different permutations */
    std::cout << "\nPermutation:\n";
    permute_string(string, size_of_array-1);
    return 0;
}