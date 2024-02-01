#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<netdb.h>
#include "core.h"

#ifdef __IPV6
int http_CreateSocket(){
    int sock  = socket(AF_INET6, SOCK_STREAM,0);
    if(sock == -1){
        perror("socket creation failure");
    }
}
#else
int http_CreateSocket(){
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1){
        perror("socket creation failure");
        return EXIT_FAILURE;
    }else{
    return sock_fd;}
} 
#endif

int http_SetSocketOptions(int fd){
    int reuse = 1;
    if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR, &reuse, sizeof(reuse))== -1){
        return EXIT_FAILURE;
    };
    return EXIT_SUCCESS;
}

int http_Bind(int sock_fd, int port, char *ip_addr){
    struct sockaddr_in addr;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    if(bind(sock_fd,(struct sockaddr *)&addr, sizeof(addr)) == -1){
        perror("Failed to bind socket to port");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;   
}

int http_Connect(int sock_fd, char *ip_addr, int port){
    struct sockaddr_in conn_addr;
    conn_addr.sin_addr.s_addr = inet_addr(ip_addr);
    conn_addr.sin_family = AF_INET;
    conn_addr.sin_port = htons(port);
    if(connect(sock_fd,(struct sockaddr *)&conn_addr,sizeof(conn_addr)) == -1){
        perror("connection failure");
        return EXIT_FAILURE;}
    return EXIT_SUCCESS;
}

char *http_GetConnectedIp(int sockfd){
    struct sockaddr_in connected_ip;
    socklen_t connected_ip_len = sizeof(connected_ip);
    if(getpeername(sockfd,(struct sockaddr *)&connected_ip,&connected_ip_len)!=0){
        perror("get peer name");
    }
    return inet_ntoa(connected_ip.sin_addr);
}

int http_Listen(int sockfd){
    if(listen(sockfd, 5) == -1){
        perror("listening failed");
        return EXIT_FAILURE;
    }else{
        return EXIT_SUCCESS;
    };
}

int http_Accept(int sock_fd){
    struct sockaddr_in connected_ip;
    socklen_t len_connected_ip = sizeof(connected_ip);
    int new_sockfd = accept(sock_fd, (struct sockaddr *)&connected_ip,&len_connected_ip);
    if(new_sockfd == -1){
        perror("failed to accept connection");
        return EXIT_FAILURE;
    }else{
        printf("%s","new connection accepted");
        return new_sockfd;
    }
}

int http_Send(int sock_fd, char *data){
    if(send(sock_fd,data,strlen(data),0) == -1){
        perror("Send Data failure");
        return EXIT_FAILURE;
    };
}

char *http_CreateConnectionSend(char *ip_addr,char *data){
    int sockfd = http_CreateSocket();
    http_Connect(sockfd,ip_addr,PORT_HTTP);
    http_Send(sockfd,data);
    return http_Receive(sockfd);
}

char *http_Receive(int sock_fd){
    char *buffer = malloc(4096);
    ssize_t recievedBytes = recv(sock_fd, buffer, 4096, 0);
    if(recievedBytes < 0){
        perror("Recieving Failure");
    }
    return buffer;
}
