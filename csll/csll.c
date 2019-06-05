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
char* removeLast(void);
char* removeElement(char*);
void printList(void);

struct node* head;

int main(int argc, char** argv) {
	
	/* Setting up the head */
	head = createNode("test");

	/* Adding nodes */ for (int i = 0; i < 10; i++) {
		char str[256];
		sprintf(str, "test%d", i);
		addToRear(str);
	}

	char* retbfr = removeLast();
	removeLast();
	removeLast();
	printf("%s\n", removeElement("test3"));
	printf("%s\n", retbfr);
	removeLast();
	removeLast();
	removeLast();
	removeLast();
	removeLast();
	removeLast();
	removeLast();
	removeLast();
	removeLast();
	removeLast();
	
	printList();

	return 0;
}

/**
 * Creates a new node pointer with the specified string parameter,  and returns a pointer to it.
 */
struct node* createNode(char* str) {
	
	struct node* n;
	n = (struct node*) malloc(sizeof(struct node));
	
	n->bfr = strdup(str);
	n->next = n;

	return n;
}

/**
 * Creates a new node and adds it at the back of the circular linked list.
 */
void addToRear(char* str) {
	
	struct node* newHead;
	newHead = (struct node*) malloc(sizeof(struct node));
	newHead->bfr = head->bfr;
	newHead->next = head->next;

	head->bfr = strndup(str, strlen(str));
	head->next = newHead;

	head = newHead;
}

/**
 * Removes the last element from the CSLL
 */
char* removeLast() {
	
	if (head == NULL) {
		printf("No list!\n");
		return NULL;
	}

	if (head->next == head) {
//		bfr = strndup(head->bfr, strlen(head->bfr));
		char* bfr = head->bfr;
//		free(head->bfr);
		free(head);
		head = NULL;
		return bfr;
	}

	struct node* current;
	current = head;
	while (current->next->next != head) {
		current = current->next;
	}
	
	char* bfr = current->bfr;
//	bfr = strndup(current->bfr, strlen(current->bfr));	// if I malloc this here to return it... how do I free it?
//	free(current->bfr); // valgrind says this is an invalid free
	free(current->next);
	current->next = head;
	return bfr;
}

/**
 * Removes the node containing the given element and returns the element. Returns a char* 
 * of -1 if element is not found.
 */
char* removeElement(char* element) {
	
	if (head == NULL) {
		printf("No list!\n");
		return NULL;
	}
	
	struct node* current;
	current = head;
	while (strncmp(current->next->bfr, element, strlen(element)) < 0 && current-> next != head){
		current = current->next;
	}

	if (strncmp(current->next->bfr, element, strlen(element)) == 0) {
		struct node* newNext = current->next->next;
		free(current->next->bfr);
		free(current->next);
		current->next = newNext;
		return element;
	} else { 
		return NULL;
	}
}

void printList() {

	/* Traversing the list */
	if (head != NULL) {
		
		struct node* current;
		current = head;
		while (current->next != head) {
			printf("%s\n", current->bfr);
			current = current->next;
		}
	} else {
		printf("No list!!\n");
	}
}
