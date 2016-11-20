#include"stdafx.h"


// declarefunctions.h
# include "declarefunctions.h"



int getOnePort(int nowport)
{
	return nowport;
}
string setDomainName(string addr)
{
	return addr;
}

string setFilePath(string path)
{
	return path;
}

char* initializeBuffer(int length)
{
	char* buffer = new char[length];
	for (int i = 0; i < length; i++)
	{
		buffer[i] = ' ';
	}
	buffer[ length ] = '\0';
	return buffer;
}

struct sockaddr_in initializeSockaddr(struct hostent *he, int g_nPort){
	struct sockaddr_in cliaddr = { 0 };
	cliaddr.sin_family = AF_INET;
	cliaddr.sin_port = htons(g_nPort);
	cliaddr.sin_addr = *((struct in_addr*)he->h_addr_list[0]);
	cout << "ip: " << inet_ntoa(*(struct in_addr*)he->h_addr_list[0]) << "port: " << g_nPort << endl;
	return cliaddr;
}


string getSendMessage(string path, string addr){

	return	"GET " + path + " HTTP/1.1\n" +  // URL
			"Host: " + addr + "\n\n";       // Host
}