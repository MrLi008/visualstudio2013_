#include"stdafx.h"


// declarefunctions.h
# include "declarefunctions.h"



int getOnePort(int nowport)
{
	return 80;
}
string setDomainName(string addr)
{
	return "www.baidu.com";
}

string setFilePath(int nownum)
{
	return "/hangj/";
}

char* initializeBuffer(int length)
{
	char* buffer = new char[length];
	for (int i = 0; i < length; i++)
	{
		buffer[i] = 0;
	}
	return buffer;
}


string getSendMessage(string path, string addr){

	return	"GET " + path + " HTTP/1.1\n" +  // URL
			"Host: " + addr + "\n\n";       // Host
}