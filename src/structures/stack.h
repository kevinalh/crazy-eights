#ifndef STACK_H_
#define STACK_H_

/**
 * Basic stack data structure.
 * 
 * @struct Stack
 */
struct Stack;

/**
 * Constructs stack.
 *
 * @return     New stack object.
 * @memberof   Stack
 */
struct Stack *Stack_create(void);

/**
 * Destructor of the stack.
 *
 * @memberof   Stack
 */
void Stack_destroy(struct Stack *stack);

/**
 * Pushes one element at the top of the stack.
 *
 * @memberof   Stack
 */
int Stack_push(struct Stack *stack, void *element);

/**
 * Pops the element on top of the stack.
 *
 * @return     Element on top of the stack.
 * @memberof   Stack
 */
void *Stack_pop(struct Stack *stack);

/**
 * Returns the element on top without deleting it.
 *
 * @return     Element on top of the stack.
 * @memberof   Stack
 */
void *Stack_top(const struct Stack *const stack);

/**
 * How many elements this stack has.
 *
 * @return     Size of the stack.
 * @memberof   Stack
 */
unsigned int Stack_size(const struct Stack *const stack);

#endif