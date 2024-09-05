#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

void stack_init(Stack *stack);
void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
void stack_free(Stack *stack);

#endif

