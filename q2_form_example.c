#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	char address[30];
	int rooms;
	int price;
} Apartment;



Apartment* appropriateAppartment(char* fileName,int roomNum,int price,int *count) {
	*count = 0;
	int i;
	FILE* fp = fopen(fileName, "rb");
	if (!fp) { return NULL; }
	Apartment arr;
	while (fread(&arr, sizeof(Apartment), 1, fp)==1) {
		
		if (arr.rooms == roomNum) {
			if(arr.price<=price)
			{
				(*count)++;
			}
		}
	}

	if (!(*count)) {
		fclose(fp);
		return NULL;
	}
	
	rewind(fp);//fseek(fp, 0, SEEK_SET);
	

	Apartment* arrDin = (Apartment*)malloc(sizeof(Apartment) * (*count));
	i = *count;
	
	while (i>0&&fread(&arr, sizeof(Apartment), 1, fp) == 1) {
		if(arr.rooms == roomNum && arr.price <= price){
			strcpy(arrDin[i - 1].address , arr.address);
			arrDin[i - 1].price = arr.price;
			arrDin[i - 1].rooms = arr.rooms;
			i--;	
		}
	}
	fclose(fp);
	return arrDin;

}
void printApartments(Apartment* arr, int count) {
	printf("Apartments:\n");
	for (int i = 0; i < count; i++) {
		printf("Address: %s\n", arr[i].address);
		printf("Rooms: %d\n", arr[i].rooms);
		printf("Price: %d\n\n", arr[i].price);
	}
}


int main() {
	int count;
	Apartment apartmaent[] = {
	{"Begin 7 ", 3, 700000},
	{"Reznik 4 ", 4, 1000000},
	{"bbb 4", 5, 1700000},
	{"ccccc 5", 3, 2016000},
	{"dddddd 77", 3, 900000}
	};

	FILE* fp = fopen("c:\\temp\\text.bin","wb");
	if (!fp) { exit(1); }
	fwrite(apartmaent, sizeof(Apartment), sizeof(apartmaent) / sizeof(Apartment), fp);
	fclose(fp);
	
	Apartment* arr = appropriateAppartment("c:\\temp\\text.bin", 3, 900000, &count);
	printf("%d", count);
	printApartments(arr, count);
	free(arr);
	return 0;
	
}