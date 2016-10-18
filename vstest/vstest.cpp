// vstest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"



int main() {

	testScanPortSimple();

	system( "pause" );
	return 0;
}







//
//// 栏栅加密
//// 
//int main( void ) {
//
//	char*ch = "tn c0afsiwal kes,hwit1r  g,npt  ttessfu}ua u  hmqik e {m,  n huiouosarwCniibecesnren.";
//	//char*ch = "1234567890";
//	int length = strlen(ch);
//	int num = 2;
//	int n = 0;
//	char*res = new char[ length ];
//	for ( int num = 1; num < length; num++ ) {
//		n = 0;
//		int counter = length / num;
//		for ( int j = 0; j < num; j++ ) {
//			for ( int i = 0; i < counter; i++ ) {
//				if ( j + i*num < length && n < length) {
//					res[ n ] = ch[ j + i*num ];
//					n++;
//				}
//			}
//		}
//		/*for ( int i = 0; i < length; i++ ) {
//			res[ i ] = ch[( i * num + i%length) % length ];
//		
//		}*/
//		for ( int i = 0; i < length; i++ ) {
//			cout << res[ i ];
//			if ( i + 1 < length ) {
//				if ( res[ i ] == 'f' && res[ i + 1 ] == '{' ) {
//					cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||";
//				}
//			}
//		}
//		cout << endl;
//	}
//
//	system( "pause" );
//	return 0;
//}
//



//int main(void){
//
//	// getfilefromdir("D:\\exe", vector<string>());
//	findfrom(vector<string>(), "");
//	system("pause");
//	return 0;
//}

//int main(void){
//
//	cout << "This is for productting some 字符串" << endl;
//
//
//	
//	testproductcharactors();
//	
//
//	// cout << 'a'-0 << endl;
//
//	system("pause");
//	return 0;
//}

//
//int main(void){
//
//	testfuncofMyHandle();
//
//	system("pause");
//	return 0;
//}
//
//













/*
int _tmain(int argc, _TCHAR* argv[])
{


	system("pause");
	return 0;


}
*/
//#include <WinSock2.h>


/*
void test();
void run(int port, string addr, string path);






int main(int argc, char* argv[])
{
	cout << "begin test: " << endl;

	//test();
	
		const string s ("string");
		string* teststring = new string();
		char * ch = new char(10);
		// cin >> ch;
		// teststring = ch;
		// cin >> teststring; 此处有错!
		cout << s.c_str() << ";;;" << teststring->c_str();
		sprintf(initializeBuffer(s.length()), "%s-------------", s);
	



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
	run(80, "172.16.22.128", "/uploads/index.php");
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


*/