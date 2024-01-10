#include "linkedList.h"

#define NULL 0

static void* (*next)(void *currentElement);
static void (*setPointerField)(void *currentElement, void *newElement);

void config(void * (*nextElementFunc)(void *currentElement),
            void (*setPointerFieldFunc)(void *currentElement, void *newElement))
{
    next = nextElementFunc;
    setPointerField = setPointerFieldFunc;
}

void addLast(void **head, void *newElement)
{
    if (*head == NULL)
    {
        *head = newElement;
        return;
    }

    void *current = *head;
    void *prev = *head;

    while (current != NULL)
    {
        prev = current;
        current = (*next)(current);
    }
    
    (*setPointerField)(prev, newElement);
}
