#include <stdio.h>
#include <string.h>

void f(char* infile1, char* infile2, char* outfile) {
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	FILE* fp3 = NULL;
	fopen(&fp1, infile1, "r");
	if (!fp1) { exit(1); }
	fopen(&fp2, infile2, "r");
	if (!fp1) { fclose(fp1); exit(1); }
	fopen(&fp3, outfile, "w");
	if (!fp1) { fclose(fp1); fclose(fp2); exit(1); }

	while(fscanf())


}