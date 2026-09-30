#ifndef ALGORITHMS_INTERPRETER_H
#define ALGORITHMS_INTERPRETER_H

#include "stack.h"

struct Interpreter;

void set_script_symb(Interpreter *interpreter, char symb);
void set_sript_width(Interpreter *interpreter, Data width);
void set_sript_height(Interpreter *interpreter, Data height);

#endif //ALGORITHMS_INTERPRETER_H
//TODO: make sure that the current design possible to do that