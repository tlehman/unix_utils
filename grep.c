/** a re-implementation of grep(1)
    by tlehman at 1384757784 */
#include <stdio.h>
#include <stdlib.h>
// Use POSIX regular expression library instead of rolling
// my own state machine.
#include <regex.h> 

int grep(const char *re_str, FILE *f);
int match(regex_t *re, const char *line);

int main(int argc, const char *argv[])
{
    // TODO: Check for flags
    if(2 == argc) {
        grep(argv[1], stdin);
    } else {
        // loop over remaining argc - 2 files and grep each
        for(int i = 2; i < argc; ++i) {
            FILE *file = fopen(argv[i], "r");
            grep(argv[1], file);
            fclose(file);
        }
    }

    return 0;
}

int grep(const char *re_str, FILE *f)
{
    char buf[BUFSIZ];
    int nmatches = 0;
    // to avoid a http://xkcd.com/371, allocate the damn re 
    // on the stack instead of an undefined pointer
    regex_t re; 

    // check re_str validity (no flags for now)
    if(0 != regcomp(&re, re_str, 0)) {
        printf("error compiling /%s/\n", re_str);
        exit(EXIT_FAILURE);
    }

    while( NULL != fgets(buf, BUFSIZ, f) ) {
        if(match(&re, buf)) {
            printf("%s\n", buf);
            ++nmatches;
        }
    }

    return nmatches;
}

int match(regex_t *re, const char *line)
{
    regmatch_t matches;
    return 0 == regexec(re, line, 1, &matches, 0);
}

