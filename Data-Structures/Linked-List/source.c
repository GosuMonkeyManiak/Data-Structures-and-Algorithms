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
        printf("1. Add new element to end of list\n");
        printf("2. Add new element to beginning of list\n");
        printf("3. Delete element from end of list\n");
        printf("4. Delete element from beginning of list\n");
        printf("5. Delete element from list by condition\n");
        printf("6. Print the list\n");
        printf("7. Exit\n");

        ReadingOpeationNumber:
        scanf("%d", &buffer);

        switch (buffer)
        {
            case 1:
                int elementValueToAddLast;
                printf("Enter element value: ");
                scanf("%d", &elementValueToAddLast);

                Node *newElementLast = (Node *) malloc(sizeof(Node));
                newElementLast -> next = NULL;
                newElementLast -> value = elementValueToAddLast;

                addLast(&head, newElementLast);
                countOfElements++;
                break;

            case 2:
                int elementValueToAddFirst;
                printf("Enter element value: ");
                scanf("%d", &elementValueToAddFirst);

                Node *newElementFirst = (Node *) malloc(sizeof(Node));
                newElementFirst -> next = NULL;
                newElementFirst -> value = elementValueToAddFirst;

                addFirst(&head, newElementFirst);
                countOfElements++;
                break;

            case 3:
                if (deleteLast(&head))
                {
                    countOfElements--;
                }
                else
                {
                    printf("Something went wrong!");
                }
                break;

            case 4:
                if (deleteFirst(&head))
                {
                    countOfElements--;
                }
                else
                {
                    printf("Something went wrong!");
                }
                break;

            case 5:
                int elementValueToDelete;
                printf("Enter element value: ");
                scanf("%d", &elementValueToDelete);

                if (deleteByCondition(&head, &elementValueToDelete))
                {
                    countOfElements--;
                }
                else
                {
                    printf("Something went wrong!\n");
                }
                break;

            case 6:
                printList(head);
                printf("\n");
                break;
        }

    } while (buffer != 7);
    

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