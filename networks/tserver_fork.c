//Multiprocess implementation of multiplex TCP

#include "../include/socket_header.h"
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    //Initialise winsock for Windows
    #if defined(_WIN32)
    WSADATA d;

    if(WSAStartup(MAKEWORD(2, 2),  &d))
    {
        fprintf(stderr,"Failed to initialise socket.\n");
        return -1;
    }
    #endif

    struct addrinfo hints;
    memset(&hints,  0, sizeof(hints));
    hints.ai_family = AF_INET6;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo* bind_addr;

    getaddrinfo(0,"8080", &hints, &bind_addr);

    //Create Socket
    SOCKET socket_listen = create_socket(bind_addr);

    if(!ISVALIDSOCKET(socket_listen))
    {
        fprintf(stderr, "Socket() failed. (%d)\n", GETSOCKETERRORNO());
        return 1;
    }

    //Make it support dual-stack sockets
    int  option = 0;
    if(setsockopt(socket_listen, IPPROTO_IPV6, IPV6_V6ONLY, (void*)&option, sizeof(option)))
    {
        fprintf(stderr, "setsockopt() failed. (%d)\n", GETSOCKETERRORNO());
        return  1;
    }

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

    while (1)
    {
        //Typecast from sockaddr_storage pointer into sockaddr pointer
        SOCKET socket_client = accept(socket_listen, (struct sockaddr*) &client_addr, &client_len);

        if(!ISVALIDSOCKET(socket_client))
        {
            fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRORNO());
            return 1;
        }

        int pid = fork();
        if(pid == 0)
        {
            close(socket_listen);

            //print client's address
            printf("Client is connected-----\n");
            
            char address_buffer[100];
            getnameinfo((struct sockaddr*) &client_addr, client_len, address_buffer, sizeof(address_buffer), 0, 0, NI_NUMERICHOST);

            printf("%s\n", address_buffer);
            
            //Read request from client
            printf("Reading request-----\n");

            sleep(3);
            char request[1024];
            int bytes_received = recv(socket_client, request, sizeof(request), 0);

            if(bytes_received <= 0)
            {
                fprintf(stderr, "recv() failed. (%d)\n", GETSOCKETERRORNO());
                return 1;
            }

            printf("Received %d bytes. \n", bytes_received);

            //print the request received
            //Note:The request buffer is not guaranteed to be NULL terminated,
                    //so we have to properly specify the string length we want to print

            printf("%.*s", bytes_received, request);

            //Send response to the client
            //First: HTTP response header
            printf("Sending response-----\n");

            const char* response = "HTTTP/1.1 200 OK\r\n"
                                "Connection: close\r\n"
                                "Content-Type: text/plain\r\n\r\n"
                                "Local time  is: ";

            int bytes_sent = send(socket_client,  response, strlen(response), 0);
            printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));

            //Next: Actual response

            time_t timer;
            time(&timer);
            char *time_msg = ctime(&timer);
            bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
            printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));


            //Close the client connection
            printf("Closing the connection----\n");
            CLOSESOCKET(socket_client);
            exit(0);
        }
        else if(pid < 0)
        {
            fprintf(stderr, "fork() failed. (%d)\n", GETSOCKETERRORNO());
            exit(1);
        }
        else
        {
            //parent process
            waitpid(pid, NULL, 0);

            //Close  thelistening socket
            printf("Close the listening socket-----\n");
            CLOSESOCKET(socket_client);
        }
        
    }

    //Windows
    #if defined(_WIN32)
        WSACleanup();
    #endif

    printf("Finished.\n");

    return 0;
}
