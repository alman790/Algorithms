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
    return list_item_data(list_first(stack->elements));
}

void stack_pop(Stack *stack)
{
    if (stack->size > 0) {
        list_erase_first(stack->elements);
        stack->size--;
    }
}

bool stack_empty(const Stack *stack)
{
    return stack->size == 0;
}
