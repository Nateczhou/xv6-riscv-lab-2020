#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) 
{
    //create a pipe
    int p[2];
    char buf[1];
    // buf[0] = *argv[1];
    // create a pipe but not connect it to 
    pipe(p);
    // fork a child
    if (fork() == 0) {
        close(0);
        dup(p[0]);
        close(p[0]);
        read(0, buf, 1);
        fprintf(2,"%d: received ping\n", getpid());
        close(0);
        dup(p[1]);
        write(0, buf, 1);
        close(p[1]);
        close(0);
        exit(0);
    } else {
        // parent write to write end of pipe which is p[1]
        close(0);
        dup(p[1]);
        write(0, buf, 1);
        close(p[1]);
        close(0);

        // parent read from child
        wait(0);
        dup(p[0]);
        read(0, buf, 1);
        close(p[0]);
        close(0);
        fprintf(2, "%d: received pong\n", getpid());
    }
    exit(0);
}