
/* Include Guard */

#ifndef _RECURSIVE_MERGE_SORT_H_
#define _RECURSIVE_MERGE_SORT_H_

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

/* recursive merge sort algorithm */
template <typename T>
void merge_sort(T* array, ssize_t right_index, ssize_t left_index=0) {
    if (left_index < right_index) {
        auto mid_index{left_index + (right_index - left_index)/2};

        /* sort left sub-array array[left_index..mid_index] */
        merge_sort(array, mid_index, left_index);

        /* sort right sub-array array[mid_index+1..right_index] */
        merge_sort(array, right_index, mid_index + 1);

        /* merge two sorted sub-arrays */
        merge_subarray(array, left_index, mid_index, right_index);
    }
}

#endif