#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    FILE *output = NULL;
    char filename[8];
    int file_count = 0;

    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(filename, "%03i.jpg", file_count);

            output = fopen(filename, "w");
            file_count++;
        }

        if (output != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }
    fclose(input);

    return 0;
}
