// TODO: Print 1 if input is vowel

#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n;
    char c;
    char upper;
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};

    do {
        n = read(STDIN_FILENO, &c, 1);

        upper = toupper(c);

        for (int i = 0; i != 5; ++i) {
            if (upper == vowels[i]) {
                upper = '1';
            }
        }

        write(STDOUT_FILENO, &upper, 1);
    } while (n != 0);

    return EXIT_SUCCESS;
}
