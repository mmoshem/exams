#define _CRT_SECTURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>



typedef struct{
	int	colIndex, rowIndex, height, width;
}frame;

int f(int** mat, int cols, int rows, int N, frame f) {
	int i, j, k;
	int* arrCounter = (int*)calloc(N, sizeof(int));

	int rr = f.rowIndex + f.height;
	int cc = f.colIndex+ f.width;
	if (f.rowIndex >= 0 && f.colIndex >= 0 &&rr < rows && cc < cols) {
		k = 1;
	}

	// this is my code but i found out that the answer to the quawion is a pain in the ass so i studied the answer and coppied it below 
	// if N has exactly the size of the frame
	//for (i = f.rowIndex; i < rr; i++) {
	//	for (j = f.colIndex; j < cc; j++) {
	//		if (k = ++arrCounter[mat[i][j]] != 2) {}
	//		else
	//			return 0;
	//	}
	//	return 1;
	//}

	//this is the below part 

	for (i = f.rowIndex; i < rr; i = i + f.rowIndex - 1) //only first and last rows 
	{
		for (j = f.colIndex; j < cc; j++)
		{
			if (mat[i][j] >= 1 && mat[i][j] <= N)
			{
				(arrCounter[mat[i][j]])++;
			}
		}
	}
	for (j = f.colIndex; j < cc; j = j + f.colIndex - 1)
	{
		for (i = f.rowIndex + 1; i < rr - 1; i++)
		{
			if (mat[i][j] >= 1 && mat[i][j] <= N)
			{
				(arrCounter[mat[i][j]])++;
			}
		}
	}

	for (i = 1; i <= N; i++) {
		if (arrCounter[i] != 1) {
			k = 0; break;
		}
	}
	free(arrCounter);
	arrCounter = NULL;
	return k;
}

int main() {



}