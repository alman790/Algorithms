#include <iostream>
#include <string>
#include "interpreter.h"

int FAILED_TESTS = 0;

void check(std::string &name, std::string &actual, std::string &expected) {
    if (actual == expected) {
        std::cout << "[PASSED] : " << name << "\n";
    } else {
        std::cout << "[FAILED] : " << name << "\n";
        std::cout << actual << " != " << expected << "\n";
        FAILED_TESTS++;
    }
}

int main() {
    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 3);

        std::string name = "Interpreter: Test setter and getter for width";
        std::string actual = std::to_string(get_script_width(interpreter));
        std::string expected = "3";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_height(interpreter, 5);

        std::string name = "Interpreter: Test setter and getter for height";
        std::string actual = std::to_string(get_script_height(interpreter));
        std::string expected = "5";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 6);
        set_sript_height(interpreter, 4);

        std::string name = "Interpreter: Test setter for width and height";
        std::string actual = std::to_string(get_script_width(interpreter)) + " " +std::to_string(get_script_height(interpreter));

        std::string expected = "6 4";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');

        std::string name = "Interpreter: Test getter for last symbol";
        std::string actual;

        actual += static_cast<char>(get_script_symb(interpreter, 3));
        std::string expected = "D";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'C');

        std::string name = "Interpreter: Test setter for symbols";

        std::string actual;
        actual += static_cast<char>(get_script_symb(interpreter, 0));
        actual +=  " ";
        actual += static_cast<char>(get_script_symb(interpreter, 1));
        actual +=  " ";
        actual += static_cast<char>(get_script_symb(interpreter, 2));
        actual +=  " ";
        actual += static_cast<char>(get_script_symb(interpreter, 3));
        actual +=  " ";
        actual += static_cast<char>(get_script_symb(interpreter, 4));
        actual +=  " ";
        actual += static_cast<char>(get_script_symb(interpreter, 5));

        std::string expected = "A A B B C C";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 3);
        set_sript_height(interpreter, 2);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');

        std::string name = "Interpreter: Test getter by position";

        std::string actual;
        actual += static_cast<char>(get_script_symb(interpreter, 5));

        std::string expected = "D";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');

        std::string name = "Interpreter: Test getter by invalid position";

        std::string actual = std::to_string(get_script_symb(interpreter, -1)) + " " + std::to_string(get_script_symb(interpreter, 3));

        std::string expected = "-1 -1";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 3);
        set_sript_height(interpreter, 2);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');

        std::string name = "Interpreter: Test getter by matrix coordinate";

        std::string actual;
        actual += static_cast<char>(get_script_symb_xy(interpreter, 1, 1));

        std::string expected = "C";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 2);
        set_sript_height(interpreter, 2);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');

        std::string name = "Interpreter: Test getter by invalid matrix coordinate";

        std::string actual = std::to_string(get_script_symb_xy(interpreter, -1, 0)) + " " + std::to_string(get_script_symb_xy(interpreter, 2, 0)) + " " + std::to_string(get_script_symb_xy(interpreter, 0, 2));

        std::string expected = "-1 -1 -1";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 3);
        set_sript_height(interpreter, 2);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, '*');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');
        set_script_symb(interpreter, 'E');

        std::string name = "Interpreter: Test find start";

        if (!find_start(interpreter)) {
            FAILED_TESTS++;
            interpreter_delete(interpreter);
            std::cout << "[FAILED] Interpreter: Test find start\n";
        } else {
            std::string actual;
            actual += static_cast<char>(get_current_symb(interpreter));
            std::string expected = "*";

            check(name, actual, expected);

            interpreter_delete(interpreter);
        }
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 3);
        set_sript_height(interpreter, 2);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');
        set_script_symb(interpreter, 'E');
        set_script_symb(interpreter, 'F');

        std::string name = "Interpreter: Test find start without start";

        std::string actual;

        if (find_start(interpreter)) {
            actual = "true";
        } else {
            actual = "false";
        }

        std::string expected = "false";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 3);
        set_sript_height(interpreter, 2);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, '*');
        set_script_symb(interpreter, 'B');

        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');
        set_script_symb(interpreter, 'E');

        find_start(interpreter);

        std::string name = "Interpreter: Test step";

        std::string actual;

        if (step(interpreter)) {
            actual += static_cast<char>(get_current_symb(interpreter));
        } else {
            actual = "false";
        }

        std::string expected = "C";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 2);
        set_sript_height(interpreter, 2);

        set_script_symb(interpreter, '*');
        set_script_symb(interpreter, 'A');

        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');

        find_start(interpreter);

        std::string name = "Interpreter: Test step outside script";

        std::string actual;

        if (step(interpreter)) {
            actual = "true";
        } else {
            actual = "false";
        }

        std::string expected = "false";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        std::string name = "Interpreter: Test open empty branch";

        std::string actual;

        if (open_branch(interpreter)) {
            actual = "true";
        } else {
            actual = "false";
        }

        std::string expected = "false";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 4);
        set_sript_height(interpreter, 3);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');

        set_script_symb(interpreter, 'E');
        set_script_symb(interpreter, 'F');
        set_script_symb(interpreter, 'G');
        set_script_symb(interpreter, 'H');

        set_script_symb(interpreter, 'I');
        set_script_symb(interpreter, 'J');
        set_script_symb(interpreter, 'K');
        set_script_symb(interpreter, 'L');

        save_branch(interpreter, 0, 1, -1);
        save_branch(interpreter, 2, 1, 1);

        std::string name = "Interpreter: Test branch stack";

        std::string actual;

        open_branch(interpreter);
        actual += static_cast<char>(get_current_symb(interpreter));

        actual += " ";

        open_branch(interpreter);
        actual += static_cast<char>(get_current_symb(interpreter));

        std::string expected = "G E";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 4);
        set_sript_height(interpreter, 3);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');

        set_script_symb(interpreter, 'E');
        set_script_symb(interpreter, 'F');
        set_script_symb(interpreter, 'G');
        set_script_symb(interpreter, 'H');

        set_script_symb(interpreter, 'I');
        set_script_symb(interpreter, 'J');
        set_script_symb(interpreter, 'K');
        set_script_symb(interpreter, 'L');

        save_branch(interpreter, 2, 1, 1);

        std::string name = "Interpreter: Test save and open branch";

        std::string actual;

        if (open_branch(interpreter)) {
            actual += static_cast<char>(get_current_symb(interpreter));
        } else {
            actual = "false";
        }

        std::string expected = "G";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 4);
        set_sript_height(interpreter, 3);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, 'B');
        set_script_symb(interpreter, 'C');
        set_script_symb(interpreter, 'D');

        set_script_symb(interpreter, 'E');
        set_script_symb(interpreter, 'F');
        set_script_symb(interpreter, 'G');
        set_script_symb(interpreter, 'H');

        set_script_symb(interpreter, 'I');
        set_script_symb(interpreter, 'J');
        set_script_symb(interpreter, 'K');
        set_script_symb(interpreter, 'L');

        save_branch(interpreter, 2, 1, 1);
        open_branch(interpreter);

        std::string name = "Interpreter: Test branch direction";

        std::string actual;

        if (step(interpreter)) {
            actual += static_cast<char>(get_current_symb(interpreter));
        } else {
            actual = "false";
        }

        std::string expected = "L";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 1);
        set_sript_height(interpreter, 1);

        set_script_symb(interpreter, '~');

        std::ifstream input;

        std::string name = "Interpreter: Test execute current";

        std::string actual;

        if (execute_current(interpreter, input)) {
            actual = "true";
        } else {
            actual = "false";
        }

        std::string expected = "false";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    {
        Interpreter* interpreter = interpreter_create();

        set_sript_width(interpreter, 2);
        set_sript_height(interpreter, 2);

        set_script_symb(interpreter, 'A');
        set_script_symb(interpreter, '*');
        set_script_symb(interpreter, '~');
        set_script_symb(interpreter, 'B');

        std::ifstream input;

        std::string name = "Interpreter: Test loop";

        std::string actual;

        if (loop(interpreter, input)) {
            actual = "true";
        } else {
            actual = "false";
        }

        std::string expected = "true";

        check(name, actual, expected);

        interpreter_delete(interpreter);
    }

    std::cout << '\n';

    if (FAILED_TESTS == 0) {
        std::cout << "All tests passed!! Time for matcha latte with a coconut milk\n";
        return 0;
    }

    std::cout << FAILED_TESTS << " test(s) failed. sh..\n";

    return 1;
}