#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char bfr[256];
	struct node* next;
};

struct node* add(char*, struct node*);

int main(int argc, char** argv) {

	struct node* head;
	struct node* tail;
	head = (struct node*) malloc(sizeof(struct node));
	tail = (struct node*) malloc(sizeof(struct node));
	tail = head;

	head->next = NULL;
	tail->next = NULL;

	strncpy(head->bfr, "test1", sizeof(head->bfr));

	for (int i = 0; i < 10; i++) {
		char str[256];
		sprintf(str, "test%d", i);
		struct node* newNode = add(str, tail);
		tail->next = newNode;
		tail = newNode;
	}

	struct node* current;
	current = head;
	while (current->next != NULL) {
		printf("%s\n", current->bfr);
		current = current->next;
	}

	return 0;
}

struct node* add(char* str, struct node* tail) {
	
	struct node* n;
	n = (struct node*) malloc(sizeof(struct node));
	
	strncpy(n->bfr, str, sizeof(n->bfr));
	n->next = NULL;

	return n;
}
