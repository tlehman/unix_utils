int main(int argc, const char *argv[])
{
    if(2 == argc) {
        // grep over stdin, since this point is reached by:
        // <command> | ./grep 'pat*ern'
    } else {
        /* loop over the remaining (argc - 2) args, 
           open each as file,
             loop over each line of file,
               check if line matches pattern, if so, print line
           */
    }

    return 0;
}
