// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE * fp;

    fp = fopen("text.txt", a+);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork Failure\n");
        exit(1);
    } else if (rc == 0) {
        printf("child success (pid: %d)\n", (int) getpid());
        char child_str[] = "This is child string!\n";
        fwrite(child_str, 1, sizeof(child_str), fp);
    } else {
        printf("parent success (pid: %d)\n", (int) getpid());
        char parent_str[] = "Parent string\n";
        fwrite(parent_str, 1, sizeof(parent_str), fp);
    }

    fclose(fp);
    return 0;
}
