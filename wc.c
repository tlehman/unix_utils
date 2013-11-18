/** a re-implementation of wc(1)
    by tlehman at 1384790932 */
#include <stdio.h>

int main(int argc, const char *argv[])
{
    if(1 == argc) {
        printf("%d  %d  %d", 
                count_lines(),
                count_words(),
                count_chars());
    }
    return 0;
}

