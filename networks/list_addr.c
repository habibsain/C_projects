#if defined(_WIN32)//windows

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include<winsock2.h>
#include<ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#else//Linux
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<ifaddrs.h>
#include<fcntl.h>
#include<net/if.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#endif

#include<stdio.h>
#include<stdlib.h>

int main()
{
    #if defined(_WIN32)//Windows

    #else//Linux
    struct ifaddrs* addresses;
    
    if(getifaddrs(&addresses) == -1)
    {
        fprintf(stderr, "Unsuccessful call for getifaddrs");
        return -1;
    }

    //Traverse the Linked List
    struct ifaddrs* address = addresses;
    
    while (address)
    {
        int family = address->ifa_addr->sa_family;
        if(family == AF_INET || family == AF_INET6)
        {
            printf("%s\t", address->ifa_name);
            printf("%s\n", family == AF_INET ? "IPv4" : "IPv6");
        

        char ap[100];
        const int family_size = family == AF_INET ? \
            sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
        
        //getnameinfo(address->ifa_addr, family_size ,ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
        //printf("\t%s\n", ap);
        }
        
    address->ifa_next;
    }

    freeifaddrs(addresses);
    return 0;

    #endif
}