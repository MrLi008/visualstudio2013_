// 函数的声明写在这里
// 原则: 个体功能完整, 有单独的测试过程
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




// 端口扫描
// 建议完整端口扫描控制台程序

void testScanPortSimple();
void scanPortSimple( int port_begin, int port_end, char* ip );


// TCP SYN 扫描
// 步骤:
// 1, 构造TCP数据包
// 2, 修改头信息
void testScanPortByTCPSYN();
void ScanPortByTCPSYN(int port_begin, int port_end, char* ip);


//  线程测试:
/**
 * 
 * 自定义结构体 selfarg
 * 传递给createthread
 * 在线程函数中 输出
 * 
 */

void testselfargbythread();
// 新建的线程调用的函数
DWORD WINAPI WorkThread( LPVOID arg );


// winpacp简单实用
void learn_winpacp();


// 向服务器发送完整数据
// 使用winsock实现
void testSendThread();
DWORD WINAPI SendThread( LPVOID lpVOID );
// 解析参数
void setParam(char* host, char* path);
// 设置要发送的数据
char* prepardatatosend( );