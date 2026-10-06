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

Data get_script_symb(Interpreter *interpreter, Data position) {

    if (position < 0 || position >= list_size(interpreter->script)) {
        return  -1;
    }

    int i = 0;
    ListItem* current = list_first(interpreter->script);

    while (i < position) {
        current = list_item_next(current);
        i++;
    }

    return list_item_data(current);
}

Data get_script_symb_xy(Interpreter *interpreter, Data x, Data y) {
    if (x < 0 || x >= interpreter->width || y < 0 || y >= interpreter->height) {
        return -1;
    }

    Data position = y * interpreter->width + x;

    if (position < 0 || position >= list_size(interpreter->script)) {
        return  -1;
    }

    return get_script_symb(interpreter, position);
}

void set_sript_width(Interpreter *interpreter, Data width) {
    interpreter->width = width;
}

Data get_script_width(Interpreter *interpreter) {
    return interpreter->width;
}

void set_sript_height(Interpreter *interpreter, Data height) {
    interpreter->height = height;
}

Data get_script_height(Interpreter *interpreter) {
    return interpreter->height;
}

bool find_start(Interpreter *interpreter) {

    interpreter->x = 0;
    interpreter->y = 0;

    bool result = false;
    int size = 0;

    while (!result && size < list_size(interpreter->script)) {
        if (get_script_symb_xy(interpreter, interpreter->x, interpreter->y) == '*') {
            result = true;
        } else {
            if (interpreter->x < interpreter->width - 1) interpreter->x++;
            else {
                interpreter->x = 0;
                interpreter->y++;
            }
        }
        size++;
    }
    return result;
}

bool step(Interpreter *interpreter) {
    bool result = true;

    if (interpreter->x + interpreter->direction >= 0 && interpreter->x + interpreter->direction < interpreter->width) interpreter->x = interpreter->x + interpreter->direction;
    else return false;

    if (interpreter->y + 1 >= 0 && interpreter->y + 1 < interpreter->height) interpreter->y = interpreter->y + 1;
    else {
        interpreter->x = interpreter->x - interpreter->direction;
        return false;
    }

    return true;
}

//TODO:: make more interfaces and first worker with tree. For now I think it must be like DFS or something like this