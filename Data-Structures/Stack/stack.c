#include "../Linked-List/linkedList.h"

#define NULL ((void *)0)

void configStack(void * (*_prevElementFunc)(void *currentElement), void (*_setPointerFieldFunc)(void *currentElement, void *newElement))
{
    configList(_prevElementFunc, _setPointerFieldFunc, NULL, NULL);
}

void push(void **top, void *newElement)
{
    addFirst(top, newElement);
}

int pop(void **top)
{
    return deleteFirst(top);
}