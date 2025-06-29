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

    if(!ISVALIDSOCKET(new_socket))
    {
        fprintf(stderr, "Socket() failed. (%d)\n", GETSOCKETERRORNO());
        return 1;
    }

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

    //Create Socket
    SOCKET socket_listen = create_socket(bind_addr);

    //Bind the socket to local network address
    printf("Binding socket to local address----\n");

    if(bind(socket_listen, bind_addr->ai_addr, bind_addr->ai_addrlen))
    {
        fprintf(stderr, "bind() failed. (%d)\n", GETSOCKETERRORNO());
        return 1;
    }

    freeaddrinfo(bind_addr);

    //Listen for connections
    printf("Listening-----\n");

    //max number of connections allowed to be queued
    int max_num = 10;

    if(listen(socket_listen, max_num) < 0)
    {
        fprintf(stderr, "listen() failed. (%d)\n", GETSOCKETERRORNO());
        return 1;
    }

    //accept incomming connection
    printf("Waiting for  connection----\n");

    struct sockaddr_storage client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    //Typecast from sockaddr_storage pointer into sockaddr pointer
    SOCKET socket_client = accept(socket_listen, (struct sockaddr*) &client_addr, &client_len);

    if(!ISVALIDSOCKET(socket_client))
    {
        fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRORNO());
        return 1;
    }
    

    //print client's address
    printf("Client is connected-----\n");
    
    char address_buffer[100];
    getnameinfo((struct sockaddr*) &client_addr, client_len, address_buffer, sizeof(address_buffer), 0, 0, NI_NUMERICHOST);

    printf("%s\n", address_buffer);
    
    //Read request from client
    printf("Reading request-----\n");

    char request[1024];
    int bytes_received = recv(socket_client, request, sizeof(request), 0);

    if(bytes_received <= 0)
    {
        fprintf(stderr, "recv() failed. (%d)\n", GETSOCKETERRORNO());
        return 1;
    }

    printf("Received %d bytes. \n", bytes_received);

    return 0;
}