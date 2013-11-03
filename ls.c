/** a re-implementation of ls(1)
    by tlehman at 1383506012 */
#include <stdio.h>
#include <sys/stat.h>

void print_directory_contents(char *path) {
    
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        print_directory_contents(".");
    } else {
        print_directory_contents(argv[1]);
    }
    return 0;
}

