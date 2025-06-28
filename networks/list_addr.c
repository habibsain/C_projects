#if defined(_WIN32)//windows

#ifndef _WINNIT32
#define _WINNIT32 0x0600
#endif

#include<winsock.h>
#include<iphlptcp.h>
#pragma comment(lib, "")

#else//Linux
#include<sys/socket.h>
#include<netdb.h>
#include<ifaddrs.h>
#endif

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv)
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
        char* family = address->ifa_addr->sa_family;
        if(family == AF_INET || family == AF_INET6)
        {
            printf("%s\t", address->ifa_name);
            printf("%s\n", family == AF_INET ? "IPv4" : "IPv6");
        }

        char ap[100];

        address->ifa_next;
    }
    

    #endif
}