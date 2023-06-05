#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* inverseString(char* str) {
	int len = strlen(str);
	int i=len-1,j=0;
	char* temp = (char*)calloc(len, sizeof(char));
	memcpy(temp, str, len);
	for (i,j; i >= 0; j++, i--) {
		str[j] = temp[i];
	}
	return str; 
}


int main() {

	char str[] = "hello world";
	char *str1 = inverseString(str);
	printf("%s", str1);
	return 0;
}