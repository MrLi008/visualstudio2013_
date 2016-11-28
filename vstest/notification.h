/****************************************************/

/*

描述
1,	文件监视技术
2,	用到的函数:	
	HANDLE FindChangeNotification{
		LPCTSTR		lpPathName,
		BOOL		bWatchSubtree,
		DWORD		dwNotifyFilter
		};
	BOOL FindNextChangeNotifycation{
		HANDLE hChangeHandle
	};
	BOOL FindCloseChangeNotification{
		HANDKE hChangeHandle
	};


3,	思考
	由于FindChangeNotification返回值是一个引用对象,
	不是指针, 在退出所调用该函数的函数后, 对象呗清空,
	不知有何解决方法



*/
#include "stdafx.h"

#pragma once


/****************************************************/
// self define structure
struct HANDLESANDLENGTH {
	int length;
	HANDLE* hChangeHandles;
};


/********* test function: **********/
void testFindChangeNotificationHandle( );

// set event handle
HANDLE* setFindChangeNotification(
	LPCTSTR	lpPathName,
	//BOOL	bWatchSubtree, 
		// true for 监视子目录, 
		// false for 不见时子目录
	DWORD	dwNotifycation
	);

// begin listenning
DWORD WINAPI onListeningThread( 
	LPVOID arg 
	);

// close handle
void closeFindChangeNotification(
	HANDLE* dwChangeHandle,
	int length
	);