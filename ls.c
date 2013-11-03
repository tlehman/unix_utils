/** a re-implementation of ls(1)
    by tlehman at 1383506012 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void print_directory_contents(const char *path) {
    DIR *this_dir = opendir(path);
    struct dirent *this_file;

    if(this_dir == NULL) {
        fprintf(stderr, "error opening %s\n", path);
        exit(1);
    }

    while( (this_file = readdir(this_dir)) != NULL ) {
        printf("%s\n", this_file->d_name);
    }

    closedir(this_dir);
}

int main(int argc, const char *argv[]) {
    if(argc == 1) {
        print_directory_contents(".");
    } else {
        print_directory_contents(argv[1]);
    }
    return 0;
}

