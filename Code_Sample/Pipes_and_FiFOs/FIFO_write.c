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
    char mess[] = "Hello from writer\n";

    // Kiểm tra xem FIFO đã tồn tại chưa, nếu chưa thì tạo
    if (access(FIFO_FILE, F_OK) == -1)
    {
        if (mkfifo(FIFO_FILE, 0666) < 0)
        {
            perror("Failed to create FIFO");
            exit(EXIT_FAILURE);
        }
    }

    // Mở FIFO để ghi
    fd = open(FIFO_FILE, O_WRONLY);
    if (fd < 0)
    {
        perror("Cannot open FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Ghi dữ liệu vào FIFO
    if (write(fd, mess, strlen(mess)) < 0)
    {
        perror("Failed to write to FIFO");
    }

    close(fd);
    return 0;
}
