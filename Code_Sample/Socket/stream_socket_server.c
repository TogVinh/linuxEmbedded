#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, new_socket;
    char buffer[1024] = {0};
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        printf("Can not create socket , server_fd = %d\n", server_fd);
    }

    //define address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // listen in all address
    address.sin_port = htons(11111);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0 )
    {
        printf("Bind Fail\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // listen step
    if (listen(server_fd, 2) < 0) // blocking
    {
        printf("Listen Fail \n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    //accept step
    new_socket = accept(server_fd, (struct sockaddr *)&address, &addr_len);

    read(new_socket, buffer, 1024);
    printf("Message from client: \n");
    printf("==========\n");
    printf("%s\n", buffer);
    printf("==========\n");

    close(new_socket);
    close(server_fd);

    return 0;
}