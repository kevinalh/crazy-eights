#ifndef SIMPLE_LIST_H_
#define SIMPLE_LIST_H_

/**
 * Node of a List data structure.
 */
struct ListNode {
	/**
	 * @protected
	 * Element in the List.
	 */
	void *element;
	/**
	 * @protected
	 * Next node in the List.
	 */
	struct ListNode *next;
};

/**
 * Simple list data structure.
 */
struct List {
	/**
	 * @protected
	 * Size of the list.
	 */
	unsigned int size;
	/**
	 * @protected
	 * First node in the list.
	 * NULL if it's empty.
	 */
	struct ListNode *begin;
	/**
	 * @protected
	 * Final node in the list.
	 * NULL is it's empty.
	 */
	struct ListNode *end;
	/**
	 * @protected
	 * Current node. Useful for keeping track of
	 * where we are in the list.
	 */
	struct ListNode* current;
};

/**
 * Default constructor for the list.
 * 
 * @return     A new List with zero size.
 * @memberof   List
 */
struct List *List_create(void);

/**
 * Constructor for a simple list based on the elements passed as
 * argument.
 * 
 * @param[in] elements
 * Pointer to an array of elements.
 * @param[in] size
 * The size of the @p elements structure.
 *  
 * @return     A new List with nodes created for each one of the elements
 * specified.
 * @memberof   List
 */
struct List *List_create_from(void **elements, unsigned int size);

/**
 * Destructor.
 *
 * @memberof   List
 */
void List_destroy(struct List *list);

/**
 * Adds an arbitrary element to the end of the list.
 * No type safety.
 * 
 * @retval     1 Success.
 * @retval     -1 Memory error.
 * @retval     0 Null @p element input.
 * 
 * @memberof   List
 */
int List_add(struct List *list, void *const element);

/**
 * Deletes an element from the list.
 * Returns 0 if the element is not in the list.
 *
 * @retval     0 The element isn't in the list.
 * @memberof   List
 */
int List_delete(struct List *list, const void *const element);

/**
 * Returns true if the element is contained. False otherwise.
 * 
 * @return     Whether the element is contained in the list or not.
 * @memberof   List
 */
_Bool List_contains(struct List *list, const void *const element);

/**
 * Takes a random element of the list (doesn't delete it).
 * 
 * @attention  It's needed to use srand() before calling this function.
 * 
 * @return     A random element from the list.
 * @memberof   List
 */
void *List_take_random(const struct List *list);

/**
 * Gets element at the beginning of the list.
 * 
 * @return     First element of the list.
 * @memberof   List
 */
void *List_first(const struct List *const list);

/**
 * Gets element at the end of the list.
 *
 * @return     Last element of the list.
 * @memberof   List
 */
void *List_last(const struct List *const list);

/**
 * Pops the element at the beginning.
 * 
 * @return     First element of the list.
 * @memberof   List
 */
void *List_pop(struct List *list);

/**
 * Gets the size of the list.
 *
 * @return     Size of the list.
 * @memberof   List
 */
unsigned int List_size(const struct List *const list);

/**
 * Moves to the next element of the list.
 * The implementation includes a memory of where we are during each call
 * of this function, so that each call moves to the next element.
 * At the end, returns to the beginning, so that we can work on it as if it
 * were a circular list.
 *
 * @return		Current element being pointed to in the List.
 * @memberof	List
 */
void *List_iterate(struct List *const list);

/**
 * Gets the current element of the list without advancing it.
 *
 * @memberof	List
 */
void *List_current(const struct List *const list);

/**
 * Resets the iterator so that it points to the beginning.
 *
 * @memberof	List
 */
void List_reset_iterator(struct List *const list);

#endif
