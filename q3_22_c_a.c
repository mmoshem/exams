#include <stdio.h>
#include <stdio.h>
#include <string.h>



int removeCloseDupChars(char* str, char* str1) {
	int i=1,j=1,dup=0, dup1 = 0;
	int len = strlen(str);
	int len1 = strlen(str1);
	while (str[i] != '\0') {
		if (str[i]==' ' && str[i - 1]==' ') {
			dup++;
		}
		else {
			str[i - dup] = str[i];
		}
		i++;
	}
	str[i - dup] = '\0';

	while (str1[j] != '\0') {
		if (str1[j] == ' ' && str1[j - 1] == ' ') {

			dup1++;
		}
		else {
			str1[j - dup1] = str1[j];
		}
		j++;
	}
	str1[j - dup1] = '\0';


	return (strcmp(str1, str) == 0 ? 1 : 0);
}



int main() {

	char str[] = "h  el  l o";
	char str1[] = "h el l  o";
	printf("%d",removeCloseDupChars(str, str1));
	return 0;
}