#include "stdafx.h"

// send thread
// ���������������

/*
	@author MrLi
	ͨ��winsock���������������
	���Ի���:
	��������дһ����վ
	�ɴ˳��������վ��������
	�鿴����ͳɹ�
 
*/

/*
	�˴�Ϊ�ؼ�����ʵ��
*/

// �����̴߳��ݵĲ��������ݽṹ
struct SendData {
	int i;// ���
	char *host;

	char *path;


};



// ���Ժ���
void testSendThread() {
	// ���÷��ʴ���
	const int RefreshTimes = 1;
	const int length = 128;
	char host[ length ];
	char path[ length ];

	HANDLE hThread;
	DWORD dwThread;

	int i = 0;
	// initialize
	setParam(host, path);

	// init
	

	// 
	for ( i = 0; i < RefreshTimes; i++ ) {

		SendData sd;
		sd.i = i;
		sd.host = host;
		sd.path = path;

		hThread = CreateThread( NULL, 0, SendThread, (LPVOID)&sd, 0, &dwThread );

		if ( hThread == NULL ) {
			cout << "\t create thread faild" << endl;
			exit( 0 );
		}
		Sleep( 1000 );
		CloseHandle( hThread );
	}

}


// �̺߳���, ���������������
DWORD WINAPI SendThread( LPVOID lpParam ) {
	SendData* sd = ( struct SendData* )lpParam;
	WSADATA wsd;

	SOCKET sockfd;
	SOCKADDR_IN addr;
	HOSTENT* host = NULL;

	if ( WSAStartup( MAKEWORD( 2, 2 ), &wsd ) != 0 ) {

		cout << "\n\t wsa startup faild, error code: " << WSAGetLastError() << endl;
		// exit( 0 );
		return 0;
	}

	host = gethostbyname( sd->host );
	cout << "host: " << host->h_name;
	if ( host == NULL ) {
		cout << "host name is error, errorcode: " << WSAGetLastError() << endl;
		WSACleanup();
		// exit( 0 );
		return 0;
	}

	addr = initializeSockaddr( host, 81 );
	sockfd = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if ( INVALID_SOCKET == sockfd ) {
		cout << "sockfd error, error code: " << WSAGetLastError() << endl;
		WSACleanup();
		// exit( 0 );
		return 0;
	}
	cout << "connect...." << endl;
	if ( 0 > connect( sockfd, ( struct sockaddr* )&addr, sizeof( addr ) ) ) {
		cout << "\n\t error connect, error code: " << WSAGetLastError() << endl;
		WSACleanup();
		// exit( 0 );
		return 0;
	}
	char* sendbuffer;// = initializeBuffer( 1024 );
	// ׼��Ҫ���͵�����
	sendbuffer = prepardatatosend( );
	if ( send( sockfd, sendbuffer, strlen( sendbuffer ) + 1, 0 ) == SOCKET_ERROR ) {
		cout << " \n\t error code: " << WSAGetLastError() << endl;
		// exit( 0 );
		return 0;
	}
	char* recvbuffer = initializeBuffer( 128 );

	// ������ܵ�����
	ofstream output;
	output.open( "1921681129.txt", ios::app );
	if ( output.is_open() ) {
		cout << "open success" << endl;
	}

	while ( recv( sockfd, recvbuffer, strlen( recvbuffer ), 0 ) > 0 ) {
		int lengthrecv = strlen( recvbuffer );
		cout << "recv:" << lengthrecv << endl;
		for ( int j = 0; j < lengthrecv; j++ ) {
			cout << recvbuffer[ j ];
			output << recvbuffer[ j ];
		}
		//delete recvbuffer;
		recvbuffer = initializeBuffer( 128 );
		cout << endl;
	}
	output.close();
	closesocket( sockfd );
	WSACleanup();

	return 0;
	
}


void setParam( char* host, char* path ) {
	// ���÷�����վ��������IP
	strcpy( host, "192.168.1.129" );
	// ���÷��ʵ�·��
	strcpy( path, "/" );


}

char* prepardatatosend(  ) {
	//strcpy( buff, "GET / HTTP/1.1"
	//	"Host: 192.168.1.129 : 81"
	//	"Proxy - Connection : keep - alive"
	//	"Cache - Control : max - age = 0"
	//	"Upgrade - Insecure - Requests : 1"
	//	"User - Agent : Mozilla / 5.0 ( Windows NT 6.1; WOW64 ) AppleWebKit / 537.36 ( KHTML, like Gecko ) Chrome / 54.0.2840.99 Safari / 537.36"
	//	"Accept : text / html, application / xhtml + xml, application / xml; q = 0.9, image / webp, */*;q=0.8"
	//	"Accept-Encoding: gzip, deflate, sdch"
	//	"Accept-Language: zh-CN,zh;q=0.8"
	//	"Cookie: yunsuo_session_verify=1472061db5ea58530639b3bad17904e8; "
	//	"ASPSESSIONIDASAARCAD=JFGHJNMAFJOMPPCMDDEIJAPO" 
	//	);

	char* buff = "GET / HTTP/1.1"
		"Host: 192.168.1.129 : 81"
		"Proxy - Connection : keep - alive"
		"Cache - Control : max - age = 0"
		"Upgrade - Insecure - Requests : 1"
		"User - Agent : Mozilla / 5.0 ( Windows NT 6.1; WOW64 ) AppleWebKit / 537.36 ( KHTML, like Gecko ) Chrome / 54.0.2840.99 Safari / 537.36"
		"Accept : text / html, application / xhtml + xml, application / xml; q = 0.9, image / webp, */*;q=0.8"
		"Accept-Encoding: gzip, deflate, sdch"
		"Accept-Language: zh-CN,zh;q=0.8"
		"Cookie: yunsuo_session_verify=1472061db5ea58530639b3bad17904e8; "
		"ASPSESSIONIDASAARCAD=JFGHJNMAFJOMPPCMDDEIJAPO";
	return buff;
}

