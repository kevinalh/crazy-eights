#include <stdlib.h>

#include "simplelist.h"

struct ListNode {
	void *element;
	struct ListNode *next;
};

struct List {
	struct ListNode *begin;
	struct ListNode *end;
};

struct ListNode *List_find_next(struct List *list, void *element);
struct ListNode *List_find(struct List *list, void *element);

void List_init(struct List *list) {
	list->begin = NULL;
	list->end = NULL;
}

int List_add(struct List *list, void *element) {
	struct ListNode *node = malloc(sizeof(struct ListNode));
	if(!node) return -1;
	node->element = element;
	node->next = NULL;
	if(list->end != NULL) {
		list->end->next = node;
	}
	if(list->begin == NULL) {
		list->begin = node;
	}
	list->end = node;
	return 1;
}

int List_delete(struct List *list, void *element) {
	struct ListNode *node = list->begin;
	if(node->element == element) {
		// It's the first element.
		list->begin = node->next;
		free(node);
	}
	else {
		// Somewhere in the middle or the end.
		node = List_find_next(element, list);
		if(node == NULL) return 0;
		if(node->next == list->end) list->end = node;
		node->next = node->next->next;
		free(node->next);
	}
	return 1;
}

_Bool List_contains(struct List *list, void *element) {
	return List_find(list, element) != NULL;
}

/**
* Returns NULL if the element isn't found, or is the first.
* Otherwise, returns a node such that node->next is the value
* being searched for.
*/
struct ListNode *List_find_next(struct List *list, void *element) {
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
struct ListNode *List_find(struct List *list, void *element) {
	struct ListNode *node;
	for(node = list->begin; node != NULL; node = node->next) {
		if(node->element == element) break;
	}
	return node;
}