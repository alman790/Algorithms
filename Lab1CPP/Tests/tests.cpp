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

bool run_program(std::string &program) {
    std::string command = "\"" + program + "\" ";
    return std::system(command.c_str()) == 0;
}

void check(std::string &name, std::string &actual, std::string &expected) {
    if (actual == expected) {
        std::cout << "[PASSED] : " << name  << "\n";
    } else {
        std::cout << "[FAILED] : " << name << "\n";
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
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "-2\n";
            std::string actual = read_out();
            std::string name = "task1: basic test";

            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "1\n"
                           "1";
        write_inp(test);

        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "1\n";
            std::string actual = read_out();
            std::string name = "task1: one int";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "1\n"
                           "-1\n";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "-1\n";
            std::string actual = read_out();
            std::string name = "task1: one negative int";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "2\n"
                           "21 5";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "16\n";
            std::string actual = read_out();
            std::string name = "task1: two els";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "4\n"
                           "4 -1 3 -3";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "11\n";
            std::string actual = read_out();
            std::string name = "task1: negative els in subtract position";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "6\n"
                           "-1 -2 -3 -4 -6 -5";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "1\n";
            std::string actual = read_out();
            std::string name = "task1: only negatives";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "7\n"
                           "-1 1 -2 2 -3 3 -5";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "-17\n";
            std::string actual = read_out();
            std::string name = "task1: mix";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "10\n"
                           "10 10 10 10 10 10 10 10 10 10";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "0\n";
            std::string actual = read_out();
            std::string name = "task1: only ten";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "0\n";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "0\n";
            std::string actual = read_out();
            std::string name = "task1: zero";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "";
            std::string actual = read_out();
            std::string name = "task1: white label";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "2\n"
                           "1 2 3";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "-1\n";
            std::string actual = read_out();
            std::string name = "task1: read only for size";
            check(name, actual, exp);
        }
    }
}

void test_task2(std::string &program) {
    {
        clear_out();
        std::string test = "8\n"
                           "100 7 42 10 11 40 2 70";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task2: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "40 42\n";
            std::string actual = read_out();
            std::string name = "task2: shuffled arr";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "7\n"
                           "18 5 100 18 3 40 2";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task2: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "18 18\n";
            std::string actual = read_out();
            std::string name = "task2: duplicate";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "8\n"
                           "-101 -100 -3 8 -6 15 -8 50";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task2: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "-8 -6\n";
            std::string actual = read_out();
            std::string name = "task2: neg and pos";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "8\n"
                           "20 101 102 103 7 40 70 200";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task2: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "20 40\n";
            std::string actual = read_out();
            std::string name = "task2: odd must be ign";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "8\n"
                           "-200 150 -2 99 80 2 -50 300";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "-2 2\n";
            std::string actual = read_out();
            std::string name = "task2: around zero";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "1\n"
                           "1";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "0 0\n";
            std::string actual = read_out();
            std::string name = "task2: one el";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "1\n"
                           "2";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task2: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "2 0\n";
            std::string actual = read_out();
            std::string name = "task2: one even";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "0\n";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task2: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "0 0\n";
            std::string actual = read_out();
            std::string name = "task2: zero els";
            check(name, actual, exp);
        }
    }

    {
        clear_out();

        std::string test =
            "2\n"
            "-2147483648 2147483646";

        write_inp(test);

        if (!run_program(program)) {
            std::cout << "[FAILED] task2: program error\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "-2147483648 2147483646\n";
            std::string actual = read_out();
            std::string name = "task2: extreme";

            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task2: programm error\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "";
            std::string actual = read_out();
            std::string name = "task2: white label";
            check(name, actual, exp);
        }
    }

    {
        clear_out();
        std::string test = "2\n"
                           "1 2 3";
        write_inp(test);
        if (!run_program(program)) {
            std::cout <<  "[FAILED] task1: programm error " << "\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "2 0\n";
            std::string actual = read_out();
            std::string name = "task1: read only for size";
            check(name, actual, exp);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Lab1CPP executable not specified\n";
        return 1;
    }

    std::string program1 = argv[1];
    std::string program2 = argv[2];

    test_task1(program1);
    test_task2(program2);

    std::cout << '\n';

    if (FAILED_TESTS == 0) {
        std::cout << "All tests passed!! Time for matcha latte with a coconut milk\n";
        return 0;
    }

    std::cout << FAILED_TESTS << " test(s) failed. sh..\n";

    return 1;
}