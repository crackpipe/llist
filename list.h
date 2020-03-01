/*
 * singly linked list
 * written by eight
*/

#ifndef LIST_H
#define LIST_H

struct Node {
	void* data;
	struct Node* next;
};

struct List {
	int length;
	struct Node* head;
};

struct List* createList(); // alloc (DONE)
void freeList(struct List*); // free (DONE)

void* getElem(int, struct List*); // get element by key (zero-based) (DONE)

void pushToList(void*, struct List*); // push to end of list (DONE)
void addAfterElem(int, void*, struct List*); // push after specific slot in list (DONE)

void popFromList(struct List*); // pop from end of list (DONE)
void remFromList(int, struct List*); // remove from specific slot in list (DONE)

#endif
