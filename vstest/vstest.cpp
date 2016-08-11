// vstest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"

/*
int _tmain(int argc, _TCHAR* argv[])
{


	system("pause");
	return 0;


}
*/
//#include <WinSock2.h>


int main(int argc, char* argv[])
{
	// 发送的数据
	int g_nPort = getOnePort(80);
	string g_strAddr = setDomainName("");
	string g_strPath = setFilePath(1);

	//  Windows Sockets implementation
	
	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2, 2), &WSAData)){
		printf("initializationing error!\n");
		WSACleanup();
		exit(-1);
	}

	struct hostent  *he;
	if ((he = gethostbyname(g_strAddr.c_str())) == NULL){
		printf("gethostbyname failed.\n");
		WSACleanup();
		exit(-1);
	}


	// 创建socket套接子
	struct sockaddr_in      CliAddr = { 0 };
	CliAddr.sin_family = AF_INET;
	CliAddr.sin_port = htons(g_nPort);
	CliAddr.sin_addr = *((struct in_addr*)he->h_addr_list[0]);
	cout << "ip: " << inet_ntoa(*(struct in_addr*)he->h_addr_list[0]) << endl;

	int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sockfd){
		printf("socket failed.\n");
		WSACleanup();
		exit(-1);
	}
	if (0 > connect(sockfd, (struct sockaddr*)&CliAddr, sizeof(CliAddr))){
		printf("connect failed.\n");
		WSACleanup();
		exit(-1);
	}


	// prepare to send message
	string strSend = getSendMessage(g_strPath, g_strAddr);

	// cache
	char* bufSend = initializeBuffer(1024);
	sprintf(bufSend, "%s", strSend.c_str());
	if (0 > send(sockfd, bufSend, strlen(bufSend), 0)){
		printf("send failed.\n");
		WSACleanup();
		exit(-1);
	}

	ofstream os("hangj.html");

	char* bufRecv = initializeBuffer(1024);
	bufRecv[1024] = 0;
	int nRet = 0;
	printf("recv: \n");
	while (sizeof(bufRecv)-1 < (nRet = recv(sockfd, bufRecv, sizeof(bufRecv), 0))){
		// bufRecv[nRet] = 0;
		// printf("%s", bufRecv);
		cout.clear();
		cout << bufRecv;
		os << bufRecv;
	}
	bufRecv[nRet] = 0;
	printf("%s\nendding", bufRecv);
	os << bufRecv;

	os.close();
	closesocket(sockfd);
	WSACleanup();




	system("pause");
	return 0;
}
