// TODO: Cantidad de archivos .c

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 80

int main(int argc, char *argv[])
{
    FILE *output;
    FILE *input;

    char read_buffer[MAX_SIZE];

    output = popen("ls *.c", "r");
    input = popen("./tomay", "w");

    while (fgets(read_buffer, MAX_SIZE, output)) {
        fputs(read_buffer, input);
    }

    pclose(output);
    pclose(input);

    return EXIT_SUCCESS;
}
