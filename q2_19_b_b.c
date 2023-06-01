#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct item {
	char* string;
	struct item* next;
} Item;

void printList(Item* l) {
	while (l != NULL) {
		printf("%s, ", l->string);
		l = l->next;
	}
	printf("\n");
}

Item* createNode(char* str) {
	Item* node= (Item*)malloc(sizeof(Item));
	node->string = str;
	node->next = NULL;
	return node;
}

void addToListFromArrLexi(Item** list, char* arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		Item* pos= *list;
		if (strcmp(arr[i], (*list)->string) < 0) {
			Item* temp = createNode(arr[i]);
			temp->next = *list;
			*list = temp;
		}
		if (strcmp(pos->string, arr[i]) == 0) {
			pos = pos->next;
		}
		if (strcmp( arr[i], pos->string) > 0) {
			Item* temp = createNode(arr[i]);
			temp->next = pos->next;
			pos->next = temp;
		}
	}


}

int main() {

	char* arr[] = { "Mike","Avi","Irit","Arthur" };
	Item* head = (Item*)malloc(sizeof(Item));
	Item* l = head;
	l->string = "Avi";
	l->next = (Item*)malloc(sizeof(Item));
	l = l->next;
	l->string = "Irit";
	l->next = (Item*)malloc(sizeof(Item));
	l = l->next;
	l->string = "Moshe";
	l->next = NULL;
	puts("before");
	printList(head);
	addToListFromArrLexi(&head, arr, sizeof(arr)/sizeof(arr[0]));
	puts("after");

	printList(head);

	return 0;
}