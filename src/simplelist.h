#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

struct List;

/**
* Initializes the list. Use this before anything else.
*/
void List_init(struct List *list);

/**
* Adds an arbitrary element to the end of the list.
* No type safety.
*/
int List_add(struct List *list, void *element);

/**
* Deletes an element from the list.
* Returns 0 if the element is not in the list.
*/
int List_delete(struct List *list, void *element);

/**
* Returns true if the element is contained. False otherwise.
*/
_Bool List_contains(struct List *list, void *element);

#endif