#include <stdio.h>
#include <stdlib.h>

typedef struct data_item {
	int data;
	struct data_item* next;
} DataItem;

typedef struct ptr_item {
	DataItem* ptr;
	struct ptr_item* next;
} PtrItem;


//printing the list of lists diffrent visuallity of printing 
//void print(PtrItem* head) {
//	DataItem* curr = NULL;
//	while (head != NULL) {
//		curr = head->ptr;
//		//printf("[]->");
//		while (curr != NULL) {
//			printf("[%d]->", curr->data);
//			curr = curr->next;
//		}
//		puts("NULL");
//		puts(" |");
//		puts(" V");
//		head = head->next;
//	}
//	puts("NULL");
//}


//printing the list of lists  
void print(PtrItem* head) {
	DataItem* curr = NULL;
	while (head != NULL) {
		curr = head->ptr;
		printf("[]->");
		while (curr != NULL) {
			printf("[%d]->", curr->data);
			curr = curr->next;
		}
		puts("NULL");

		head = head->next;
	}
		
}

//printing simple list
void printsiplelist(DataItem* head) {
	puts("\nprinting simple list:");
	while(head!=NULL){
		printf("[%d]->", head->data);
		head = head->next;
	}
	puts("NULL");
}



//////////////////////////////// from here is the answer

DataItem* createElement(int num) {
	DataItem* node = (DataItem*)malloc(sizeof(DataItem) * 1);
	node->data = num;
	node->next = NULL;
	return node;
}


//
DataItem* tutrnToSimpleList(PtrItem* l){
	DataItem* head = NULL;
	DataItem* newcurr= NULL;

	if (l == NULL) { return NULL; }


	DataItem* curr = NULL;
	while (l != NULL) {
		curr = l->ptr;
		while (curr != NULL) {
			if (head == NULL) {
				newcurr = head = createElement(curr->data);        
			}
			
			else{
				newcurr->next = createElement(curr->data);
				newcurr = newcurr->next;
			}
			curr = curr->next;
		
		}
		l = l->next;
	}
	newcurr->next = NULL;

	return head;
}
//this is the end of the answer;


//free simple list 
void freelst(DataItem* head) {
	DataItem* tmp = head;
	while (head != NULL) {
		head = head->next;
		free(tmp);
		tmp = head;
	}
}


//free list of lists
freeListOfLists(PtrItem* head) {
	DataItem* curr=head->ptr;
	DataItem* ptTemp = head;
	DataItem* dataTemp=curr;
	while (head != NULL) {
		while (curr != NULL) {
			curr = curr->next;
			free(dataTemp);
			dataTemp = curr;
		}
		head = head->next;
		free(ptTemp);
		ptTemp = head;
	}

}

int main() {
	PtrItem* head = NULL;
	DataItem* curr=NULL;
	PtrItem* l = (PtrItem*)malloc(sizeof(PtrItem) * 1);
	head = l;
	curr = (l->ptr) = (DataItem*)malloc(sizeof(DataItem)*1);
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
	l->next=NULL;

	print(head);// printing the listof lists

	DataItem* newhead = tutrnToSimpleList(head); //creating a simple list out of list of lists

	printsiplelist(newhead); //printing simple list

	freelst(newhead); // free simple list 
	freeListOfLists(head); // free list of lists
	
	
	return 0;
}