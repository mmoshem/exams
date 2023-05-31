#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
	char* string; 
	struct item* next;
} Item;

Item* createNode(char* str) {
	
	int i=0;
	int firstWordSize=0;
	Item* node = (Item*)malloc(sizeof(Item) * 1);
	node->next = NULL;

	//"abc dasfdsg asdgg  dasf"
	while(str[i]!= ' ') {
		firstWordSize++;
		i++;
	}

	node->string = (char*)malloc(sizeof(char) * (firstWordSize + 1));
	     
	for (i = 0; i < firstWordSize; i++) {
	node->string[i] = str[i];
	}
	node->string[i] = '\0';



	return node;

}

Item* textToList(char* filename) {

	char word[99]={0};
	Item* head = NULL;
	Item* tail = NULL;

	FILE* fp = fopen(filename, "r");
	if (!fp) { return NULL; }
	

	while (fgets(word, sizeof(word), fp) != NULL) {
		if (head == NULL) {
			tail = head = createNode(word);
		}
		else{
			tail->next = createNode(word);
			tail = tail->next;
		}
	}
	

	fclose(fp);
	return head;
}

int main() {
	
	int i;
	char* fileName = "C:\\temp\\text.txt";

	Item* list = textToList(fileName);
    
	while (list != NULL) {
		printf("[%s]->", list->string); 
		list = list->next;
	}
	puts("NULL");

	return 0;
}
