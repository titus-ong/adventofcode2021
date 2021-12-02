#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int maxSize = 6; // max 4 digits + 2 extra bytes for newline
    char *first = malloc(maxSize);
    char *second = malloc(maxSize);
    char *third = malloc(maxSize);
    char *fourth = malloc(maxSize);

    int increaseCount = 0;

    FILE *input = fopen("./input", "r");
    fgets(first, maxSize, input);
    fgets(second, maxSize, input);
    fgets(third, maxSize, input);

    while (!feof(input))
    {
        fgets(fourth, maxSize, input);
        if (atoi(fourth) > atoi(first))
        {
            increaseCount++;
        }
        strcpy(first, second);
        strcpy(second, third);
        strcpy(third, fourth);
    }
    
    free(first);
    free(second);
    free(third);
    free(fourth);
    fclose(input);

    printf("Number of sums are larger than the previous sum: %d", increaseCount);

    return 0;
}