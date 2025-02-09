#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int client_fd;
    struct sockaddr_in address;
    char buffer[1024] = {0};

    snprintf(buffer, sizeof(buffer), "Hello, Message from client");

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0)
    {
        printf("Can not create socket , client_fd = %d\n", client_fd);
    }

    //define address
    address.sin_family = AF_INET;
    address.sin_port = htons(11111);
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);

    if (connect(client_fd, (struct sockaddr *)&address, sizeof(address)) < 0 )
    {
        printf("connect Fail\n");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    send(client_fd, buffer, sizeof(buffer), 0);
    close(client_fd);

    return 0;
}