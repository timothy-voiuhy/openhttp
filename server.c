
#include<stdio.h>
#include<stdlib.h>

#include "core.h"

int main(int argc, char const *argv[])
{
    char *data;
    int sock_fd = http_CreateSocket();
    http_SetSocketOptions(sock_fd);
    char *ip= "127.0.0.1";
    http_Bind(sock_fd,8090,ip);
    http_Listen(sock_fd);
    while (1){
        int new_sockfd= http_Accept(sock_fd);
        data = http_Receive(new_sockfd);
        printf("%s",data);
        // char *s_data = "hi";
        // http_Send(sock_fd, s_data);
        free(data);
    }
    return 0;
}
