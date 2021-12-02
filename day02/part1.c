#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int maxSize = 11; // max 7 chars + space + 1 digit + 2 extra bytes for newline
    char *baseInstruction = malloc(maxSize);
    char *instruction, *direction, *distance;

    int horizontal = 0;
    int depth = 0;

    FILE *input = fopen("./input", "r");
    // place this outside while loop so that on last line, file is read past end of line and feof works correctly
    fgets(baseInstruction, maxSize, input);


    while (!feof(input))
    {
        instruction = baseInstruction;
        direction = strsep(&instruction, " ");
        distance = strsep(&instruction, " ");

        if (strcmp(direction, "forward") == 0)
        {
            horizontal += atoi(distance);
        } else if (strcmp(direction, "down") == 0)
        {
            depth += atoi(distance);
        } else
        {
            depth -= atoi(distance);
        }
        fgets(baseInstruction, maxSize, input);
    }
    
    free(baseInstruction);
    fclose(input);

    printf("Final horizontal position multiplied by final depth: %d", horizontal*depth);

    return 0;
}