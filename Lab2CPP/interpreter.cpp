#include "interpreter.h"

#include <iostream>

#include "stack.h"
#include "list.h"

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

    if (interpreter->x + interpreter->direction >= 0 && interpreter->x + interpreter->direction < interpreter->width) interpreter->x = interpreter->x + interpreter->direction;
    else return false;

    if (interpreter->y + 1 >= 0 && interpreter->y + 1 < interpreter->height) interpreter->y = interpreter->y + 1;
    else {
        interpreter->x = interpreter->x - interpreter->direction;
        return false;
    }

    return true;
}

Data get_current_symb(Interpreter *interpreter) {
    return get_script_symb_xy(interpreter, interpreter->x, interpreter->y);
}

void save_branch(Interpreter *interpreter, Data x, Data y, Data direction) {
    stack_push(interpreter->branch,x);
    stack_push(interpreter->branch,y);
    stack_push(interpreter->branch,direction);
}

bool open_branch(Interpreter *interpreter) {
    if (!stack_empty(interpreter->branch)) {
        interpreter->direction = stack_get(interpreter->branch);
        stack_pop(interpreter->branch);
        interpreter->y = stack_get(interpreter->branch);
        stack_pop(interpreter->branch);
        interpreter->x = stack_get(interpreter->branch);
        stack_pop(interpreter->branch);
        return true;
    }
    return false;
}

bool execute_current(Interpreter *interpreter) {
    char symb = get_current_symb(interpreter);
    if (interpreter->print_mode == true && symb != '\"') {
        std::cout << symb;
    } else {
        switch (symb) {
        case '/':
            interpreter->direction = -1;
            break;
        case '\\':
            interpreter->direction = 1;
            break;
        case '~':
            if (!open_branch(interpreter)) {
                return false;
            }
            break;
        case '^':
            interpreter->direction = 1;
            save_branch(interpreter, interpreter->x + 1, interpreter->y + 1, interpreter->direction);
            interpreter->direction = -1;
            break;
        case '+' : {
            Data a = stack_get(interpreter->data);
            stack_pop(interpreter->data);
            Data b = stack_get(interpreter->data);
            stack_pop(interpreter->data);
            stack_push(interpreter->data, (a + b) % 16);
            break;
        }
        case '-': {
            Data a = stack_get(interpreter->data);
            stack_pop(interpreter->data);
            Data b = stack_get(interpreter->data);
            stack_pop(interpreter->data);
            Data result = (b - a) % 16;

            if (result < 0) {
                result += 16;
            }

            stack_push(interpreter->data, result);
            break;
        }
        case ':': {
            Data a = stack_get(interpreter->data);
            stack_push(interpreter->data, a);
            break;
        }
        case '$': {
            stack_pop(interpreter->data);
            break;
        }
        case '%': {
            Data a = stack_get(interpreter->data);
            stack_pop(interpreter->data);
            Data b = stack_get(interpreter->data);
            stack_pop(interpreter->data);
            stack_push(interpreter->data,a);
            stack_push(interpreter->data,b);
            break;
        }
        case '?': {
            Data a = stack_get(interpreter->data);

            if (a == 0) {
                interpreter->direction = -1;
            } else {
                Data top = a - 1;

                stack_pop(interpreter->data);
                stack_push(interpreter->data, top);

                interpreter->direction = 1;
            }

            break;
        }
        case '.': {
            Data a = stack_get(interpreter->data);
            if (a >= 0 && a <= 9) {
                std::cout << static_cast<char>(a + '0');
            } else if (a >= 10 && a <= 15) {
                std::cout << static_cast<char>(a + 'A' - 10);
            }
            break;
        }
        case 'n':
            std::cout << '\n';
            break;
        case '\"':
            interpreter->print_mode = interpreter->print_mode == false ? true : false;
            break;
        case '{': {
            interpreter->ret_x = interpreter->x;
            interpreter->ret_y = interpreter->y;
            break;
        }
        case '}': {
            interpreter->x = interpreter->ret_x;
            interpreter->y = interpreter->ret_y;
            break;
        }
        default:
            if (symb >= '0' && symb <= '9') {
                stack_push(interpreter->data, symb - '0');
            } else if (symb >= 'A' && symb <= 'F') {
                stack_push(interpreter->data, symb - 'A' + 10);
            }
            break;
        }
    }

    return true;
}

//TODO:: make more interfaces and first worker with tree. For now I think it must be like DFS or something like this