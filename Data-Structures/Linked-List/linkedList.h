extern void config(void * (*_nextElementFunc)(void *currentElement), 
                   void (*_setPointerFieldFunc)(void *currentElement, void *newElement),
                   int (*_deleteConditionFunc)(void *currentElement, void *data),
                   void (*_printFunc)(void *currentElement));
extern void addToList(void **head, void *newElement);
extern int deleteFromList(void **head, void *data);
extern void printList(void *head);