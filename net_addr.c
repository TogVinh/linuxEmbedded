#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

#define  OK      0
#define  FAIL   -1
#define  MAX   128

typedef struct object
{
    /* data */
    char ip[MAX];
    char subnet[MAX];
    char interface[MAX];
} object;

typedef struct Wan
{
    /* data */
    char name[MAX];
    char wan_ip[MAX];
}Wan;

Wan wan_addr[] = {
    [0] = {"wan8", "192.168.88.0"},
    [1] = {"wan9", "192.168.99.0"},
    [2] = {"wan10", "192.168.10.0"}
};

int calculate_network_address(char ip[], char subnet[], char wan[], char *network)
{
    struct in_addr ip_address;
    struct in_addr subnet_mask;
    struct in_addr network_address;

    char *test = NULL;


    network_address.s_addr = 0;
    /* transfer ip and submask to binary  */
    if (inet_aton(ip, &ip_address) != 1)
    {
        /* code */
        printf("\n -- Can not transfer IP to binary -- \n");
        return FAIL;
    }

    if (inet_aton(subnet, &subnet_mask) != 1)
    {
        /* code */
        printf("\n -- Can not transfer subnet to binary -- \n");
        return FAIL;
    }

    network_address.s_addr = ip_address.s_addr & subnet_mask.s_addr;
    if(network_address.s_addr == 0)
    {
        printf("\n -- Can not transfer subnet to binary -- \n");
        return FAIL; 
    }

    test = inet_ntoa(network_address);
    strncpy(network, test, MAX);
    return OK;
}

int main()
{
    object r1 = {"192.168.99.88", "255.255.255.0", "wan8"};
    char network[MAX] = {0};
    int ret = -1;

    if(ret = calculate_network_address(r1.ip, r1.subnet, r1.subnet, network))
    {
        printf("\n Fail \n");
        return 0;
    }

    printf("network |%s|", network);

    return 0;
}