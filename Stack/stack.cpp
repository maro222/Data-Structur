#include "stack.h"
#include <stdlib.h>

void createStack(stack *ps){
    ps->top = NULL;
    ps->size = 0;
}

void push(stack *ps, stackEntry element){
    stackNode* pn = (stackNode*)malloc(sizeof(stackNode));
    if (!pn)
        exit(1);
    pn->item = element;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}

void pop(stack *ps, stackEntry* pe){
    stackNode* pt = ps->top;
    *pe = ps->top->item;
    ps->top = ps->top->next;
    free(pt);
    pt = NULL;
    ps->size--;
}

int stackEmpty(stack *ps){
    return (ps->top == NULL);
}

int stackFull(stack *ps){
    return 0; //always 0 because it's dynamic no static
}

void clearStack(stack *ps){   //O(n)
    stackNode *pn = ps->top;

    while(ps->top){
        ps->top = ps->top->next;
        free(pn);
        pn = ps->top;
    }
    ps->size = 0;
}

void traverseStack(stack *ps, void (*pf)(stackEntry)){
    stackNode* pn = ps->top;
    while (pn){
        (*pf)(pn->item);
        pn = pn->next;
    }
}

int sizeStack(stack *ps){
    return (ps->size);
}