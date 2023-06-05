#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


char* inverseString(char* str) {
	int len = strlen(str);
	int i = len - 1, j = 0, counter=1;
	char* temp = (char*)calloc(len, sizeof(char));
	if (!temp)return NULL;
	//strcpy(temp, str);
//	abc def'\0'
//  0123456 7
//      i
	while (i >= 0) {
		while (str[i] != ' ' && i > 0) {
			counter++;
			i--;
		}
		if (i == 0) {
			
			memcpy(temp + j, str + i, counter);
			//memcpy_s(temp + j, counter, str + i, counter);
			temp[len] = '\0';
		}
		else {
			memcpy_s(temp + j, counter, str + i + 1, counter);
			j += counter;
		}
		counter = 1;
		while (str[--i] == ' ') {
			i--;
		}

	}
	return temp; 
}


int main() {

	char str[] = "abc def";
	char *str1 = inverseString(str);
	printf("%s", str1);
	return 0;
}