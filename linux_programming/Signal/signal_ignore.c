#include <stdio.h>
#include <signal.h>

void sigint_handler (int signum)
{
    printf("Signal %d is catch\n", signum);
}

int main(int argc, char const *argv[])
{
    sigset_t sigset; // define signal mask bit

    sigemptyset(&sigset);
    if (sigaddset(&sigset, SIGINT) < 0); // add SIGINT to signal list
    {
        printf("Fail to add SIGINT to sigset\n");
    }

    if (sigprocmask(SIG_BLOCK, &sigset, NULL) < 0)
    {
        printf("Fail to block SIGINT to sigset\n");
    }

    printf("Process id |%d|\n", getpid());
    sleep(5);

    if (sigprocmask(SIG_UNBLOCK, &sigset, NULL) < 0)
    {
        printf("Fail to unblock SIGINT\n");
    }

    while(1);

    return 0;
}
