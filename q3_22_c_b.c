#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* inverseString(char* str)
{
	char* primary;
	char* secondary;
	char* res;
	int len = strlen(str);

	res = (char*)calloc(len + 1, sizeof(char));

	secondary = primary = &str[len];   
	while (secondary != str)
	{
		while (*secondary != ' ' && secondary != str)
		{
			secondary--;
		}

		if (secondary == str)//זה בשביל אם אני הגעתי להתחלה ואין כבר רווח אז אני צריך להוסיף רווח ישנית לשורה של התשובה
			strcat(res, " ");

		if (primary == &str[len])//חד פעמי נכנס לתנאי זה רק בפעם הראשונה כי אני לא רוצה לקחת את הרווח הקיים בתוך סקונדרי ולכן אני מכניס לרזולט עם תו אחד קדימה(כתובת) מסטרינג בלי הרווח 
			strcat(res, secondary + 1);
		else
			strcat(res, secondary);//לפה זה יכנס כל שאר הפעמיים מהפעם השנייה ועד הסוף
		primary = secondary;
		*primary = '\0';

	}
	strcpy(str, res);
	free(res);
	res = NULL;
	return str;
}


int main() {

	char str[] = "ab cd ef gh";
	char *str1 = inverseString(str);
	printf("%s", str1);
	return 0;
}