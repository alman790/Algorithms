#include "helpers.h"
#include <string>

int main(int argc, char *argv[]) {
    int choice = 2;
    if (argc > 1) {
        std::string input = argv[1];
        if (input == "1") choice = 1;
        else if (input == "2") choice = 2;
        else return 1;
    }
    reader(choice);
    return 0;
}
