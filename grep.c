#include <stdio.h>
#include <regex.h>

int match(const char *regexp, const char *line);
int grep(const char *regexp, FILE *f);


int main(int argc, const char *argv[])
{
    if(2 == argc) {
        // grep stdin
    } else {
        // loop over remaining argc - 2 files and grep each
        for(int i = 2; i < argc; ++i) {
            // open file
            // grep file
            // close file
        }
    }

    return 0;
}

int grep(const char *regexp, FILE *f)
{
    char buf[BUFSIZ];
    int nmatches;

    while( NULL != fgets(buf, BUFSIZ, f) ) {
        if(match(regexp, buf)) {
            printf("%s\n", buf);
            ++nmatches;
        }
    }

    return nmatches;
}

int match(const char *regexp, const char *line)
{
    return 0;
}

