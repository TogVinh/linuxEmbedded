#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler1(int num)
{
    printf("\n I am signal handler 1 : |%d|\n", num);
    //while(1);
    //
    
    exit(EXIT_SUCCESS);
}

void sig_handler2(int num)
{
    printf("\n I am signal handler 2 : |%d|\n", num);
}

void sig_handler3(int num)
{
    printf("\n I am signal handler 3 : |%d|\n", num);
}

int main()
{
    if (signal(SIGINT, sig_handler1) == SIG_ERR)
    {
        printf("Can not handler SIGINT\n");
        exit(EXIT_FAILURE);
    }

    // sleep(4);
    // kill(getpid(), SIGINT);

    while (1)
    {
        /* code */
        printf("hello\n");
        sleep(2);
    }
    
}