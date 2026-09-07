#include "task1.h"

void task1(Array *arr) {
    long accumulator = 0;

    for (size_t i = 0; i < array_size(arr); i++) {
        if (i % 2 == 0) accumulator += static_cast<long>(array_get(arr, i));
        else accumulator -= static_cast<long>(array_get(arr, i));
    }

    writer(accumulator);
    array_delete(arr);
}