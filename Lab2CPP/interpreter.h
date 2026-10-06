#ifndef ALGORITHMS_INTERPRETER_H
#define ALGORITHMS_INTERPRETER_H

#include "stack.h"

struct Interpreter;

void set_script_symb(Interpreter *interpreter, char symb);
Data get_script_symb(Interpreter *interpreter, Data position);
Data get_script_symb_xy(Interpreter *interpreter, Data x, Data y);
void set_sript_width(Interpreter *interpreter, Data width);
Data get_script_width(Interpreter *interpreter);
void set_sript_height(Interpreter *interpreter, Data height);
Data get_script_height(Interpreter *interpreter);
bool find_start(Interpreter *interpreter);
bool step(Interpreter *interpreter);

#endif //ALGORITHMS_INTERPRETER_H
//TODO: make sure that the current design possible to do that