#include "stack.h"
#include <stdlib.h>

void stack_init(Stack *stack) {
    stack->top = NULL;
}

void stack_push(Stack *stack, int value) {
    StackNode *new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

int stack_pop(Stack *stack) {
    if (stack->top == NULL) {
        return -1; // Stack is empty, handle error appropriately
    }

    StackNode *temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

void stack_free(Stack *stack) {
    while (stack->top != NULL) {
        stack_pop(stack);
    }
}
int stack_peek(Stack *stack){
    return stack->top->data;
}
