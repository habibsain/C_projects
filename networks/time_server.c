#if defined(_WIN32)//windows

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include<winsock2.h>
#include<ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#else//Linux
#define _GNU_SOURCE
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<ifaddrs.h>
#endif

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>


#if defined(_WIN32)
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRORNO() (WSAGetLastError())

#else
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define GETSOCKETERRORNO() (errno)
#define SOCKET int

#endif

SOCKET create_socket(struct addrinfo* address_ptr)
{
    printf("Creating Socket----\n");
    
    SOCKET new_socket;
    new_socket = socket(address_ptr->ai_family, address_ptr->ai_socktype, address_ptr->ai_protocol);

    return new_socket;
}

int main()
{
    #if defined(_WIN32)//windows
    WSDATA d;

    if(WSAStartup(MAKEWORD(2, 2),  &d))
    {
        fprintf(stderr,"Failed to initialise socket.\n");
        return -1;
    }
    #endif

//console
    // time_t timer;
    // time(&timer);

    // printf("Current time: %s\n", ctime(&timer));

//networked
    struct addrinfo hints;
    memset(&hints,  0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo* bind_addr;

    getaddrinfo(0,"8080", &hints, &bind_addr);

    SOCKET socket_listen = create_socket(bind_addr);

    return 0;
}