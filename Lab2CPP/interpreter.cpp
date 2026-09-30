#include "interpreter.h"

#include "stack.h"
#include "list.h"
#include "helpers.h"

struct Interpreter {

    List *script;

    Stack *data;
    Stack *branch;

    Data width;
    Data height;

    Data x;
    Data y;
    Data direction;


    Data ret_x;
    Data ret_y;

    bool print_mode;

    Interpreter() : script(list_create()), data(stack_create()), branch(stack_create()), width(0), height(0), x(0), y(0), direction(-1),ret_x(-1), ret_y(-1), print_mode(false) {}

    ~Interpreter() {
        stack_delete(data);
        stack_delete(branch);
        list_delete(script);
    }
};

void set_script_symb(Interpreter *interpreter, char symb) {
    list_insert(interpreter->script, symb);
}

void set_sript_width(Interpreter *interpreter, Data width) {
    interpreter->width = width;
}

void set_sript_height(Interpreter *interpreter, Data height) {
    interpreter->height = height;
}

//TODO:: make more interfaces and first worker with tree. For now I think it must be like DFS or something like this