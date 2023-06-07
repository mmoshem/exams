#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define COLS 5
#define ROWS 4

void dlilaMatToFile(int mat[][COLS],int rows,int cols,char* fileName) {
	int i, j;
	FILE* fp = fopen(fileName,"w");
	if (fp == NULL) { return; }

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (j == 0) {
				fprintf(fp, "%d", i);
				//fprintf(fp, "%d.", i); same a bit diff question  

			}
			
			if (mat[i][j] != 0) {
				fprintf(fp, " %d %d",  mat[i][j], j);

			}
				
			
			if(j==cols-1) {
				//fprintf(fp, "%s", "\n"); //same 
				fprintf(fp, "\n");  //same
				//fputc('\n', fp); //same
			}

		}
	}


	fclose(fp);
}



int main() {
	char* fileName = "C:\\temp\\text1.txt";
	int mat[ROWS][COLS] = {
		{0,0,4,0,7},
		{3,0,0,0,0},
		{9,1,0,6,0},
		{0,0,0,0,0}
	};
	dlilaMatToFile(mat,ROWS,COLS,fileName);
	return 0;
}
