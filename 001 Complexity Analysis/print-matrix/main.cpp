#include <bits/stdc++.h>

/* print matrix elements */
void print_matrix(int32_t** matrix, int32_t row, int32_t column) {
    std::cout << "\nMatrix:\n";
    for (int32_t i{0};i < row;i++) {
        for (int32_t j{0};j < column;j++) {
            std::cout << std::setw(4) <<  matrix[i][j] << " ";
        }
        std::cout << std::endl;
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
    int32_t left_bound{-91}, right_bound{91};
    std::uniform_int_distribution<int32_t> distinct(left_bound, right_bound);

    /* get matrix_row */
    int32_t matrix_row{5};

    /* get matrix_column */
    int32_t matrix_column{6};

    /* allocate memory to store array elements */
    auto** matrix = new int32_t*[matrix_row];
    for (int32_t i{0};i < matrix_row;i++) {
        matrix[i] = new int32_t[matrix_column];
    }

    /* fill matrix with elements */
    for (int32_t i{0};i < matrix_row;i++) {
        for (int32_t j{0};j < matrix_column;j++) {
            matrix[i][j] = distinct(random_generator);
        }
    }

    /* print matrix elements */
    print_matrix(matrix, matrix_row, matrix_column);

    /* de-allocate heap memory */
    for (int32_t i{0};i < matrix_row;i++) {
        delete [] matrix[i];
    }delete [] matrix;
    return 0;
}