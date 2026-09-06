#include <iostream>
#include <fstream>
#include <string>

int FAILED_TESTS = 0;

void write_inp(std::string &text) {
    std::ofstream input("input.txt");
    input << text;
    input.close();
}

std::string read_out() {
    std::ifstream output("output.txt");

    std::string result;
    std::string line;

    while (std::getline(output, line)) {
        result += line;
        result += "\n";
    }

    return result;
}

void clear_out() {
    std::ofstream output("output.txt", std::ios::trunc);
}

bool run_program(std::string &program, int task) {
    std::string command = "\"" + program + "\" " + std::to_string(task);
    return std::system(command.c_str()) == 0;
}

void check(std::string &name, std::string &actual, std::string &expected) {
    if (actual == expected) {
        std::cout << name << ": PASSED" << "\n";
    } else {
        std::cout << name << ": FAILED" << "\n";
        std::cout << actual << " != " << expected << "\n";
        FAILED_TESTS++;
    }
}

void test_task1(std::string &program) {
    {
        clear_out();

        std::string test = "4\n"
                  "1 4 3 2";
        write_inp(test);
        if (!run_program(program, 1)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "-2\n";
            std::string actual = read_out();
            std::string name = "task1: basic test";

            check(name, actual, exp);
        }
    }

    // {
    //     clear_out();
    //
    // }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Lab1CPP executable not specified\n";
        return 1;
    }

    std::string program = argv[1];

    test_task1(program);

    std::cout << '\n';

    if (FAILED_TESTS == 0) {
        std::cout << "All tests passed!! Time for matcha latte with a coconut milk\n";
        return 0;
    }

    std::cout << FAILED_TESTS << " test(s) failed. sh..\n";

    return 1;
}

/*
 *
 * TODO: Add more test, improve the main lab1.cpp file, cause it's seems like shit, then dream about exceptions
 *
*/