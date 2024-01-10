#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

typedef struct node Node;

struct node
{
    int value;
    Node *next;
};

void * nextElement(void *current);
void setPointer(void *currentElement, void *newElement);

void main()
{
    config(nextElement, setPointer);

    Node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        Node *newElement = (Node *) malloc(sizeof(Node));
        newElement -> next = NULL;

        scanf("%d", &(newElement -> value));

        addLast(&head, newElement);
    }

    //free list
    for (int i = 0; i < 5; i++)
    {
        Node *temp = head;
        head = head -> next;
        free(temp);
    }
}

void * nextElement(void *current)
{
    Node *element = (Node *) current;

    return (void *) element -> next;
}

void setPointer(void *currentElement, void *newElement)
{
    Node *element = (Node *) currentElement;
    element -> next = (Node *)(newElement);
}