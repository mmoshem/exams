#include<stdio.h>
#include<stdlib.h>

#define COLS 8
#define ROWS 4

typedef struct item {
	int data;
	int count;
} Item;



Item** function(int mat[][COLS], int n,int m,int** size) {
	int i, j, k,times;
	Item** dinmat = (Item**)calloc(n, sizeof(Item*));
	*size = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		k = 1;
		for (j = 1; j < m; j++) {
			if (mat[i][j] != mat[i][j - 1]) {
				k++;
			}
			
		}
		(*size)[i] = k;
		dinmat[i] = (Item*)calloc(k, sizeof(Item));
		
	}
	for (i = 0; i < n; i++) {
		times = 1;
		for (j = 1,k=0; j <= m; j++) {
			
			if (mat[i][j] != mat[i][j - 1]) {
				dinmat[i][k].count = times;
				dinmat[i][k++].data= mat[i][j - 1];
				times = 1;
			}
			else {
				times++;
			}
		}
	}
	return dinmat;
}

void printmat(Item** mat,int* size) {
	for (int i = 0; i < ROWS; i++) {
		printf("size : %d    ", size[i]);
		for (int j = 0; j < size[i]; j++) {
			printf("{%d,%d},", mat[i][j].data,mat[i][j].count);
		}
		puts("");
	}

}

int main() {
	int* size = NULL;
	int arr[ROWS][COLS] = {
		{2 , 3 , 3 , 6 , 6 , 6 , 6 , 9},
		{0 , 0 , 0 , 0 , 1 , 1 , 7 , 7},
		{5 , 5 , 5 , 5 , 5 , 5 , 5 , 5},
		{3 , 3 , 3 , 4 , 4 , 4 , 4 , 4}
	};

	Item** mat = function(arr, ROWS, COLS, &size);
	printmat(mat, size);

	return 0;
}