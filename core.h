#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/tcp.h>

#ifndef __HTTPCORE
#define __HTTPCORE

#define PORT_HTTP 80
#define PORT_HTTPS 443


#ifdef __IPV6
int http_CreateSocket();
#else
int http_CreateSocket();
#endif

int http_Accept(int sock_fd);

int http_SetSocketOptions(int fd);

int http_Bind(int sock_fd, int port, char *ip_addr);

int http_Connect(int sock_fd, char *ip_addr, int port);

int http_Send(int sock_fd, char *data);

int http_Listen(int sockfd);

/*stateless http https create connection*/
char *http_CreateConnectionSend(char *ip_addr,char *data);

/*recieve the data into buffer 
remember to free the buffer */
char *http_Receive(int sock_fd);

/*return the ip address of the connected machine*/
char *http_GetConnectedIp(int sock_fd);

#endif