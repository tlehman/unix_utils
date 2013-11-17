#include <sys/types.h>
#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* a re-implementation of cat(1), to learn the basic Unix syscalls.
  by tlehman at 1383415046 
*/

void usage(const char *progname)
{
    printf("%s filename\n", progname);
    exit(EXIT_FAILURE);
}

void print_file_contents(int fd)
{
    ssize_t b;
    char buf[BUFSIZ];

    while ( (b = read(fd, buf, BUFSIZ)) != 0 ) {
        write(STDOUT_FILENO, buf, b);
    }
}

int stdin_non_empty() 
{
    fd_set fds;
    FD_SET(STDIN_FILENO, &fds);
    return select(1, &fds, NULL, NULL, NULL);
}

int main(int argc, char const *argv[])
{
    int i;
    int fd;

    if (argc > 1) {
        for(i = 1; i < argc; i++) {
            fd = open(argv[i], O_RDONLY);
            print_file_contents(fd);
            close(fd);
        }
    } else if (stdin_non_empty()) {
        print_file_contents(STDIN_FILENO);
    } else {
        usage(argv[0]);
    }
    return 0;
}

