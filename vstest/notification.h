/****************************************************/

/*

����
1,	�ļ����Ӽ���
2,	�õ��ĺ���:	
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


3,	˼��
	����FindChangeNotification����ֵ��һ�����ö���,
	����ָ��, ���˳������øú����ĺ�����, ���������,
	��֪�кν������



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
		// true for ������Ŀ¼, 
		// false for ����ʱ��Ŀ¼
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