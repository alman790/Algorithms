#include "helpers.h"
#include "task2.h"

int main() {
    std::ifstream input("input.txt");

    if (!input.is_open()) {
        return -1;
    }

    Array *arr = nullptr;

    while (reader(input, arr)) {
        task2(arr);
    }

    input.close();
    return 0;
}