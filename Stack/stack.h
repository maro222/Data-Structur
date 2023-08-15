#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef int stackEntry;

typedef struct StackNode{
    stackEntry item;
    struct StackNode* next;
}stackNode;

typedef struct Stack{
    stackNode* top;
    int size;
}stack;

void createStack(stack *ps);
void push(stack *ps, stackEntry element);
void pop(stack *ps, stackEntry* pe);
int stackEmpty(stack *ps);
int stackFull(stack *ps);
void clearStack(stack *ps);
void traverseStack(stack *ps, void (*pf)(stackEntry));
int sizeStack(stack *ps);
#endif //STACK_STACK_H
