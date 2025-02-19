#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fds[2] = {0};
    char p_message[] = "This is message from parent pipe\0";
    char c_message[] = "This is message from child pipe\0";
    char buff[256] = {0};

    __pid_t pid;


    if (pipe(fds) < 0)
    {
        printf("Fail to create pipe\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == 0)
    {
        printf("Child process, pid |%d|\n", getpid());
        read(fds[0], buff, sizeof(buff));
        printf("Child Read mess in pipe : |%s|\n", buff);

        write(fds[1], c_message, sizeof(c_message));
    }
    else if (pid > 0) // parent
    {
        write(fds[1], p_message, strlen(p_message));
        sleep(5);

        read(fds[0], buff, sizeof(buff));
        printf("Parent read mess in pipe : |%s|\n", buff);

        // waitpid();
    }

    return 0;
}