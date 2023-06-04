#include <stdio.h>
#include <stdlib.h>


#define MSZ 8

int** compress(int m1[MSZ][MSZ], int cx, int cy) {

	int i = 0, j = 0,k=1,r=0,c=0,flag=1, rows = MSZ / cy, cols= MSZ / cx;

	int** mat = (int**)calloc(rows, sizeof(int*));
    for (i = 0; i < rows; i++) {
        mat[i] = (int*)calloc(cols, sizeof(int));
    }


    for (i = 0; i < MSZ; i +=cy) {
        for (j = 0; j < MSZ; j +=cx) {
            k = 1;
            for (r = i; r < i+cy; r++) {
                for (c = j; c < j+cx; c++) {
                    k *= m1[r][c];

                }
                
            }
            mat[i / cy][j / cx] = k;
        }


    }
  

    return mat;
	
}


void printMatrix(int** matrix) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int cx = 2, cy = 2;
    int matrix[MSZ][MSZ] = {
         {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Printing the matrix
    int** mat = compress(matrix, cx, cy);
    printMatrix(mat);

	return 0;
}
