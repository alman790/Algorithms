#include <iostream>
#include <fstream>
#include <string>
#include "array.h"

void writer(const Array *arr);
void writer(long value);
void reader(int choice);
void quicksort(Array *arr, size_t left, size_t right);

int main() {
    reader(2);
    return 0;
}

void task1(Array *arr) {
    long accumulator = 0;

    for (size_t i = 0; i < array_size(arr); i++) {
        if (i % 2 == 0) accumulator += static_cast<long>(array_get(arr, i));
        else accumulator -= static_cast<long>(array_get(arr, i));
    }

    writer(accumulator);
    array_delete(arr);
}

void task2(Array *arr) {
    Array *res = array_create(2);
    int count_even = 0, min = INT_MAX;

    for (size_t i = 0; i < array_size(arr); i++) {
        if (array_get(arr, i) % 2 == 0) count_even++;
    }

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

void quicksort(Array *arr, size_t left, size_t right) {
    int i = static_cast<int>(left), j = static_cast<int>(right);

    Data pivot = array_get(arr, left);

    while (i <= j) {
        while (array_get(arr, i) < pivot) i++;
        while (array_get(arr, j) > pivot) j--;
        if (i <= j) {
            Data temp = array_get(arr, i);
            array_set(arr, i, array_get(arr, j));
            array_set(arr, j, temp);
            i++;
            j--;
        }
    }

    if (static_cast<int>(left) < j) quicksort(arr, left, j);
    if (static_cast<int>(right) > i) quicksort(arr, i, right);
}

void reader(int choice) {
    int size;
    std::ifstream input("input.txt");

    if (!input.is_open()) return;

    while (input >> size) {
        Array *arr = array_create(size);

        for (int i = 0; i < size; i++) {
            Data val;
            input >> val;
            array_set(arr, i, val);
        }

        switch (choice) {
            case 1:
                task1(arr);
                break;
            case 2:
                task2(arr);
                break;
            default:
                break;
        }
    }
    input.close();
}

void writer(const Array *arr) {
    std::ofstream output("output.txt");
    if (!output.is_open()) return;

    for (size_t i = 0; i < array_size(arr); i++) {
        if (i > 0) output << " ";
        output << array_get(arr, i);
    }
    output << "\n";
    output.close();
}

void writer(long value) {
    std::ofstream output("output.txt", std::ios::app);

    if (!output.is_open()) return;

    output << value;
    output << "\n";
    output.close();
}
