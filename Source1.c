#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divString(char* str)
{
	char* ptr;
	int count = 1;

	if (str == NULL)
		return 0;

	ptr = strchr(str, ' ');
	while (ptr != NULL)
	{
		*ptr = '\0';
		count++;
		ptr = strchr(ptr + 1, ' ');
	}

	return count;
}

int countMatches(char* str1, char* str2)
{
	int i, j;
	int count = 0;
	int n = divString(str1);
	int m = divString(str2);

	char* p1 = str1;
	for (i = 0; i < n; i++)
	{
		char* p2 = str2;
		for (j = 0; j < m; j++)
		{
			if (!strcmp(p1, p2))
			{
				count++;
				break;
			}
			p2 = strchr(p2, '\0') + 1;
		}
		p1 = strchr(p1, '\0') + 1;
	}

	return count;
}

int main()
{
	char str1[] = "set your goals and achieve them if you are good enough";
	char str2[] = "each course has a set of goals to achieve and a set of tools to use";

	printf("%d\n", countMatches(str1, str2));
}