#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
	int data;
	struct item* next;
} Item;

void printList(Item* l) {
	puts("the list is:");

	while (l) {
		printf("[%d]->", l->data);
		l = l->next;
	}
	puts("NULL");
}

Item* createNode(int dat) {

	Item* node = (Item*)malloc(sizeof(Item));
	node->data = dat;
	node->next = NULL;
	return node;
}
/// <summary>
/// this is the answer 
/// </summary>
/// <param name="l"></param>
/// <returns></returns>
Item* cutCircalList(Item* l) {
	while (l->data < l->next->data) {
		l = l->next;
	}
	Item* head = l->next;
	l->next = NULL;
	return head;
}



int main() {

	Item* list = (Item*)malloc(sizeof(Item));
	Item* head = list;
	list->data = 1;
	list->next = createNode(2);
	list = list->next;
	list->next = createNode(4);
	list = list->next;
	list->next = createNode(7);
	list->next->next = head;

	for (int i = 0; i < 8; i++) {
		printf("[%d]->", head->data);
		head = head->next;
	}
	puts("");
	Item* node = cutCircalList(head->next->next->next);
	printList(node);


	return 0;
}