#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int fun(char* str, int* smallLetters, int* bigLetters) {
	int len, i, mid;
	*smallLetters = *bigLetters = 0;
	len = strlen(str);
	mid = len / 2;
	if (len % 2 == 0)
	{
		for (i = 0; i < mid; i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				(*smallLetters)++;
		}
		for (i = mid; i < len; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z')
				(*bigLetters)++;
		}
		return 0;
	}
	else {
		for (i = 0; i < mid; i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				(*smallLetters)++;
		}
		for (i = mid + 1; i < len - 1; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z')
				(*bigLetters)++;

		}
		if (*(str + mid) >= '0' && str[mid] <= '9')
			return 1;
		return -1;
	}

}



int main() {

	//char* str = "t&u5Y%sa3k$R";
	char* str = "t&u5Y%4sa3kR$";

		



	int small=0, big=0;

	printf("return :%d\nsmall:%d\nbig:%d ", fun(str, &small, &big),small,big);

	return 0;
}