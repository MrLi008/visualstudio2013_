// ����������д������
#pragma once;

#include "stdafx.h"


// �õ���һ���˿�
int getOnePort(int nowport);

// ��������
string setDomainName(string addr);

// �����ļ�·��
// ���ݵ�ǰ�ļ�·���õ���һ���ļ�·��
string setFilePath(int nownum);



// ����һ����ʼ���˵��ַ�������
char* initializeBuffer(int length);


// �齨Ҫ���͵���Ϣ
string getSendMessage(string path, string addr);