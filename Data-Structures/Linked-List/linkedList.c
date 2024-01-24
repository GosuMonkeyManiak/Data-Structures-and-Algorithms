#include "linkedList.h"
#include <stdlib.h>

static int isListEmpty(void *head);

static void * (*nextElementFunc)(void *currentElement);
static void (*setPointerFieldFunc)(void *currentElement, void *newElement);
static int (*deleteConditionFunc)(void *currentElement, void *data);
static void (*printFunc)(void *currentElement);

void configList(void * (*_nextElementFunc)(void *currentElement),
            void (*_setPointerFieldFunc)(void *currentElement, void *newElement),
            int (*_deleteConditionFunc)(void *currentElement, void *data),
            void (*_printFunc)(void *currentElement))
{
    nextElementFunc = _nextElementFunc;
    setPointerFieldFunc = _setPointerFieldFunc;
    deleteConditionFunc = _deleteConditionFunc;
    printFunc = _printFunc;
}

void addFirst(void **head, void *newElement)
{
    if (isListEmpty(*head))
    {
        *head = newElement;
        return;
    }

    (*setPointerFieldFunc)(newElement, *head);

    *head = newElement;
}

void addLast(void **head, void *newElement)
{
    if (isListEmpty(*head))
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

int deleteByCondition(void **head, void *data)
{
    if (isListEmpty(*head))
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

int deleteFirst(void **head)
{
    if (isListEmpty(*head))
    {
        return 0;
    }
    
    void *temp = *head;

    void *nextElement = (*nextElementFunc)(*head);
    *head = nextElement;

    free(temp);

    return 1;
}

int deleteLast(void **head)
{
    if (isListEmpty(*head))
    {
        return 0;
    }

    void *current = *head;
    void *prev = *head;

    while ((*nextElementFunc)(current) != NULL)
    {
        prev = current;
        current = (*nextElementFunc)(current);
    }

    (*setPointerFieldFunc)(prev, NULL);
    
    free(current);

    return 1;
}

void printList(void *head)
{
    while (head != NULL)
    {
        (*printFunc)(head);
        head = (*nextElementFunc)(head);
    }
}

static int isListEmpty(void *head)
{
    return head == NULL ? 1 : 0;
}