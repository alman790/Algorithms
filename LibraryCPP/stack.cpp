#include "stack.h"
#include "list.h"

struct Stack
{
    List* elements;
    Stack() : elements(list_create()) {}
    ~Stack() {
        list_delete(elements);
    }
};

Stack *stack_create()
{
    return new Stack;
}

void stack_delete(Stack *stack)
{
    delete stack;
}

void stack_push(Stack *stack, Data data)
{
    list_insert(stack->elements, data);
}

Data stack_get(const Stack *stack)
{
    if (list_first(stack->elements) == nullptr) return (Data) 0;
    return list_item_data(list_first(stack->elements));
}

void stack_pop(Stack *stack)
{
    if (list_first(stack->elements) != nullptr) list_erase_first(stack->elements);
}

bool stack_empty(const Stack *stack)
{
    return list_first(stack->elements) == nullptr;
}
