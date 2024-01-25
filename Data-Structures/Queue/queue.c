#include "../Linked-List/linkedList.h"

#include "queue.h"

#define NULL ((void *)0)

void configQueue(void * (*_nextElementFunc)(void *), void (*_setPointerFieldFunc)(void *, void *))
{
    configList(_nextElementFunc, _setPointerFieldFunc, NULL, NULL);
}

void enqueue(void **head, void *newElement)
{
    addLast(head, newElement);
}

int dequeue(void **head)
{
    return deleteFirst(head);
}