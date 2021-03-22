// CS 2690 Program 2
// Simple Windows Sockets Server Client (IPv6)
// Last update: 2/12/19
// <Garrett Cook> <601> <10/27/2020>
// <Windows 10, Visual Studio Community 2019>
//
// Server usage: WSEchoServerv6 <server port>
//
// This program is coded in conventional C programming style, with the 
// exception of the C++ style comments.
//
// I declare that the following source code was written by me or provided
// by the instructor. I understand that copying source code from any other 
// source or posting solutions to programming assignments (code) on public
// Internet sites constitutes cheating, and that I will receive a zero 
// on this project if I violate this policy.
// ----------------------------------------------------------------------------
#include <stdio.h>       // for print functions
#include <stdlib.h>      // for exit() 
#include <winsock2.h>	 // for Winsock2 functions
#include <ws2tcpip.h>    // adds support for getaddrinfo & getnameinfo for v4+6 name resolution
#include <Ws2ipdef.h>    // optional - needed for MS IP Helper
#define MAXQUEUED  100
#define ECHOSIZE 99

void DisplayFatalErr(char* errMsg);


void main(int argc, char* argv[])
{

	WSADATA wsaData;                // contains details about WinSock DLL implementation
	struct sockaddr_in6 serverInfo;	// standard IPv6 structure that holds server socket info
	struct sockaddr_in6 clientInfo;
	struct sockaddr_in6 fromAddr;
	int numargs, len, size, bytesRead;
	SOCKET serverSock;
	unsigned short serverPort;
	char* serverIPaddr;
	numargs = argc;
	int clientInfoLen = sizeof(clientInfo);
	char EchoBuff[ECHOSIZE];
	////Verifies the correct number of command line arguments
	//if (argc != 4) {
	//	DisplayFatalErr("Wrong number of arguments");
	//	exit(1);
	//}
	//Initialize the Winsock DLL. Returns 0 if okay.
	if (WSAStartup(MAKEWORD(2, 0), &wsaData))	DisplayFatalErr("WSAStartup() failed.");

	serverSock = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP); // Create server socket
	if (argc > 2) {
		DisplayFatalErr("Incorrect arguments");
		exit(1);
	}
	//assignments to chars
	serverPort = argc == 2 ? atoi(argv[1]) : 5000;




	//Zero out the structure
	memset(&serverInfo, 0, sizeof(serverInfo));
	serverInfo.sin6_family = AF_INET6;
	serverInfo.sin6_port = htons(serverPort);
	serverInfo.sin6_addr = in6addr_any;


	//bind server socket
	bind(serverSock, (struct sockaddr*)&serverInfo, sizeof(serverInfo));

	
	printf("GC's IPv6 echo server is ready for UDP client...");

	for (;;) {
		char ipstrng[INET6_ADDRSTRLEN];
		unsigned int fromSize = sizeof(fromAddr);
		int EchoLength;
		if ((EchoLength = recvfrom(serverSock, EchoBuff, ECHOSIZE, 0, (struct sockaddr*)&fromAddr, &fromSize)) < 0) DisplayFatalErr("recvfrom() function failed.");
		printf("\n Processing the client %s, client port %i, server port %i", inet_ntop(AF_INET6, &(fromAddr.sin6_addr), ipstrng, sizeof(ipstrng)), ntohs(fromAddr.sin6_port), ntohs(serverInfo.sin6_port));
		if (sendto(serverSock, EchoBuff, EchoLength, 0, (struct sockaddr *) &fromAddr, &fromSize) != EchoLength) DisplayFatalErr("sendto() function failed.");
		
	}
	


}