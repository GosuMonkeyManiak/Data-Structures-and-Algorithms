#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *prev;
};

void * prevElement(void *currentElement);
void setPointerField(void *currentElement, void *newElement);

void printStack(Node *top);
void freeStack(Node *top);

void main(void)
{
    configStack(prevElement, setPointerField);

    Node *top = NULL;

    int operation;

    do
    {
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Show top\n");
        printf("4. Print\n");
        printf("5. Exit\n");

        scanf("%d", &operation);

        switch (operation)
        {
            case 1:
                int data;
                
                printf("Element to push to stack: ");
                scanf("%d", &data);

                Node *newElement = (Node *) malloc(sizeof(Node));
                newElement -> data = data;
                newElement -> prev = NULL;

                push(&top, newElement);
                break;
        
            case 2:
                if (pop(&top))
                {
                    printf("Successfully!\n");
                }
                else
                {
                    printf("Something went wrong!\n");
                }
                break;

            case 3:
                if (top != NULL)
                {
                    printf("%d\n", top -> data);
                }
                else
                {
                    printf("The stack is empty!\n");
                }
                break;
            
            case 4:
                printStack(top);
                break;
        }

    } while (operation != 5);
    
    freeStack(top);
}

void * prevElement(void *currentElement)
{
    return (void *)(((Node *) currentElement) -> prev);
}

void setPointerField(void *currentElement, void *newElement)
{
    Node *curernt = (Node *) currentElement;
    curernt -> prev = (Node *) newElement;
}

void printStack(Node *top)
{
    if (top == NULL)
    {
        return;
    }

    while (top != NULL)
    {
        printf("%d ", top -> data);
        top = top -> prev;
    }
    
    printf("\n");
}

void freeStack(Node *top)
{
    if (top == NULL)
    {
        return;
    }

    Node *temp;

    while (top != NULL)
    {
        temp = top;
        top = top -> prev;

        free(temp);
    }
}