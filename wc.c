/** a re-implementation of wc(1)
    by tlehman at 1384790932 */
#include <ctype.h>
#include <stdio.h>

#define is_whitespace

int main(int argc, const char *argv[])
{
    char c;
    int in_word = 0;
    int chars, words, lines = 0;

    if(1 == argc) {
        // read from pipe
        do {
            c = getc(stdin);

            ++chars;
            if('\n' == c) ++lines;

            in_word = !isspace(c);

            if(in_word && isspace(c)) {
                in_word = 1;
                ++words;
            } else if(!in_word && !isspace(c)) {
                in_word = 0;
            }

        } while(c != EOF);
    } else {
        // argv[1] is filename
        // open file
        // read character
        // if EOF
        //   close file
    }

    printf("%d  %d  %d\n", lines, words, chars);

    return 0;
}

