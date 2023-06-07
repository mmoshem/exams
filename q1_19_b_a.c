#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


void f(char* filename, char** str, int size) {

	FILE* fp = NULL;
	fopen_s(&fp, filename, "w");
	if (!fp)printf("wtf?");
	int i = 1;
	while (i < size) {

		fprintf(fp, "%d %s\n", i,str[i]+2);
		i++;
	}
	fprintf(fp, "%d %s\n",1, str[1]+2);


	fclose(fp);



}

int main()
{
	char* fileName = "C:\\temp\\q1_19_b_a.txt";
	char* strarr[] = { {"1 bill jon,28"}, {"2 ron smith,234"}, {"3 arthun sf,1"}, {"4 sduarde stone,123"} };
	f(fileName, strarr, 4);
	return 0;
}