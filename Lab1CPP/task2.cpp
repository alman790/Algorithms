#include "task2.h"

void task2(Array *arr) {
    Array *res = array_create(2);
    int count_even = 0, min = INT_MAX;

    for (size_t i = 0; i < array_size(arr); i++) {
        if (array_get(arr, i) % 2 == 0) count_even++;
    }

    if (count_even == 0) {
        array_set(res, 0, 0);
        array_set(res, 1, 0);
        writer(res);
        array_delete(res);
        array_delete(arr);
    } else if (count_even == 1) {
        size_t index = 0;
        for (size_t i = 0; i < array_size(arr); i++) {
            if (array_get(arr, i) % 2 == 0) index = i;
        }
        array_set(res, 0, array_get(arr, index));
        array_set(res, 1, 0);
        writer(res);
        array_delete(res);
        array_delete(arr);
    } else {
        Array *even = array_create(count_even);
        size_t j = 0;
        for (size_t i = 0; i < array_size(arr); i++) {
            if (array_get(arr, i) % 2 == 0) {
                array_set(even, j, array_get(arr, i));
                j++;
            }
        }

        if (count_even > 0) {
            quicksort(even, 0, array_size(even) - 1);
        }

        for (size_t i = 0; i < array_size(even) - 1; i++) {
            int diff = array_get(even, i + 1) - array_get(even, i);
            if (diff < min) {
                min = diff;
                array_set(res, 0, array_get(even, i));
                array_set(res, 1, array_get(even, i + 1));
            }
        }
        writer(res);
        array_delete(arr);
        array_delete(even);
        array_delete(res);
    }
}