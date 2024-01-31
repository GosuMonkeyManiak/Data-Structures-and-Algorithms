#ifndef STACK

#define STACK

extern void configStack(void * (*_prevElementFunc)(void *currentElement), void (*_setPointerFieldFunc)(void *currentElement, void *newElement));
extern void push(void **top, void *newElement);
extern int pop(void **top);

#endif