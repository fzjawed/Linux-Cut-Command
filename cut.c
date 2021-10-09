#include "cutfuncs.h"
int main(int argc, char *argv[])
{
    /** main
     * Simplistic version of Linux cut command (cuts only fields)
     * @param argc - number of arguments passed in
     * @param argv - array of arguments passed in
     * Returns 0, then exits with 0 if functions did not exit already
     * Input is the characters from stdin
     * Output is the characters from stdin cut based on fields and delimiters
     */
    checkArgs(argc, argv);
    cutCommand(argc, argv);
    return 0;
    exit(0);
}