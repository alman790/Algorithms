#include "interpreter.h"
#include "helpers.h"

int main() {
    Interpreter *interpreter = interpreter_create();
    std::ifstream script_file("script.txt");
    std::ifstream input_file("input.txt");

    if (!script_file.is_open()) {
        interpreter_delete(interpreter);
        return 1;
    }

    if (!input_file.is_open()) {
        interpreter_delete(interpreter);
        return 1;
    }


    if (!reader(script_file, interpreter)) {
        interpreter_delete(interpreter);
        return 1;
    }

    if (!loop(interpreter, input_file)) {
        interpreter_delete(interpreter);
        return 1;
    }

    interpreter_delete(interpreter);
    script_file.close();
    input_file.close();
    return 0;
}