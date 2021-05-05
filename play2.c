#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHARINIT 2

int main(int argc, char *argv[]){


	char str1[] = "11 22";
	char str2[] = "33 44 55";
	char str3[] = "66 77 88 99";

	char jjarr[3][(sizeof(str1) + sizeof(str2) + sizeof(str3))];

	//char jarr[] = { str1, str2, str3 };
	
	for (int i = 0; i < 15; i++)
	{
		//puts(i);
		//printf("%c", jjarr[0][i]);
	}


	int a;
	char c;
	char temp;

	//sscanf(str1, "%d%c", a, c);
	//printf("int is %d, char is %c\n", &a, &c);

	char str[80] = "This is - www.tutorialspoint.com - website";
	const char s[2] = " ";
	char* token;

	/* get the first token */
	token = strtok(str3, s);

	int out[4];
	int count = 0;

	/* walk through other tokens */
	while (token != NULL) {
		out[count++] = atoi(token);
		//printf(" %d\n", atoi(token));

		token = strtok(NULL, s);
		
	}

	for (int i = 0; i < count; i++) { printf("%d ", out[i]); }
	puts("");


	return 0;
}
