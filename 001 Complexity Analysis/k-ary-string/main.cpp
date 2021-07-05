#include <bits/stdc++.h>

/* k-ary-string generator */
void k_ary_generator(char* k_ary_string, int32_t k_ary_value, int32_t endIndex, int32_t startIndex=0) {

    /* static variable to store
     * count of string generated */
    static int32_t count{1};

    if (startIndex >= endIndex) {
        /* print k-ary-string */
        std::cout << std::setw(endIndex + 1) << count++ ;
        std::cout << ".\t" << k_ary_string << std::endl;
    } else {
        for (int32_t i{0};i < k_ary_value;i++) {
            if (i < 10) {
                /* if i represents one
                 * of decimal digits */
                k_ary_string[startIndex] = (char)(i + 48);
            } else {
                /*if i represents decimal number
                 * greater than or equal to 10*/
                k_ary_string[startIndex] = (char)(i + 'A' - 10);
            }

            /* generate all possibility */
            k_ary_generator(k_ary_string,k_ary_value,endIndex,startIndex+1);
        }
    }
}

/* driver program */
int32_t main(int32_t argc, char* argv[]) {

    /* declare variable to store
     * length of k-ary-string */
    const int32_t length_of_array{4};
    const int32_t k_ary_value{16};

    /* allocate heap memory to store
     * k-ary-string representation */
    auto* k_ary_string = new char[length_of_array];

    int32_t k_ary_length{length_of_array - 1};

    /* null terminated character array */
    k_ary_string[k_ary_length] = '\0';

    k_ary_generator(k_ary_string, k_ary_value, k_ary_length);

    /* de-allocate heap memory */
    delete [] k_ary_string;

    return 0;
}