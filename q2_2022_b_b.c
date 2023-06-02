#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Pair {
    int i,j;
}Pair;



Pair* findAllfriendsofFriends(int* size, int** m, int sizeMat) {

    int i, j, k, count = 0;
    Pair* arr = (Pair*)malloc(sizeof(Pair) * ((N * N) / 2 - N));
    for (i = 0; i < sizeMat; i++)
        for (j = 0; j < i; j++)
            if (m[i][j] == 0)
                for (k = 0; k < sizeMat; k++)
                    if (m[i][k] == 1 && m[k][j] == 1)
                    {
                        arr[count].i = i;
                        arr[count].j = j;
                        count++;
                        break; //search for common friends of i and j has been terminated

                    }

}




int main()
{
    
    return 0;
}