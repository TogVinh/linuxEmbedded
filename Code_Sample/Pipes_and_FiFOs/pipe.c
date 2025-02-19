#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fds[2] = {0};
    char message[] = "This is message in pipe\0";
    char buff[256] = {0};


    if (pipe(fds) < 0)
    {
        printf("Fail to create pipe\n");
        exit(EXIT_FAILURE);
    }

    write(fds[1], message, strlen(message));

    read(fds[0], buff, sizeof(buff));
    printf("Read mess in pipe : |%s|\n", buff);

    return 0;
}