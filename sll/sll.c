#include <stdio.h>
#include <stdlib.h>

struct node {
	char bfr[256];
	struct node* next;
};

struct node add(char*, node*);

int main(int argc, char** argv) {

	struct node* head;
	struct node* tail;
	head = (struct node*) malloc(sizeof(struct node));
	tail = head;

	head->next = NULL;
	tail->next = NULL;

	head->bfr = "test1";

	for (int i = 0; i < 10; i++) {
		char str[256] = "test" + i;
		tail = add(str, tail);
	}

	struct node* current;
	current = head;
	while (current->next != NULL) {
		printf("%s\n", current->bfr);
	}

	return 0;
}

struct node add(char* str, node* tail) {
	
	struct node* new;
	new = (struct node*) malloc(sizeof(struct node));
	
	new->bfr = str;
	new->next = NULL;

	tail = new;
}
