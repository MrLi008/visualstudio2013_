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

void test();
void run(int port, string addr, string path);






int main(int argc, char* argv[])
{
	cout << "begin test: " << endl;

	test();

	system("pause");
	return 0;
}





void test(){

	//int port = 0;
	//for (int port = 50; port < 10000; port++){

	//	run(port, "172.16.21.41", "");
	//}

	//run(80, "www.baidu.com", "");
	//run(80, "123.206.90.107", "");
	run(80, "172.16.21.41", "");
	// 访问默认主页, 分析网页编写的语言
	// 爆破

}

void run(int port, string addr, string path){

	// 发送的数据
	int g_nPort = getOnePort(port);
	string g_strAddr = setDomainName(addr);
	string g_strPath = setFilePath(path);

	//  Windows Sockets implementation

	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2, 2), &WSAData)){
		printf("initializationing error: %d\n", WSAGetLastError());
		WSACleanup();

		// exit(-1);
		return;
	}

	struct hostent  *he = gethostbyname(g_strAddr.c_str());
	if ( he == NULL){
		printf("gethostbyname failed: %d\n", WSAGetLastError());
		WSACleanup();
		//exit(-1);
		return;
	}


	// 创建socket套接子
	struct sockaddr_in      CliAddr = initializeSockaddr(he, g_nPort);

	int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == sockfd){
		printf("socket failed: %d\n", WSAGetLastError());
		WSACleanup();
		// exit(-1);
		return;
	}
	cout << "sockfd....." << endl;
	if (0 > connect(sockfd, (struct sockaddr*)&CliAddr, sizeof(CliAddr))){
		printf("connect failed: %d\n", WSAGetLastError());
		WSACleanup();
		//system("pause");
		//exit(-1);
		return;
	}
	cout << "finish connect..." << endl;

	// prepare to send message
	string strSend = getSendMessage(g_strPath, g_strAddr);

	// cache
	char* bufSend = initializeBuffer(1024);
	sprintf(bufSend, "%s------", strSend.c_str());
	if (0 > send(sockfd, bufSend, strlen(bufSend), 0)){
		printf("send failed: %d\n", WSAGetLastError());
		WSACleanup();
		// exit(-1);
		return;
	}

	cout << " send message....." << endl;
	ofstream os("hangj.html", ios::app);

	int bufRecvLength = 1024;
	char* bufRecv = initializeBuffer(bufRecvLength);
	//cout << "sizeof bufrecv: " << strlen(bufRecv) << endl;
	bufRecv[bufRecvLength] = 0;
	int nRet = 0;
	printf("recv: \n");
	int count = 0;
	count = 0;
	while (sizeof(bufRecv)-1 < (nRet = recv(sockfd, bufRecv, bufRecvLength, 0))){
		// bufRecv[nRet] = 0;
		// printf("%s", bufRecv);
		cout.clear();
		os << bufRecv;
		//cout << count << " ++++ ;;;;" << bufRecv << endl;
		cout << bufRecv;
		//cout << "len: " << strlen(bufRecv) << endl;
		//if( count > 6) 
			//break;
		count++;
	}
	bufRecv[nRet] = 0;
	//printf("%s\nendding", bufRecv);
	os << bufRecv;

	os.close();
	closesocket(sockfd);
	WSACleanup();
}