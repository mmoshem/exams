#include <stdio.h>
#include <stdlib.h>

void strTtoFile_startingLetter(char* str, char letter, char* fileName) {
	int i=0;
	char c;
	FILE* fp = NULL;
	fopen_s(&fp, fileName, "w");
	if (!fp) { return NULL; }

	char bigLetter = letter - 'a' + 'A';
	if (str[1] == bigLetter || str[i] == letter) {
		while (str[i]!=' '&&str[i]!='\0') {
			fputc(str[i], fp);
			i++;
		}
		fprintf(fp, "\n");
		if(str[i]!='\0')
			i++;
	}
	
	while (str[i] != '\0') {
		if ((str[i] == letter || str[i] == bigLetter) && str[i - 1] == ' ') {
			while (str[i] != ' ' && str[i] != '\0') {
				fputc(str[i], fp);
				i++;
			}
			fprintf(fp, "\n");

		}
		else { i++; }
	}

	fclose(fp);

}

int main() {

	char* path = "C:\\temp\\q3_17_b_a.txt";
	strTtoFile_startingLetter("tele hebe fsdf lkjglkgj  lkgj gl klg g f", 'g', path);

	return 0;
}