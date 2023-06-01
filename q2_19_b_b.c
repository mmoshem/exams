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

int ifexists(Item* list, char* str) {

	while (list!= NULL) {
		if (strcmp(list->string, str) == 0) {
			return 1;
		}
		list = list->next;
	}
	return 0;
	
}


void addToListFromArrLexi(Item **list, char* arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		Item* pos = (*list)->next;
		Item* prev = *list;

		if (ifexists(*list, arr[i])) {
			continue;
		}
		while (pos != NULL) {
			
			if (strcmp(arr[i],pos->string) > 0) {
				prev = pos;
				pos = pos->next;
			}
			else {

				Item* temp = createNode(arr[i]);
				if (prev == *list) {
					temp->next = prev;
					*list = temp;
					
				}
				else {
					temp->next = pos;
					prev->next = temp;
					
				}
			}
			if (pos==NULL) {
				Item* temp = createNode(arr[i]);
				temp->next = pos;
				prev->next = temp;
				break;
			}

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