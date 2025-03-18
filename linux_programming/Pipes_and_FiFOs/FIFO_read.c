#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_FILE "./fifo_file"

int main()
{
    int fd;
    char buff[128] = {0};

    // Mở FIFO để đọc
    fd = open(FIFO_FILE, O_RDONLY);
    if (fd < 0)
    {
        perror("Cannot open FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Đọc dữ liệu từ FIFO
    ssize_t bytesRead = read(fd, buff, sizeof(buff) - 1);
    if (bytesRead > 0)
    {
        buff[bytesRead] = '\0'; // Đảm bảo chuỗi kết thúc an toàn
        printf("buff: %s", buff);
    }
    else
    {
        perror("Failed to read from FIFO");
    }

    close(fd);
    return 0;
}
