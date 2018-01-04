#include <stdlib.h>

#include "stack.h"
#include "simplelist.h"

struct Stack {
	/**
	 * @private
	 */
	struct List *list;
};

struct Stack *Stack_create(void) {
	struct Stack *stack = malloc(sizeof(struct Stack));
	stack->list = List_create();
	return stack;
}

void Stack_destroy(struct Stack *stack) {
	if(stack == NULL) return;
	List_destroy(stack->list);
	free(stack);
}

int Stack_push(struct Stack *stack, void *const element) {
	return List_add(stack->list, element);
}

void *Stack_pop(struct Stack *stack) {
	return List_pop(stack->list);
}

void *Stack_top(const struct Stack *const stack) {
	return List_first(stack->list);
}

unsigned int Stack_size(const struct Stack *const stack) {
	return List_size(stack->list);
}