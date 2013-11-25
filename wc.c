/** a re-implementation of wc(1)
    by tlehman at 1384790932 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void wc(const char *filename);

int main(int argc, const char *argv[])
{
    if(1 == argc) {
        // read from pipe
        wc("/dev/stdin");
    } else {
        for(int i = 1; i < argc; ++i) {
            wc(argv[i]);
        }
    }

    return 0;
}

void wc(const char *filename)
{
    char curr = '\0';
    int in_word = 0;
    int chars, words, lines = 0;

    FILE *file = fopen(filename, "r");
    do {
        curr = getc(file);

        ++chars;
        if('\n' == curr) ++lines;

        if(in_word && isspace(curr)) {
            in_word = 1;
            ++words;
        } else if(!in_word && !isspace(curr)) {
            in_word = 0;
        }
        in_word = !isspace(curr);

    } while(curr != EOF);
    fclose(file);

    // indent width = length(chars num) - length(lines num)
    int width = (int)(ceil(log10(chars)) - ceil(log10(lines)));

    if(strcmp("/dev/stdin", filename) == 0) {
        printf("%d  %d  %d\n", lines, words, chars);
    } else {
        printf("%d  %d  %d  %s\n", lines, words, chars, filename);
    }
}


