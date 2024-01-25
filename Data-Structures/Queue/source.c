#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

void * nextElement(void *currentElement);
void setPointerField(void *currentElement, void *newElement);

void printQueue(Node *head);
void freeQueue(Node *head);

void main(void)
{
    configQueue(nextElement, setPointerField);

    Node *head = NULL;

    int operation;

    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Exit\n");

        scanf("%d", &operation);

        switch (operation)
        {
            case 1:
                int data;

                printf("Enter data: ");
                scanf("%d", &data);

                Node *newElement = (Node *) malloc(sizeof(Node));
                newElement -> data = data;
                newElement -> next = NULL;

                enqueue(&head, newElement);
                break;

            case 2:
                if (dequeue(&head))
                {
                    printf("Successfully!\n");
                }
                else
                {
                    printf("Something went wrong!\n");
                }
                break;

            case 3:
                printQueue(head);
                break;
        }

    } while (operation != 4);

    freeQueue(head);   
}

void * nextElement(void *currentElement)
{
    return (void *)(((Node *) currentElement) -> next);
}

void setPointerField(void *currentElement, void *newElement)
{
    Node *temp = (Node *) currentElement;
    temp -> next = (Node *) newElement;
}

void printQueue(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    while (head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
    
    printf("\n");
}

void freeQueue(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head -> next;

        free(temp);
    }
    
}