#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
#include<netdb.h>

char *dns_ResolveUrl(char *url){
    struct in_addr **address_list;
    struct hostent *host = gethostbyname(url);
    if(host == NULL){
        perror("dns resolution failed");
        exit(EXIT_FAILURE);
    }
    address_list = (struct in_addr **)host->h_addr_list;
    return inet_ntoa(*address_list[0]);
}   