#if defined(_WIN32)//windows

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include<winsock2.h>
#include<iphlpapi.h>
#include<ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")


#else//Linux
#define _GNU_SOURCE

#include<sys/socket.h>
#include<netdb.h>
#include<ifaddrs.h>
#endif

#include<stdio.h>
#include<stdlib.h>

int main()
{

//Windows

    #if defined(_WIN32)

    //Initialise the winsock
    WSADATA d;
    if(WSAStartup(MAKEWORD(2, 2), &d)){
        fprintf(stderr, "Winsock Initialization unsuccessful");
        return -1;
    }

    //request adapter's addresses
    DWORD asize = 20000;
    PIP_ADAPTER_ADDRESSES adapters;

    do
    {
        adapters = (PIP_ADAPTER_ADDRESSES)malloc(asize);

        if(!adapters)
        {
            fprintf(stderr, "%ld byte memory couldn't be allocated.\n", asize);
            WSACleanup();
            return -1;
        }

        int r = GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, 0, adapters, &asize);
        
        if(r == ERROR_BUFFER_OVERFLOW)
        {
            fprintf(stderr, "GetAdaptersAddresses wants %ld bytes.\n", asize);
            free(adapters);
        }
        else if (r == ERROR_SUCCESS)
        {
            break;
        }
        else
        {
            fprintf(stderr, "Error from GetAdaptersAddresses: %d\n", r);
            free(adapters);
            WSACleanup();
            return -1;
        }

    } while (!adapters);

    //Traverse the nodes
    PIP_ADAPTER_ADDRESSES adapter = adapters;
    while(adapter)
    {
        printf("\nAdapter name: %s\n", adapter->FriendlyName);
        PIP_ADAPTER_UNICAST_ADDRESS address = adapter->FirstUnicastAddress;
        while(address)
        {
            printf("\t%s",, address->Address.lpSockaddr->sa_family == AF_INET ? "IPv4" : "IPv6");

            char ap[100];

            getnameinfo(address->Address.lpSockaddr, address->Address.iSockaddrLength, ap sizeof(ap), 0, 0, NI_NUMERICHOST);
            printf("\t%s\n", ap);

            address = address->Next;
        }

        adapter = adapter->Next;
    }

    free(adapters);
    WSACleanup();
    return 0;
    


//Linux

    #else
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
            printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");
        

            char ap[100];
            const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
        
            getnameinfo(address->ifa_addr, family_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
        printf("\t%s\n", ap);
        }
        
        address = address->ifa_next;
    }

    freeifaddrs(addresses);
    return 0;

    #endif
}