#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char* bfr;
	struct node* next;
};

struct node* createNode(char*);

struct node* head;

int main(int argc, char** argv) {
	
	/* Setting up the head and tail */
	head = createNode("test");
	head->next = head;
	struct node* tail = head;

	/* Adding nodes */
	for (int i = 0; i < 10; i++) {
		char str[256];
		sprintf(str, "test%d", i);
		struct node* newNode = createNode(str);
		tail->next = newNode;
		tail = newNode;
	}

	/* Traversing the list */
	struct node* current;
	current = head;
	while (current != NULL) {
		printf("%s\n", current->bfr);
		current = current->next;
	}

	return 0;
}

/**
 * Creates a new node pointer with the specified string parameter,  and returns a pointer to it.
 */
struct node* createNode(char* str) {
	
	struct node* n;
	n = (struct node*) malloc(sizeof(struct node));
	
	n->bfr = strdup(str);
	n->next = NULL;

	return n;
}

