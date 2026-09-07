#include "helpers.h"

void reader(int choice) {
    int size;
    std::ifstream input("input.txt");

    if (!input.is_open()) return;

    while (input >> size) {
        if (size < 0) return;

        Array *arr = array_create(size);

        for (int i = 0; i < size; i++) {
            Data val;

            if (!(input >> val)) {
                array_delete(arr);
                return;
            }

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
                array_delete(arr);
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
