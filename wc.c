/** a re-implementation of wc(1)
    by tlehman at 1384790932 */
#include <ctype.h>
#include <stdio.h>

void wc(FILE *file);

int main(int argc, const char *argv[])
{
    if(1 == argc) {
        // read from pipe
        wc(stdin);
    } else {
        for(int i = 1; i < argc; ++i) {
            FILE *file = fopen(argv[i], "r");
            wc(file);
            fclose(file);
        }
    }

    return 0;
}

void wc(FILE *file)
{
    char c;
    int in_word = 0;
    int chars, words, lines = 0;

    do {
        c = getc(file);

        ++chars;
        if('\n' == c) ++lines;

        if(in_word && isspace(c)) {
            in_word = 1;
            ++words;
        } else if(!in_word && !isspace(c)) {
            in_word = 0;
        }
        in_word = !isspace(c);

    } while(c != EOF);

    printf("%d  %d  %d\n", lines, words, chars);
}


