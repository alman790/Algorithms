#include <iostream>
#include <fstream>
#include <string>
#include "array.h"
#include "../LibraryCPPClass/array.h"

void writer(const Array *arr);
void writer(long value);
void reader(int choice);

int main() {
    reader(1);
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

    array_delete(arr);
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
