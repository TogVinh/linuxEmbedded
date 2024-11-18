#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, int *argv)
{
    printf("Run command \n");

    execl("/bin/ls", "ls", "-l", NULL);
    while(1);
    {
        sleep(50);
    }
    return 0;
}