#define _CRT_SECTURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


#define TYPE int 
























typedef struct list {

	TYPE data;

	struct list* next;

}List;


List* createList(TYPE num) {
	List* node = (List*)calloc(1,sizeof(List));
	node->data = num;
	node->next = NULL;
	return node;
}
 
void addToHead(List** l, TYPE num) {
	List* node = (List*)calloc(1, sizeof(List));
	node->data = num;
	node->next = *l;
	*l = node;

}


void printList(List* l) {
	puts("the list is :");
	while (l) {
		printf("[%d]->",l->data);
		l = l->next;
	}
	puts("NULL");
}



int isFibo(List* l) {

	List* curr = l->next;
	List* prev = l;
	while (curr->next != NULL) {
		if (curr->next->data != (prev->data + curr->data)) {
			return 0;
		}
		prev = curr;
		curr = curr->next;
	}
	return 1;
}


int main() {

	List* head = createList(63);
	addToHead(&head, 39);
	addToHead(&head, 24);
	addToHead(&head, 15);
	addToHead(&head, 9);
	addToHead(&head, 6);
	addToHead(&head, 3);
	printList(head);
	printf("the list is %s",(isFibo(head)==1)? "fibo" :"not fibo");

	return 0;
}