#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A basic circular single linked list program that creates a head, then adds nodes
 * to the end of the list with an incrementing string. It then prints the string
 * contents of the nodes.
 * Author: Matt Arnold
 */

struct node {
	char* bfr;
	struct node* next;
};

struct node* createNode(char*);
void addToRear(char*);

struct node* head;

int main(int argc, char** argv) {
	
	/* Setting up the head */
	head = createNode("test");
	head->next = head;

	/* Adding nodes */ for (int i = 0; i < 10; i++) {
		char str[256];
		sprintf(str, "tesst%d", i);
		addToRear(str);
	}
	
	/* Traversing the list */
	struct node* current;
	current = head;
	while (current->next != head) {
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

void addToRear(char* str) {
	
	struct node* newHead;
	newHead = (struct node*) malloc(sizeof(struct node));
	newHead->bfr = head->bfr;
	newHead->next = head->next;

	head->bfr = strdup(str);
	head->next = newHead;

	head = newHead;
}

