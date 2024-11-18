#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <bits/types/sigset_t.h>
#include <asm-generic/signal.h>

void sig_hander1( int sugnum )
{
    printf("i am signal hander 1\n");
}

int main()
{
    sigset_t new_set, old_set;

    if(signal(SIGINT, sig_hander1) == SIG_ERR)
    {
        printf("Fail to handle SIGINT");
        exit(EXIT_FAILURE);
    }

    sigemptyset(&new_set);
    sigemptyset(&old_set);

    
}