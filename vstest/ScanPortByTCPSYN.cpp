# include "stdafx.h"

# pragma once
// #include <netmon.h>
#include <MSTcpIP.h>
#include <WS2tcpip.h>
#include <fwpmu.h>
#include <sddl.h>
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "fwpuclnt.lib")

typedef struct _IPHeader // 20字节的IP头 
{
	UCHAR iphVerLen; // 版本号和头长度（各占4位） 
	UCHAR ipTOS;  // 服务类型 
	USHORT ipLength; // 封包总长度，即整个IP报的长度 
	USHORT ipID; // 封包标识，惟一标识发送的每一个数据报 
	USHORT ipFlags; // 标志 
	UCHAR ipTTL; // 生存时间，就是TTL 
	UCHAR ipProtocol; // 协议，可能是TCP、UDP、ICMP等 
	USHORT ipChecksum; // 校验和 
	ULONG ipSource; // 源IP地址 
	ULONG ipDestination; // 目的IP地址 
} IPHeader, *PIPHeader;
typedef struct _UDPHeader {
	USHORT         sourcePort;                // 源端口号 
	USHORT         destinationPort;// 目的端口号 
	USHORT         len;                        // 封包长度 
	USHORT         checksum;                // 校验和 
} UDPHeader, *PUDPHeader;
/*TCP头定义，共20个字节*/
typedef struct _TCP_HEADER {
	short m_sSourPort;        // 源端口号16bit
	short m_sDestPort;        // 目的端口号16bit
	unsigned int m_uiSequNum;   // 序列号32bit
	unsigned int m_uiAcknowledgeNum;  // 确认号32bit
	short DataOffset;					// 偏移
	short m_sHeaderLenAndFlag;       // 前4位：TCP头长度；中6位：保留；后6位：标志位
	short m_sWindowSize;        // 窗口大小16bit
	short m_sCheckSum;         // 检验和16bit
	short m_surgentPointer;       // 紧急数据偏移量16bit
} TCP_HEADER, *PTCP_HEADER,TCPHeader;
// 计算校验和
USHORT CheckSum( USHORT* buffer, int size ) {
	ULONG cksum = 0;
	while ( size > 1 ) {
		cksum += *buffer;
		size = sizeof( USHORT );

	}

	if ( size ) {
		cksum += *(UCHAR*)buffer;
	}

	while ( cksum >> 16 ) {
		cksum = ( cksum && 0xffff ) + ( cksum >> 16 );
	}

	return (USHORT)( ~cksum );
}


/*
 * 计算TCP为头部校验和, 基于:
 * 源IP地址
 * 目的0域
 * 8位0域
 * 8位协议域
 * 16位TCP长度
 * TCP头部和TCP数据
 *
 */

void ComputerTcpPseudoHeaderCheckum( IPHeader* pIphdr, 
									TCPHeader* pTcphdr, 
									char* payload, 
									int payloadlen ) {

	char buff[ 1024 ];
	char* ptr = buff;
	int chksumlen = 0;
	ULONG zero = 0;

	// 伪头部包含源IP地址和目的IP地址
	memcpy( ptr, &pIphdr->ipSource, sizeof( pIphdr->ipSource ) );
	ptr += sizeof( pIphdr->ipSource );
	chksumlen += sizeof( pIphdr->ipSource );

	memcpy( ptr, &pIphdr->ipDestination, sizeof( pIphdr->ipDestination ) );
	ptr += sizeof( pIphdr->ipDestination );
	chksumlen += sizeof( pIphdr->ipDestination );

	//  包含8位0域
	memcpy( ptr, &zero, 1 );
	ptr += 1;
	chksumlen += 1;

	// 协议
	memcpy( ptr, &pIphdr->ipProtocol, sizeof ( pIphdr->ipProtocol ) );
	ptr += sizeof( pIphdr->ipProtocol );
	chksumlen += sizeof( pIphdr->ipProtocol );
	// TCP长度
	int tcplen = sizeof( TCPHeader );
	USHORT tcp_len = htons(  tcplen + payloadlen );
	memcpy( ptr, &tcp_len, sizeof( tcp_len ) );
	
	// TCP头
	memcpy( ptr, pTcphdr, sizeof( TCPHeader ) );
	ptr += sizeof( tcp_len );
	chksumlen += sizeof( TCPHeader );
	// TCP数据, 净荷
	memcpy( ptr, payload, payloadlen );
	ptr += payloadlen;
	chksumlen += payloadlen; 

	// 补齐到下一个16位边界
	for ( int i = 0; i < payloadlen % 2; i++ ) {
		*ptr = 0;
		ptr++;
		chksumlen++;
	}

	// 计算校验和, 将结果填充到TCP头
	pTcphdr->m_sCheckSum = CheckSum( (USHORT*)buff, chksumlen );
}

// 解析返回的数据包函数
int DecodeIPPacket( char* pData, struct sockaddr_in szDest) {
	IPHeader* pIpHdr = (IPHeader*)pData;
	if ( pIpHdr->ipSource != inet_addr( inet_ntoa( szDest.sin_addr ) ) ) {
		return -1;
	}
	if ( pIpHdr->ipProtocol != IPPROTO_TCP ) {
		return -1;
	}
	int nHeaderLen = ( pIpHdr->iphVerLen & 0xF )*sizeof( ULONG );
	TCPHeader* pTcpHdr = (TCPHeader*)( pData + nHeaderLen );
	if ( ( pTcpHdr->m_sHeaderLenAndFlag & TCP_SYN ) && ( pTcpHdr->m_sHeaderLenAndFlag & TCP_ACK ) ) {
		return 1;

	} else {
		return 0;
	}
	return -1;

}



int scanPort( int port, char* ip ) {
	if ( ip == NULL ) {
		cerr << "no ip......" << endl;
		return 0;
	}

	int DestPort = 80;
	int SourcePort = 5555;
	char szBuffer[ 4024 ] = { 0 };
	IPHeader ip_header;
	TCPHeader tcp_header;
	WSADATA ws;
	WSAStartup( MAKEWORD( 2, 2 ), &ws );
	SOCKET sRaw = socket( AF_INET, SOCK_RAW, IPPROTO_IP );
	SOCKET sListen = socket( AF_INET, SOCK_RAW, IPPROTO_IP );



	// 设置IP头操作选项
	bool bOpt = true;

   /*	
	* Parameters
	*	s[ in ]
	*	A descriptor that identifies a socket.
	*	level[ in ]
	*	The level at which the option is defined( for example, SOL_SOCKET ).
	*	optname[ in ]
	*	The socket option for which the value is to be set( for example, SO_BROADCAST ).The optname parameter must be a socket option defined within the specified level, or behavior is undefined.
	*	optval[ in ]
	*	A pointer to the buffer in which the value for the requested option is specified.
	*	optlen[ in ]
	*	The size, in bytes, of the buffer pointed to by the optval parameter.
	*	
	**/
	setsockopt( sRaw, IPPROTO_IP, IP_HDRINCL, (char*)&bOpt, sizeof( bOpt ) );

	// 获取本机主机IP
	UCHAR strHostName[ 56 ];
	
	gethostname( (char*)strHostName, 56 );

	struct hostent* pHost;
	pHost = gethostbyname( (char*)strHostName );

	struct sockaddr_in szHost;
	memcpy( &szHost.sin_addr.S_un.S_addr, pHost->h_addr_list[ 0 ], pHost->h_length );
	szHost.sin_family = AF_INET;
	szHost.sin_port = htons( SourcePort );
	bind( sListen, (SOCKADDR*)&szHost, sizeof( szHost ) );

	// 设置网卡
	// 混合模式
	DWORD dwValue = 1;
	ioctlsocket( sListen, SIO_RCVALL, &dwValue );
	// 获取目标IP

	struct sockaddr_in szDest;
	memset( &szDest, 0, sizeof( szDest ) );
	
	szDest.sin_family = AF_INET;
	szDest.sin_port = htons( DestPort );

	if ( ( szDest.sin_addr.S_un.S_addr = inet_addr( ip ) ) == INADDR_NONE ) {
		if ( ( pHost = gethostbyname( ip )) != NULL ) {
			memcpy( &( szDest.sin_addr ), pHost->h_addr_list[ 0 ], pHost->h_length );
		} else {
			printf( "Need a Dest IP Address" );
			return 0;
		}
	}

	printf( "Scanning IP: %s.......\n\n", inet_ntoa( szDest.sin_addr ) );
	// 构造并发送数据包
	ip_header.iphVerLen = ( 4 << 4 | sizeof( ip_header ) / sizeof( ULONG ) );
	ip_header.ipTOS = 0;
	ip_header.ipLength = htons( sizeof(ip_header)+sizeof( tcp_header ) );
	ip_header.ipID = 1;
	ip_header.ipFlags = 0;
	ip_header.ipTTL = 121;
	ip_header.ipProtocol = IPPROTO_TCP;
	ip_header.ipChecksum = 0;
	ip_header.ipSource = inet_addr( inet_ntoa( szHost.sin_addr ) );
	ip_header.ipDestination = inet_addr( ip );
	ip_header.ipChecksum = CheckSum( (USHORT*)&ip_header, sizeof( ip_header ) );
	memcpy( szBuffer, &ip_header, sizeof( IPHeader ) );

	tcp_header.m_sDestPort = htons( DestPort );
	tcp_header.m_sSourPort = htons( SourcePort );
	tcp_header.m_uiSequNum = htons( DestPort );
	tcp_header.m_uiAcknowledgeNum = 0;
	tcp_header.m_sWindowSize = htons( 5647 );
	tcp_header.m_surgentPointer = 0;
	tcp_header.m_sCheckSum = 0;
	tcp_header.m_sHeaderLenAndFlag = TCP_SYN; //
	tcp_header.DataOffset= ( sizeof( tcp_header ) / 4 << 4 | 0 );

	ComputerTcpPseudoHeaderCheckum( &ip_header,
		&tcp_header,
		NULL,
		0 );
	memcpy( &szBuffer[ sizeof( IPHeader ) ], &tcp_header, sizeof( TCPHeader ) );
	int iError = 0;

	int nLen = sizeof(ip_header)+sizeof( tcp_header );
	if ( sendto( sRaw, 
				szBuffer, 
				nLen + 34, 
				0, 
				( struct sockaddr*)&szDest,
				sizeof(szDest)) == SOCKET_ERROR){
		printf( "Send Data  Error!\n" );
		closesocket( sRaw );
		closesocket( sListen );
		iError = WSAGetLastError();
		printf( "Error Code: %d\n", iError );
		return -1;
	}

	printf( "Send Data Success!\n" );
	// 接受数据
	char szRecv[ 1024 ] = { 0 };
	memset( szRecv, 0, sizeof( szRecv ) );
	int szDestLen = sizeof( szDest );
	int len = 0;
	while ( 1 ) {
		recv( sListen, szRecv, sizeof( szRecv ), 0 );
		iError = DecodeIPPacket( szRecv ,szDest);
		if ( iError == 1 ) {
			printf( "\tPort: %d Open!\n", DestPort );
			break;
		} else if ( iError == 0 ) {
			printf( "\tPort: %d Closed!\n", DestPort );
			break;
		} else {
			continue;
		}
	}

	closesocket( sRaw );
	closesocket( sListen );
	return 0;
}