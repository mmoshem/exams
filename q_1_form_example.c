#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>




typedef struct list {
	int data;
	struct list* next;
}List;



void addToLast(List** last,int number) {
	if (*last == NULL) {
		*last = (List*)calloc(1, sizeof(List));
		(*last)->data = number;
	}
	else {
		(*last)->next= (List*)calloc(1, sizeof(List));
		*last = (*last)->next;
		(*last)->data = number;
	}
}

List* createList(int* arr,int size) {
	List* head = NULL;
	addToLast(&head, arr[0]);
	List* last = head;
	for (int i = 1; i < size; i++) {
		addToLast(&last, arr[i]);

	}
	return head;
}

print(List* head) {
	while (head != NULL) {
		printf("%d->", head->data);
		head = head->next;
	}
	puts("");
}





/// ////////////////////////////////////
int numberinList(List* head) {
	int num = 0; 
	while (head != NULL) {
		num += head->data;
		num *= 10;
		head = head->next;
	}
	//printf("the number is %d", num / 10);
	return num / 10;
}

int invertnumber(int number) {
	int num = 0;
	
	while (number != 0) {
		num += (number % 10);
		num *= 10;
		number /= 10;
	}
	return num / 10;
}

void list_add_num(List** head, int num) {
	List* temp = *head;
	int Listnumber = numberinList(*head);
	int newnumber = Listnumber + num;
	printf("before: %d\n", newnumber);
	newnumber = invertnumber(newnumber);
	printf("after: %d", newnumber);
	while (newnumber != 0) {
		if (temp->next != NULL) {
			temp->data = newnumber % 10;
			temp = temp->next;
		
		}
		else {
			temp->data = newnumber % 10;
			if(newnumber/10 !=0)
				temp->next = (List*)calloc(1, sizeof(List));

			temp = temp->next;

		}
		//print(*head);
		newnumber /= 10;
	}

}

/// /////////////////////////////////////////////////


int main() {
	int arr[] = { 9,9,9,4};

	List* head = (List*)calloc(1, sizeof(List));
	head->data = arr[0];
	List* curr = head;
	for(int i = 1; i < sizeof(arr) / sizeof(int); i++) {
		curr->next= (List*)calloc(1, sizeof(List));
		curr = curr->next;
		curr->data = arr[i];
	}


	//List* head = createList(arr, sizeof(arr) / sizeof(int));
	print(head);
	list_add_num(&head, 118);
	puts("");
	print(head);

}