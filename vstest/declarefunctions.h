// ����������д������
#pragma once;

#include "stdafx.h"





// �õ���һ���˿�
int getOnePort(int nowport);

// ��������
string setDomainName(string addr);

// �����ļ�·��
// ���ݵ�ǰ�ļ�·���õ���һ���ļ�·��
string setFilePath(string path);



// ����һ����ʼ���ַ�������
char* initializeBuffer(int length);

// ��ʼ��sockaddr
struct sockaddr_in initializeSockaddr(struct hostent *he, int g_nPort);


// �齨Ҫ���͵���Ϣ
string getSendMessage(string path, string addr);



// class test MyHandle function:

void testfuncofMyHandle();

// �����ַ���
int testproductcharactors();

// ��ȡ�ļ����µ������ļ�
void getfilefromdir(string filepath, vector<string>& file);
// ������Щ�ļ����Ƿ����ĳ���ַ�
void findfrom(const vector<string> files, string str);