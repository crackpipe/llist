/**
 * singly linked list
 * written by eight
 *
 * todo:
 * - sorting
**/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct List* createList() {
	struct List* l = malloc(sizeof(struct List));

	l->length = 0;
	l->head = NULL;

	return l;
}

void pushToList(void* data, struct List* l) {
	struct Node* n = malloc(sizeof(struct Node));

	n->data = data;
	n->next = NULL;

	if(l->head == NULL) {
		l->head = n;
	} else {
		struct Node* i = l->head;

		while(i->next != NULL) {
			i = i->next;
		}
		
		i->next = n;
	}

	l->length++;
}

void addAfterElem(int key, void* data, struct List* l) {
	if(key <= l->length - 1 && key > -1) {
		struct Node* n = malloc(sizeof(struct Node));

		n->data = data;

		struct Node* i = l->head;
		int x = 0;

		while(x != key && i->next != NULL) {
			i = i->next;
			x++;
		}

		struct Node* z = i->next;
		n->next = z;
		i->next = n;
		
		l->length++;
	}
}

void popFromList(struct List* l) {
	if(l->head != NULL) {
		if(l->head->next == NULL) {
			free(l->head);
			l->head = NULL;

			l->length--;
		} else {
			struct Node* i = l->head;
			
			while(i->next->next != NULL) {
				i = i->next;
			}

			free(i->next);
			i->next = NULL;

			l->length--;
		}
	}
}

void popHead(struct List* l) {
	if(l->head != NULL) {
		struct Node* n = l->head->next;
		free(l->head);
		l->head = n;

		l->length--;
	}	
}

void remFromList(int key, struct List* l) {
	if(key <= l->length - 1 && key > -1) {
		if(key == 0) {
			popHead(l);
		} else if(key == l->length) {
			popFromList(l);
		} else {	
			struct Node* i = l->head;
			int x = 0;

			while(x != key - 1 && i->next->next != NULL) {
				i = i->next;
				x++;
			}

			struct Node* z = i->next->next;

			free(i->next);
			i->next = z;

			l->length--;
		}
	}
}

void* getElem(int key, struct List* l) {
	if(key > l->length - 1 || key < -1)
		return NULL;

	struct Node* i = l->head;
	int n = 0;

	while(i->next != NULL) {
		if(n == key) {
			return i->data;
		} else {
			i = i->next;
			n += 1;
		}
	}

	return i->data;
}

void freeList(struct List* l) {
	free(l);	
}

void testList(struct List* l) {
	for(int i = 0; i <= l->length - 1; i++)
		printf("item %d - %s\n", i, (char*)getElem(i, l));
}

int main() {
	struct List* list = createList();
	printf("create list (len: %d)\n", list->length);

	pushToList("hello", list);
	pushToList("world", list);
	pushToList("last one", list);

	printf("push to list (len: %d)\n", list->length);
	
	printf("\n-+ test list +-\n");
	testList(list);
	printf("\n");

	freeList(list);
	printf("free list\n");

	return 0;
}
