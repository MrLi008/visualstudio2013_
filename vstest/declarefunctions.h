// 函数的声明写在这里
#pragma once;

#include "stdafx.h"


// 得到下一个端口
int getOnePort(int nowport);

// 设置域名
string setDomainName(string addr);

// 设置文件路径
// 根据当前文件路径得到下一个文件路径
string setFilePath(int nownum);



// 返回一个初始化了的字符缓冲区
char* initializeBuffer(int length);


// 组建要发送的消息
string getSendMessage(string path, string addr);