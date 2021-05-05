#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 10

int main(int argc, char *argv[]){
  /* Do stuff */
    FILE* inFile;
    char* filename = argv[1];
    inFile = fopen(filename, "r"); // read only

    char line[MAXCHAR];

    int sum = 0;

    while (fgets(line, MAXCHAR, inFile) != NULL)
    {
        sum += atoi(line);
    }

    printf("%d", sum);

    fclose(inFile);
    return 0;
}
