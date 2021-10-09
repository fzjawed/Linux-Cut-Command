#include "cutfuncs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_fields 100
void checkArgs(int argc, char *argv[])
{
    /** checkArgs
     * Checks if arguments passed in are valid inputs
     * @param argc - number of arguments passed in
     * @param argv - array of arguments passed in
     * Returns nothing, exits 1 if input is invalid
     */
    int arg;      // Current argument
    int arg_next; // Next argument

    if (argc > 1)
    {
        if (argc > 103)
        {
            fprintf(stderr, " %s: specify input_delimiter output_delimiter and 1-%d fields in order. \n", argv[0], max_fields);
            exit(1);
        }
        if (strlen(argv[1]) != 1 || strlen(argv[2]) != 1)
        {
            fprintf(stderr, " %s: specify input_delimiter output_delimiter and 1-%d fields in order. \n", argv[0], max_fields);
            exit(1);
        }
        for (int i = 3; i < argc; i++)
        {
            if (strlen(argv[i]) == 1)
            {
                if (!atoi(argv[i]))
                {
                    fprintf(stderr, " %s: specify input_delimiter output_delimiter and 1-%d fields in order. \n", argv[0], max_fields);
                    exit(1);
                }
            }
            if (strlen(argv[i]) > 1)
            {
                for (int j = 0; j < strlen(argv[i]); j++)
                {
                    if (!isdigit(argv[i][j]))
                    {
                        fprintf(stderr, " %s: specify input_delimiter output_delimiter and 1-%d fields in order. \n", argv[0], max_fields);
                        exit(1);
                    }
                }
            }
            if (i < argc - 1)
            {
                arg = atoi(argv[i]);
                arg_next = atoi(argv[i + 1]);
                if (arg >= arg_next)
                {
                    fprintf(stderr, " %s: specify input_delimiter output_delimiter and 1-%d fields in order. \n", argv[0], max_fields);
                    exit(1);
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    {
        fprintf(stderr, " %s: specify input_delimiter output_delimiter and 1-%d fields in order. \n", argv[0], max_fields);
        exit(1);
    }
}

void cutCommand(int argc, char *argv[])
{
    /** cutCommand
     * Cuts fields based on delimiters from stdin like the Linux cut command
     * @param argc - number of arguments passed in
     * @param argv - array of arguments passed in
     * Input: characters from stdin
     * Output: characters from stdin cut based on fields and delimiters
     */
    char inputDel[2];  // Stores input delimiter
    char outputDel[2]; // Stores output delimiter
    int character;     // Current character
    int counter = 0;   // Counter for field number
    int index = 3;     // Index for arguments in argv
    strcpy(inputDel, argv[1]);
    strcpy(outputDel, argv[2]);
    while ((character = fgetc(stdin)) != EOF)
    {
        if (character == *inputDel)
        {
            if (counter == atoi(argv[index]) - 1 && index < argc - 1)
            {
                printf("%s", outputDel);
                index++;
            }
            counter++;
            continue;
        }
        if (character == 0x0A) // If the character is \n
        {
            counter = 0;
            index = 3;
            putchar(character);
        }
        else
        {
            if (index == argc)
            {
                index = 3;
            }
            if (counter > atoi(argv[index]) - 1)
            {
                continue;
            }
            if (counter == atoi(argv[index]) - 1)
            {
                putchar(character);
            }
        }
    }
}