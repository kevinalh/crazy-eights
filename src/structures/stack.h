#ifndef STACK_H_
#define STACK_H_

struct Stack;

/**
* Initializes stack.
*/
struct Stack *Stack_create(void);

/**
* Destructor
*/
void Stack_destroy(struct Stack *stack);

/**
* Pushes one element at the top of the stack.
*/
int Stack_push(struct Stack *stack, void *element);

/**
* Pops the element on top of the stack.
*/
void *Stack_pop(struct Stack *stack);

/**
* Returns the element on top without deleting it.
*/
void *Stack_top(const struct Stack *const stack);

/**
* How many elements this stack has.
*/
unsigned int Stack_size(const struct Stack *const stack);

#endif