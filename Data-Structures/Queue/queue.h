#ifndef QUEUE

#define QUEUE

extern void configQueue(void * (*_nextElementFunc)(void *currentElement), void (*_setPointerFieldFunc)(void *currentElement, void *newElement));
extern void enqueue(void **head, void *newElement);
extern int dequeue(void **head);

#endif