#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRINIT 1024 // 2^3
#define MAXCHAR 1024

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(int argc, char* argv[]) {
    /* do stuff*/
    FILE* inFile;
    char* filename = argv[1];
    inFile = fopen(filename, "r"); // read only
    int numSize = ARRINIT;

    int* numbers = (int*)malloc(sizeof(int) * numSize);
    int totNums = 0;
    char line[MAXCHAR]; // works for lines up to MAXCHAR char in length

    // read the next line from the file into char array line
    while (fgets(line, MAXCHAR, inFile) != NULL)
    {
        //printf("The line is: %d\n", atoi(line));
        //printf("Line is: %s", line);
        //puts("outer");

        char buff[sizeof(line)];
        strncpy(buff, line, sizeof(line));
        //printf("buff is: %s\n", buff);

        //char temp;
        const char delim[2] = " ";
        char* token;
        token = strtok(buff, delim);

        while (token != NULL) 
        {
            //puts("inner");
            //puts(buff);
            
            // If current array is maxed out
            if (totNums == numSize) {
                puts("max");

                // True if realloc succeeds
                if (realloc(numbers, sizeof(int) * (numSize *= 2)) != NULL) {
                    puts("realloc");
                    // exit program if realloc fails
                }
                else {
                    // instead of exiting, could implement copying
                    puts("Realloc failed after array maxed out");
                    return 0;
                }

            }

            numbers[totNums] = atoi(token);
            token = strtok(NULL, delim);

            totNums++;

        }

    }

    

    mergeSort(numbers, 0, totNums - 1);


    //puts("ready to print");
    for (int i = 0; i < totNums -1; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("%d\n", numbers[totNums -1]);


    




    fclose(inFile);
    return 0;
}
