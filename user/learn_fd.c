#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main() 
{
    char *child = "Hi from child!\n";
    char *parent = "Hi from parent!\n";
    if (fork() == 0) {
        write(1, child, 15);
        close(1);
        write(1, child, 15);
    } else {
        wait((int *)0);
        write(1, parent, 16);
    }
    exit(0);
}