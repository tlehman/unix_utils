#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* a re-implementation of cat(1), to learn the basic Unix syscalls.
  by tlehman at 1383415046 
*/

void usage(const char *progname) {
   printf("%s filename\n", progname);
   exit(EXIT_FAILURE);
}

void print_file_contents(const char *filename) {
    int fd;
    ssize_t b;
    char buf[BUFSIZ];

    fd = open(filename, O_RDONLY);

    while ( (b = read(fd, buf, BUFSIZ)) != 0 ) {
        write(STDOUT_FILENO, buf, b);
    }

    close(fd);
}

int main(int argc, char const *argv[]) {
    int i;

    if (argc > 1) {
        for(i = 1; i < argc; i++) {
            print_file_contents(argv[i]);
        }
    } else {
      usage(argv[0]);
    }
    return 0;
}

