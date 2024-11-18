#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd;
    int numb_read, numb_write;
    char buf1[64] = "hello world\n";

    fd = open("hello.txt", O_RDWR | O_CREAT, 0666);
    if (-1 == fd)
    {
        printf("----- open fail -----\n");
    }

    numb_write = write(fd, buf1, strlen(buf1));
    printf("Write |%d| bytes to file \n", numb_write);

    lseek(fd, 0, SEEK_SET);
    write(fd, "2", strlen("2"));

    close(fd);

    return 0;;

}