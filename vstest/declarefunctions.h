// 函数的声明写在这里
#pragma once;

#include "stdafx.h"





// 得到下一个端口
int getOnePort(int nowport);

// 设置域名
string setDomainName(string addr);

// 设置文件路径
// 根据当前文件路径得到下一个文件路径
string setFilePath(string path);



// 返回一个初始化字符缓冲区
char* initializeBuffer(int length);

// 初始化sockaddr
struct sockaddr_in initializeSockaddr(struct hostent *he, int g_nPort);


// 组建要发送的消息
string getSendMessage(string path, string addr);



// class test MyHandle function:

void testfuncofMyHandle();

// 产生字符串
int testproductcharactors();

// 获取文件夹下的所有文件
void getfilefromdir(string filepath, vector<string>& file);
// 查找这些文件中是否包含某个字符
void findfrom(const vector<string> files, string str);