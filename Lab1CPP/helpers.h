#ifndef ALGORITHMS_HELPERS_H
#define ALGORITHMS_HELPERS_H

#include "array.h"
#include "task1.h"
#include "task2.h"
#include <fstream>
#include <climits>

void writer(const Array *arr);
void writer(long value);
void reader(int choice);
void quicksort(Array *arr, size_t left, size_t right);

#endif //ALGORITHMS_HELPERS_H
