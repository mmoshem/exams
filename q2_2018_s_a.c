#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef struct data_item {
	int data;
	struct data_item* next;
} DataItem;

typedef struct ptr_item {
	DataItem* ptr;
	struct ptr_item* next;
} PtrItem;

void printsiplelist(DataItem* head) {
	puts("\nprinting simple list:");
	while (head != NULL) {
		printf("[%d]->", head->data);
		head = head->next;
	}
	puts("NULL");
}


DataItem* makeOneLongList(PtrItem* l) {

	DataItem* head = l->ptr;
	DataItem* curr = head;
	PtrItem* a = l;
	PtrItem* b = NULL;
	l = l->next;
	while (l != NULL) {

		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = l->ptr;
		l = l->next;

	}
	while (a != NULL) {
		b = a;
		a = a->next;
		free(b);
	}


	return head;

}


int main() {
	PtrItem* head = NULL;
	DataItem* curr = NULL;
	PtrItem* l = (PtrItem*)malloc(sizeof(PtrItem) * 1);
	head = l;
	curr = (l->ptr) = (DataItem*)malloc(sizeof(DataItem) * 1);
	curr->data = 3;
	curr->next = (DataItem*)malloc(sizeof(DataItem) * 1);
	curr = curr->next;
	curr->data = 2;
	curr->next = (DataItem*)malloc(sizeof(DataItem) * 1);
	curr = curr->next;
	curr->data = 5;
	curr->next = NULL;
	l->next = (PtrItem*)malloc(sizeof(PtrItem) * 1);
	l = l->next;
	curr = (l->ptr) = (DataItem*)malloc(sizeof(DataItem) * 1);
	curr->data = 6;
	curr->next = NULL;
	l->next = (PtrItem*)malloc(sizeof(PtrItem) * 1);
	l = l->next;
	l->ptr = NULL;
	curr = (l->ptr) = (DataItem*)malloc(sizeof(DataItem) * 1);
	curr->data = 0;
	curr->next = (DataItem*)malloc(sizeof(DataItem) * 1);
	curr = curr->next;
	curr->data = 7;
	curr->next = NULL;
	l->next = NULL;

	DataItem* newhead = makeOneLongList(head);
	printsiplelist(newhead);// printing the listof lists



	return 0;
}