/** a re-implementation of wc(1)
    by tlehman at 1384790932 */
#include <stdio.h>

#define is_whitespace

int main(int argc, const char *argv[])
{
    char c;
    int in_word = 0;
    int chars, words, lines = 0, 0, 0;

    if(1 == argc) {
        // read from pipe
        do {
            c = getc(stdin);

            ++chars;
            if('\n' == c) ++lines;

            if(in_word && ' ' == c)

        } while(c != EOL);
    } else {
        // argv[1] is filename
        // open file
        // read character
        // if EOL
        //   close file
    }

    printf("%d  %d  %d", lines, words, chars);

    return 0;
}

