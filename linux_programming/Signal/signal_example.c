#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_hanlder(int signum)
{
    printf("SIGINT have catch\n");
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, sigint_hanlder);

    while (1)
    {
        /* code */
        printf("Running \n");
        sleep(5);
    }
    

    return 0;
}
