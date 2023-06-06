#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* duplicateString(char* base, char* mid, int times) {
	// abc'\0' 
	// de'\0'
	int len= strlen(base)*times+ strlen(mid) * (times - 1);
	//int lenMid = strlen(mid)* (times-1);
	char* str = (char*)calloc(len + 1, sizeof(char));
	int i=0;

	//strcpy(str, base);
	while (i < times - 1) {
		strcat(str, base);
		strcat(str, mid);
		i++;
	}
	strcat(str, base);

	return str;
}


int main() {

	char* str = "hi";
	char* str1 = " bye ";
	char* str2 = duplicateString(str, str1, 5);
	printf("%s",str2);
	return 0;
}