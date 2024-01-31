#ifndef LINKEDLIST

#define LINKEDLIST

extern void configList(void * (*_nextElementFunc)(void *currentElement), 
                   void (*_setPointerFieldFunc)(void *currentElement, void *newElement),
                   int (*_deleteConditionFunc)(void *currentElement, void *data),
                   void (*_printFunc)(void *currentElement));
extern void addFirst(void **head, void *newElement);
extern void addLast(void **head, void *newElement);
extern int deleteByCondition(void **head, void *data);
extern int deleteFirst(void **head);
extern int deleteLast(void **head);
extern void printList(void *head);

#endif