#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char bfr[256];
	struct node* next;
};

struct node* add(char*);

int main(int argc, char** argv) {
	
	/* Setting up the head and tail */
	struct node* head = add("test");
	struct node* tail = head;

	/* Adding nodes */
	for (int i = 0; i < 10; i++) {
		char str[256];
		sprintf(str, "test%d", i);
		struct node* newNode = add(str);
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
struct node* add(char* str) {
	
	struct node* n;
	n = (struct node*) malloc(sizeof(struct node));
	
	strncpy(n->bfr, str, sizeof(n->bfr));
	n->next = NULL;

	return n;
}
