#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHARINIT 2

int main(int argc, char *argv[]){

	int dumNum[] = { 0, 1, 2, 3, 4, 5, 6, 7 };


	int* numbers = (int*)malloc(sizeof(int) * CHARINIT);
    int numSize = CHARINIT;
    int totNums = 0;


	for (int i = 0; i < 8; i++)
	{
        if (totNums == numSize) {


            // True if realloc succeeds
            if (realloc(numbers, (sizeof(int) * (numSize *= 2)) != NULL)) {
                

                
            }
            // exit program if realloc fails
            else {
                // instead of exiting, could implement copying
                puts("Realloc failed after array maxed out");
                return 0;
            }
            puts("REALLOC");

        }
        numbers[i] = dumNum[i];

        totNums++;
    }
	

    //free(numbers);

    //numbers = NULL;
    int size = sizeof(int) * CHARINIT * 2;
    void* tmp = realloc(numbers, size);

    if (1) {

        puts("realloc true");
    }


	return 0;
}
