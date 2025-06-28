#if defined(_WIN32)

#ifndef _WINNIT32
#define _WINNIT32 0x0600
#endif

#include<winsock.h>
#include<iphlptcp.h>
#pragma comment(lib, "")

#else
#include<sys/socket.h>
#include<netdb.h>
#include<ifaddrs.h>
#endif

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv)
{
    struct ifaddrs adresses;
}