#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	/* do stuff */
	if (argc < 4) {
		puts("Please re-run the program with 4 arguments.");
		return 0;
	}

	char* lname = argv[1];
	char* fname = argv[2];
	double hours = atof(argv[3]);
	double rate = atof(argv[4]);

	double pay = hours * rate / 60;

	printf("%s %s: %.2f", fname, lname, pay);

	return 0;
}

