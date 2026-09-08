#include "helpers.h"

bool reader(std::ifstream &inp, Array *&arr) {
    int size;

    if (!inp.is_open()) return false;

    if (!(inp >> size)) return false;

    if (size < 0) return false;

    arr = array_create(size);

    for (int i = 0; i < size; i++) {
        Data val;

        if (!(inp >> val)) {
            array_delete(arr);
            arr = nullptr;
            return false;
        }

        array_set(arr, i, val);
    }

    inp.close();
    return true;
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

void writer(long long value) {
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
