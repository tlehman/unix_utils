#include <stdio.h>
#include <stdlib.h>

/* a re-implementation of cat(1), to learn the basic Unix syscalls.
  by tlehman at 1383415046 
*/

void usage(char *progname) {
   printf("%s filename\n", progname);
   exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // check if filename
    } else {
      usage(argv[0]);
    }
    return 0;
}
