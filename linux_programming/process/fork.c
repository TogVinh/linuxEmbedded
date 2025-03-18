#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    pid_t child_pid;
    int counter = 2;

    printf("default counter |%d|\n", counter);

    child_pid = fork();
    if (child_pid < 0)
        goto end;
    
    if (child_pid == 0) /* child process*/
    {
        printf("This is child process \n");
        printf("PID |%d| \t-\t Parent PID |%d|",getpid(), getppid() );
        printf("\n------------------------\n");
    }
    else
    {
        printf("Parent Process \n");
        printf("PID |%d|", getpid());
        printf("\n------------------------\n");
    }

end:
    return 0;
}