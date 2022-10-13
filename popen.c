#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *output;
    FILE *input;

    output = popen("ls", "r");
    
    input = popen("./tomay", "w");

    return EXIT_SUCCESS;
}
