#include <bits/stdc++.h>

/* binary string generator */
void binary_string(char* binaryString, int32_t endIndex, int32_t startIndex=0) {

    /* static variable to store
     * count of string generated */
    static int32_t count{1};

    if (startIndex >= endIndex) {
        /* print binary-string */
        std::cout << std::setw(endIndex + 1) << count++ ;
        std::cout << ".\t" << binaryString << std::endl;
    } else {
        /* substitute both possibility
         * of values either '0' or '1' */
        binaryString[startIndex] = '0';
        binary_string(binaryString, endIndex, startIndex + 1);

        binaryString[startIndex] = '1';
        binary_string(binaryString, endIndex, startIndex + 1);
    }
}

/* driver program */
int32_t main(int32_t argc, char* argv[]) {

    /* declare a variable to store
     * length of binary-string */
    const int32_t length_of_array{6};

    /* allocate heap memory to store
     * binary-string representation */
    auto* binary = new char[length_of_array];

    int32_t length_of_binary_string{length_of_array-1};

    /* null terminated character array */
    binary[length_of_binary_string] = '\0';

    binary_string(binary, length_of_binary_string);

    /* de-allocate heap memory */
    delete [] binary;

    return 0;
}