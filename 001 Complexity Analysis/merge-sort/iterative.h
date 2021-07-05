
/* Include Guard */

#ifndef _ITERATIVE_MERGE_SORT_H
#define _ITERATIVE_MERGE_SORT_H

#include <bits/stdc++.h>

/* merge the two sorted sub-arrays - left and right sub-array */
template <typename T>
void merge_subarray(T* array, ssize_t left, ssize_t mid, ssize_t right) {

    /* find the size of left sub-array and right sub-array */
    ssize_t size_of_left_subarray {(mid - left + 1)};
    ssize_t size_of_right_subarray {right - (mid + 1) + 1};

    /* allocate memory for left sub-array and right sub-array  */
    auto* left_subarray = new T[size_of_left_subarray];
    auto* right_subarray = new T[size_of_right_subarray];

    /* copy the content of left sub-array */
    for (ssize_t i{0};i < size_of_left_subarray;i++) {
        left_subarray[i] = array[left + i];
    }

    /* copy the content of right sub-array */
    for (ssize_t i{0};i < size_of_right_subarray;i++) {
        right_subarray[i] = array[mid + 1 + i];
    }

    /* initial index for left sub-array, right
     * sub-array and merged-array respectively */
    ssize_t i{0}, j{0}, k{left};

    /* merge the left_subarray and right_subarray in sorted order */
    while (i < size_of_left_subarray && j < size_of_right_subarray) {
        if (left_subarray[i] <= right_subarray[j]) {
            array[k++] = left_subarray[i++];
        } else {
            array[k++] = right_subarray[j++];
        }
    }

    /* if any element of the left sub-array is being
     * unprocessed then copy the remaining elements */
    while (i < size_of_left_subarray) {
        array[k++] = left_subarray[i++];
    }

    /* if any element of the right sub-array is being
     * unprocessed then copy the remaining elements */
    while (j < size_of_right_subarray) {
        array[k++] = right_subarray[j++];
    }

    /* de-allocate the heap memory allocated
     * for left_subarray and right_subarray */
    delete [] left_subarray;
    delete [] right_subarray;
}

/* iterative merge sort : merge sub-arrays in bottom up manner.*/
template <typename T>
void merge_sort(T* array, ssize_t size_of_array) {
    /* first merge sub-arrays of size 1 to create sorted sub-arrays of size 2,
     * then merge subarray of size 2 to create sorted sub-arrays of size 4 etc. */
    for (ssize_t current_size{1}; current_size < size_of_array; current_size *= 2) {

        /* pick starting point of different sub-array of current size */
        for (ssize_t left{0}; left < size_of_array - 1; left += 2 * current_size) {
            /* find ending point of left subarray */
            ssize_t mid {std::min(left + current_size - 1, size_of_array - 1)};

            /* find ending point of right subarray */
            ssize_t right {std::min(left + 2 * current_size - 1, size_of_array - 1)};

            /* merge sub-arrays array[left...mid] & array[mid+1...right] */
            merge_subarray(array, left, mid, right);
        }
    }
}

#endif