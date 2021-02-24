#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) 
{
    if (argc == 1)
    {
        fprintf(2, "sleep: enter a sleep time\n");
        exit(1);
    }
    int time;
    time = atoi(argv[1]);
    fprintf(2, "sleeping...\n");
    sleep(time);
    exit(0);
}