#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED "\e[0;31m"

int write_file(char *filename);

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        exit(0);
    }

    for (int i = 1; i < argc; i++)
    {
        int result = access(argv[i], R_OK);

        if (result != 0)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }
    }

    for (int i = 1; i < argc; i++)
    {
        write_file(argv[i]);
    }
}

int write_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    int c;
    if (file)
    {
        while ((c = getc(file)) != EOF)
        {
            putchar(c);
        }
    }
    fclose(file);

    return 0;
}