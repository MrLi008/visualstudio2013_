// ����������д������
// ԭ��: ���幦������, �е����Ĳ��Թ���
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




// �˿�ɨ��
// ���������˿�ɨ�����̨����

void testScanPortSimple();
void scanPortSimple( int port_begin, int port_end, char* ip );


// TCP SYN ɨ��
// ����:
// 1, ����TCP���ݰ�
// 2, �޸�ͷ��Ϣ
void testScanPortByTCPSYN();
void ScanPortByTCPSYN(int port_begin, int port_end, char* ip);