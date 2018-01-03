#ifndef SIMPLE_LIST_H_
#define SIMPLE_LIST_H_

struct List;

/**
* Constructors. NULL on error.
*/
struct List *List_create(void);
struct List *List_create_from(void **elements, unsigned int size);

/**
* Destructor.
*/
void List_destroy(struct List *list);

/**
* Adds an arbitrary element to the end of the list.
* Returns 1 on success, -1 on memory error, and 0 if element is null. 
* No type safety.
*/
int List_add(struct List *list, void *const element);

/**
* Deletes an element from the list.
* Returns 0 if the element is not in the list.
*/
int List_delete(struct List *list, const void *const element);

/**
* Returns true if the element is contained. False otherwise.
*/
_Bool List_contains(struct List *list, const void *const element);

/**
* Takes a random element of the list (doesn't delete it).
* NOTE: It's needed to use srand() before calling this function.
*/
void *List_take_random(const struct List *list);

/**
* Gets element at the beginning of the list.
*/
void *List_first(const struct List *const list);

/**
* Gets element at the end of the list.
*/
void *List_last(const struct List *const list);

/**
* Pops the element at the beginning.
*/
void *List_pop(struct List *list);

/**
* Gets the size of the list.
*/
unsigned int List_size(const struct List *const list);

#endif