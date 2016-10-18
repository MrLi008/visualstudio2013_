# include "stdafx.h"

# pragma once

//
//# include "declarefunctions.h"
//# include <stdio.h>
//# include <winsock2.h>
//# pragma comment(lib, "ws2_32")
//



// # define PORT_START (80)
// # define PORT_END (5000)

void testScanPortSimple() {
	int port_begin = 1;
	int port_end = 5000;
	char* ip = "192.168.1.129";

	printf( "Begin scan...." );

	scanPortSimple( port_begin, port_end, ip );

	printf( "Ending scan....." );
}



void scanPortSimple(int port_begin, int port_end, char* addr) {


	if ( addr == NULL ) {
		cerr << "no address to scanned" << endl;
		return;
	}

	WSADATA ws;
	SOCKET sockfd;
	struct sockaddr_in aim_addr;

	WSAStartup( MAKEWORD( 2, 2 ), &ws );
	aim_addr.sin_family = AF_INET;
	aim_addr.sin_addr.S_un.S_addr = inet_addr(addr);

	// 确定扫描from port_begin to port_end
	for ( int i = port_begin; i <= port_end; i++ ) {
		// 建立socket连接
		sockfd = socket( AF_INET, SOCK_STREAM ,0);
		aim_addr.sin_port = htons( i );
		printf( "begin: %d\t", i );
		if ( connect( sockfd, ( struct sockaddr* )&aim_addr, 
			 sizeof( struct sockaddr ) ) == SOCKET_ERROR ) {
			printf( "something wrong....\n" );
			continue;
		}

		// 端口开放
		printf( "\t\t, it is openning...\n" );
	}

	closesocket( sockfd );
	WSACleanup();
	
}