// Accepts the following arguments:
    // the first argument is a full path to a file (including filename) on the filesystem, referred to below as writefile;
    // the second argument is a text string which will be written within this file, referred to below as writestr
// Exits with value 1 error and print statements if any of the arguments above were not specified
// Creates a new file with name and path writefile with content writestr, overwriting any existing file and creating the path if it doesn’t exist. 
// Exits with value 1 and error print statement if the file could not be created.


#include <stdio.h>
#include <libgen.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    
    //printf("** inside main! **\n");

    //take inputs (has to be 2 at least)
    //printf("num of arg: %d\n", argc);
    if (argc < 3) {
        printf("ERROR: Missing arguments!");
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr  = argv[2];

    //printf("File path: %s\n", writefile);
    //printf("Text to write: %s\n", writestr);

    //parse the path to get directory path and file name 
    //can't assign the path and file name to the same pointer and then modify it using dirname() and basename()
    //must duplicate writefile string first
    char *pth = dirname(strdup(writefile));
    char *filename = basename(strdup(writefile));
    
    //printf("Directory: %s\n", pth);
    //printf("Filename:  %s\n", filename);

    // check if the directory exist, otherwise create it
    if (mkdir(pth, 0777) == 0) {
        printf("Directory created.\n");
    } 
    else if (errno == EEXIST) {
        //it returns -1, the directory wasn't created --> use errno
        //printf("Directory exists.\n");
    } 
    else {
        //in case there are other issues, print out the error message
        perror("mkdir");
    }

    // create the file 
    FILE *file = fopen(writefile, "w");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // write into the file 
    // Write the string to the file
    fprintf(file, "%s\n", writestr);

    // Close the file
    fclose(file);

    return 0;
}

