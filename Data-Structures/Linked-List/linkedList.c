#include "linkedList.h"
#include <stdlib.h>

static void* (*nextElementFunc)(void *currentElement);
static void (*setPointerFieldFunc)(void *currentElement, void *newElement);
static int (*deleteConditionFunc)(void *currentElement, void *data);
static void (*printFunc)(void *currentElement);

void config(void * (*_nextElementFunc)(void *currentElement),
            void (*_setPointerFieldFunc)(void *currentElement, void *newElement),
            int (*_deleteConditionFunc)(void *currentElement, void *data),
            void (*_printFunc)(void *currentElement))
{
    nextElementFunc = _nextElementFunc;
    setPointerFieldFunc = _setPointerFieldFunc;
    deleteConditionFunc = _deleteConditionFunc;
    printFunc = _printFunc;
}

void addToList(void **head, void *newElement)
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
        current = (*nextElementFunc)(current);
    }
    
    (*setPointerFieldFunc)(prev, newElement);
}

int deleteFromList(void **head, void *data)
{
    if (*head == NULL)
    {
        return 0;
    }

    void *current = *head;
    void *prev = *head;

    while (current != NULL)
    {
        if ((*deleteConditionFunc)(current, data))
        {
            if (current == prev)
            {
                *head = (*nextElementFunc)(current);
                free(current);
            }
            else
            {
                (*setPointerFieldFunc)(prev, (*nextElementFunc)(current));
                free(current);
            }
            
            return 1;
        }

        prev = current;
        current = (*nextElementFunc)(current);
    }

    return 0;
}

void printList(void *head)
{
    while (head != NULL)
    {
        (*printFunc)(head);
        head = (*nextElementFunc)(head);
    }
}