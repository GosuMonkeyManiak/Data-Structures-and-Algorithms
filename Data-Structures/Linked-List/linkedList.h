extern void config(void * (*nextElementFunc)(void *currentElement), void (*setPointerFieldFunc)(void *currentElement, void *newElement));
extern void addLast(void **head, void *newElement);