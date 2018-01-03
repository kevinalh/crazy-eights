#include <stdlib.h>
#include <assert.h>

#include "simplelist.h"

struct ListNode {
	void *element;
	struct ListNode *next;
};

struct List {
	unsigned int size;
	struct ListNode *begin;
	struct ListNode *end;
};

struct ListNode *List_find_next(struct List *list, const void *const element);
struct ListNode *List_find(struct List *list, const void *const element);
unsigned int List_random_index(const struct List *const list);
struct ListNode *List_get_by_index(const struct List *const list, const unsigned int index);

struct List *List_create(void) {
	struct List *list = malloc(sizeof(struct List));
	if(list != NULL) {
		list->begin = NULL;
		list->end = NULL;
		list->size = 0;
	}
	return list;
}

struct List *List_create_from(void **elements, unsigned int size) {
	struct List *list = List_create();
	if(list == NULL) return NULL;
	for(size_t i = 0; i < size; ++i) {
		if(List_add(list, elements[i]) != 1) return NULL;
	}
	return list;
}

void List_destroy(struct List *list) {
	if(list == NULL) return;
	while(list->size != 0) List_pop(list);
	assert(list->begin == NULL && list->end == NULL);
	free(list);
}

int List_add(struct List *list, void *const element) {
	struct ListNode *node = malloc(sizeof(struct ListNode));
	if(!node) return -1;
	if(element == NULL) return 0;
	node->element = element;
	node->next = NULL;
	if(list->end != NULL) {
		list->end->next = node;
	}
	if(list->begin == NULL) {
		list->begin = node;
	}
	list->end = node;
	list->size++;
	return 1;
}

int List_delete(struct List *list, const void *const element) {
	struct ListNode *node = list->begin;
	if(node->element == element) {
		// It's the first element.
		list->begin = node->next;
		free(node);
		if(list->begin == NULL) list->end = NULL;
	}
	else {
		// Somewhere in the middle or the end.
		node = List_find_next(list, element);
		// Not found
		if(node == NULL) return 0;
		// If it's at the end
		if(node->next == list->end) list->end = node;
		// Destroy the node
		struct ListNode *tmp = node->next;
		node->next = node->next->next;
		free(tmp);
	}
	list->size--;
	return 1;
}

_Bool List_contains(struct List *list, const void *const element) {
	return List_find(list, element) != NULL;
}

/**
* Returns NULL if the element isn't found, or is the first.
* Otherwise, returns a node such that node->next is the value
* being searched for.
*/
struct ListNode *List_find_next(struct List *list, const void *const element) {
	struct ListNode *node;
	struct ListNode *tmp = list->begin;
	if(tmp == NULL) return NULL;
	for(;;tmp = tmp->next) {
		node = tmp->next;
		if(node == NULL) return NULL;
		if(node->element == element) break;
	}
	return tmp;
}

/**
* Looks for the node. Returns NULL if not found.
*/
struct ListNode *List_find(struct List *list, const void *const element) {
	struct ListNode *node;
	for(node = list->begin; node != NULL; node = node->next) {
		if(node->element == element) break;
	}
	return node;
}

/**
* Naive implementation.
*/
unsigned int List_random_index(const struct List *const list) {
	return rand() % List_size(list);
}

/**
* Gets the node given its index in the list.
* Returns NULL if the node doesn't exist.
*/
struct ListNode *List_get_by_index(const struct List *const list, const unsigned int index) {
	struct ListNode *node = list->begin;
	for(unsigned int i = 0; i < index && node != NULL; ++i, node = node->next);
	return node;
}

void *List_take_random(const struct List *list) {
	unsigned int index = List_random_index(list);
	struct ListNode *node = List_get_by_index(list, index);
	// It should be impossible not to get to the node.
	assert(index < list->size);
	assert(node != NULL);
	void *element = node->element;
	return element;
}

void *List_first(const struct List *const list) {
	if(list->begin == NULL) return NULL;
	return list->begin->element;
}

void *List_last(const struct List *const list) {
	if(list->begin == NULL) return NULL;
	return list->end->element;
}

void *List_pop(struct List *list) {
	void *element = List_first(list);
	if(list->begin != NULL) {
		struct ListNode *tmp = list->begin;
		list->begin = list->begin->next;
		free(tmp);
		list->size--;
		if(list->begin == NULL) list->end = NULL;
		else if(list->begin->next == NULL) list->end = list->begin;
	}
	return element;
}

unsigned int List_size(const struct List *const list) {
	return list->size;
}