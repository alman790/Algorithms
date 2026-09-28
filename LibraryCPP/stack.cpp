#include <cstddef>
#include "stack.h"
#include "list.h"

struct Stack
{
    List* elements;
    size_t size;
    Stack() : elements(list_create()), size(0) {}
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
    stack->size++;
}

Data stack_get(const Stack *stack)
{
    if (stack->size == 0) return (Data) 0;
    return list_item_data(list_last(stack->elements));
}

void stack_pop(Stack *stack)
{
    if (stack->size > 0) {
        if (stack->size > 1) list_erase_next(stack->elements,list_item_prev(list_last(stack->elements)));
        else list_erase_first(stack->elements);
        stack->size--;
    }
}

bool stack_empty(const Stack *stack)
{
    return stack->size == 0;
}
