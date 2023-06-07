#include <stdio.h>
#include <stdlib.h>

#define COLS 5
#define ROWS 5




int isPerfect(int num) {
	int i;
	int sum = 0;
	for (i = 1; i * i <= num; i++) {
		if (!(num % i)) {
			sum += i;
			if (i != 1 && i != num / i) {
				sum += num / i;
			}
			
		}
	}

	if (sum == num) {
		return 1;
	}
	return 0;
}


int findAndCreate(int mat[][COLS], int cols, int rows,int **arr) {
	int i, j,counter=0,k=0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (isPerfect(mat[i][j])) counter++;
		}
	}

	if (!counter) { *arr = NULL; return 0; }

	*arr = (int*)malloc(sizeof(int) * counter);
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (isPerfect(mat[i][j])) {
				(*arr)[k++] = mat[i][j];
			};
		}
	}
	return counter;
 }



printArr(int* arr,int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		printf("%d, ", arr[i]);
	}
	
}


int main() {

	int matrix[ROWS][COLS] = {
		   { 6,2 ,25 ,10 , 129},
		   { 34, 230, 345, 12, 65 },
		   { 235, 8128, 45, 42, 1234 },
		   { 768, 3455, 496,340, 456 },
		   { 28, 3456, 23543, 3453,2357 }
	};

	int* arr=NULL;
	int size = findAndCreate(matrix, COLS, ROWS, &arr);
	printArr(arr, size);
	return 0;
}