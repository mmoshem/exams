#include <stdio.h>
#include <stdio.h>
#include <string.h>


//removes any close duplicates ex: 'aaa' -> 'a'   ,   '   '-> ' '   ,   'aa  ab  ' -> 'a ab '
int removeCloseDupChars(char* str, char* str1) {
	int i=1,j=1,assholes=0, assholes1 = 0;
	int len = strlen(str);
	int len1 = strlen(str1);
	while (str[i] != '\0') {
		if (str[i]==str[i - 1]) {
			assholes++;
		}
		else {
			str[i - assholes] = str[i];
		}
		i++;
	}
	str[i - assholes] = '\0';

	while (str1[j] != '\0') {
		if (str1[j] ==  str1[j - 1]) {

			assholes1++;
		}
		else {
			str1[j - assholes1] = str1[j];
		}
		j++;
	}
	str1[j - assholes1] = '\0';


	return (strcmp(str1, str) == 0 ? 1 : 0);
}



int main() {

	char str[] = "    stam BBdika   meSHUbaahaattttt  ";
    char str1[] = " stammmm   BBdika meSHHHUbaaaaaahaattt ";
	printf("%d",removeCloseDupChars(str, str1));
	return 0;
}