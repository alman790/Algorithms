#include "helpers.h"

bool reader(std::ifstream &inp, Interpreter *&interpreter) {

    if (!inp.is_open()) return false;

    char symb;
    int current_w = 0, width = 0, height = 0;

    while (inp.get(symb)) {
        if (symb == '\n') {
            if (current_w > width) width = current_w;

            height++;
            current_w = 0;
        } else current_w++;
    }

    set_script_symb(interpreter, symb);

    if (current_w > 0) {
        if (current_w > width) width = current_w;
        height++;
    }

    set_sript_width(interpreter, width);
    set_sript_height(interpreter, height);

    inp.clear();
    inp.seekg(0);
    current_w = 0;

    while (inp.get(symb)) {
        if (symb == '\n') {
            while (current_w < get_script_width(interpreter)) {
                set_script_symb(interpreter, ' ');
                current_w++;
            }
            current_w = 0;
        } else {
            set_script_symb(interpreter, symb);
        }
    }

    return true;
}
