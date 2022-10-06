// TODO: Print 1 if input is vowel

#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n;
    char c;
    char upper;

    do {
        n = read(STDIN_FILENO, &c, 1);

        upper = toupper(c);

        write(STDOUT_FILENO, &upper, 1);
    } while (n != 0);

    return EXIT_SUCCESS;
}
