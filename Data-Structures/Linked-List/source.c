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
int deleteCondition(void *currentElement, void *data);
void printElement(void *currentElement);

void freeList(Node *head);

void main()
{
    config(nextElement, setPointer, deleteCondition, printElement);

    Node *head = NULL;
    int buffer;
    int countOfElements = 0;

    do
    {
        printf("Count of elements: %d\n", countOfElements);
        printf("1. Add new element to list\n");
        printf("2. Delete element from list\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");

        ReadingOpeationNumber:
        scanf("%d", &buffer);

        switch (buffer)
        {
            case 1:
                int elementValueToAdd;
                printf("Enter element value: ");
                scanf("%d", &elementValueToAdd);

                Node *newElement = (Node *) malloc(sizeof(Node));
                newElement -> next = NULL;
                newElement -> value = elementValueToAdd;

                addToList(&head, newElement);
                countOfElements++;
                break;

            case 2:
                int elementValueToDelete;
                printf("Enter element value: ");
                scanf("%d", &elementValueToDelete);

                if (deleteFromList(&head, &elementValueToDelete))
                {
                    countOfElements--;
                }
                else
                {
                    printf("Something went wrong!\n");
                }
                break;

            case 3:
                printList(head);
                printf("\n");
                break;
        }

    } while (buffer != 4);
    

    freeList(head);
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

int deleteCondition(void *currentElement, void *data)
{
    Node *element = (Node *) currentElement;
    int *value = (int *) data;

    if (element -> value == *value)
    {
        return 1;
    }
    
    return 0;
}

void printElement(void *currentElement)
{
    printf("%d ", ((Node *) currentElement) -> value);
}

void freeList(Node *head)
{
    Node *temp = NULL;

    while (head != NULL)
    {
        temp = head;
        free(temp);
        
        head = head -> next;
    }
    
}