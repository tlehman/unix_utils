/** a re-implementation of ls(1)
    by tlehman at 1383506012 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void print_directory_contents(const char *path, char *flags[])
{
    DIR *this_dir = opendir(path);
    struct dirent *this_file;

    if(this_dir == NULL) {
        fprintf(stderr, "error opening %s\n", path);
        exit(1);
    }

    while( (this_file = readdir(this_dir)) != NULL ) {
        if( '.' != this_file->d_name[0] ) {
            printf("%s\n", this_file->d_name);
        }
    }

    closedir(this_dir);
}

void usage()
{
    printf("Usage: ls [OPTION]... [FILE]...\n");
    printf("List information about the FILEs (the current directory by default).\n");
}

int main(int argc, const char *argv[])
{
    // extract flags
    // extract file/directory names
    // loop over each file/directory, print_directory_contents(path, flags)

    if( 1 == argc ) {
        print_directory_contents(".");
    } else {
        print_directory_contents(argv[1]);
    }
    return 0;
}

