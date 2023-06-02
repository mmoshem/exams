#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



typedef struct {
	char model[20];
	int price;
	int year;
} car;


typedef struct node {
	int price;
	int year;
	struct node* next;
}List;



List* createNode(int price,int year) {

	List* node = (List*)malloc(sizeof(List));
	node->price = price;
	node->year = year;
	node->next = NULL;
	return node;
}

List* func(char* fileName, char* desModel, int maxPrice, int minYear) {

	car thecar;
	FILE* fp=fopen(fileName, "rb");
	if (!fp ) { return NULL; }

	List* head = NULL;
	List *curr = NULL;
	while (fread(&thecar, sizeof(car), 1, fp)==1) {
		
		if (strcmp(thecar.model,desModel)==0) {
			if (thecar.price <= maxPrice) {
				if (thecar.year >= minYear) {
					if (head == NULL) {
						curr = head = createNode(thecar.price, thecar.year);
						
					}
					else {
						curr->next= createNode(thecar.price, thecar.year);
						curr = curr->next;
					}
				}
			}
		}
	}
	
	fclose(fp);
	return head;//
}

void print(List* head) {
	printf("%-7s,%-7s\n", "Price", "year");

	while (head)
	{
		printf("%-7d%-7d\n", head->price, head->year);
		head = head->next;
	}

}

int main() {
	char* path = "c:\\temp\\text.txt";

	
	FILE* file = fopen(path, "wb");
	if (file == NULL) {
		printf("Failed to open file for writing.\n");
		return;
	}

	car cars[] = {
		{"Model G", 40000, 2018},
		{"Model A", 25000, 2015},
		{"Model B", 30000, 2017},
		{"Model D", 45000, 2016},
		{"Model F", 35000, 2014},
		{"Model G", 99000, 2020},
		{"Model H", 60000, 2013},
		{"Model I", 40555, 2016},
		{"Model J", 70000, 2021},
		{"Model G", 50000, 2019}
	};
	
	size_t numCars = sizeof(cars) / sizeof(cars[0]);
	/*for (int i = 0; i < numCars; i++)
	{
		fwrite(&cars[i], sizeof(car), 1, file);
	}*/

	fwrite(cars, sizeof(car), numCars, file);
	fclose(file);

	List* head = func(path, "Model G", 50000, 2000);
	print(head);
}