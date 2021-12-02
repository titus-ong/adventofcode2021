#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int maxSize = 6; // max 4 digits + 2 extra bytes for newline
    char *prev = malloc(maxSize);
    char *curr = malloc(maxSize);
    int increaseCount = 0;

    FILE *input = fopen("./input", "r");
    fgets(prev, maxSize, input);

    while (!feof(input))
    {
        fgets(curr, maxSize, input);
        if (atoi(curr) > atoi(prev))
        {
            increaseCount++;
        }
        strcpy(prev, curr);
    }
    
    free(prev);
    free(curr);
    fclose(input);

    printf("Number of measurements are larger than the previous measurement: %d", increaseCount);

    return 0;
}