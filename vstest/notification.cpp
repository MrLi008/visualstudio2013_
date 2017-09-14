#include "stdafx.h"



void testFindChangeNotificationHandle() {

	const int length = 1;

	const int notificationlist[ 5 ] = {
		FILE_NOTIFY_CHANGE_ATTRIBUTES,
		FILE_NOTIFY_CHANGE_CREATION,
		FILE_NOTIFY_CHANGE_FILE_NAME,
		FILE_NOTIFY_CHANGE_SIZE,
		FILE_NOTIFY_CHANGE_DIR_NAME
	};

	DWORD dwWaitStatus;
	HANDLE* dwChangeHandle = new HANDLE[ length ];

	// set nofity path:
	char* pathnotified = "F:\\software\\linuxcore\\filenotify";
	dwChangeHandle[ 0 ] = FindFirstChangeNotification(
		(LPCTSTR)pathnotified,
		FALSE,
		notificationlist[ 0 ]
		);
	//dwChangeHandle[ 1 ] = FindFirstChangeNotification(
	//	(LPCTSTR)pathnotified,
	//	FALSE,
	//	notificationlist[ 1 ]
	//	);
	//dwChangeHandle[ 2 ] = FindFirstChangeNotification(
	//	(LPCTSTR)pathnotified,
	//	FALSE,
	//	notificationlist[ 2 ]
	//	);
	//dwChangeHandle[ 3 ] = FindFirstChangeNotification(
	//	(LPCTSTR)pathnotified,
	//	FALSE,
	//	notificationlist[ 3 ]
	//	);
	//dwChangeHandle[ 4 ] = FindFirstChangeNotification(
	//	(LPCTSTR)pathnotified,
	//	FALSE,
	//	notificationlist[ 4 ]
	//	);
	//for ( int i = 0; i < length; i++ ) {
	//	dwChangeHandle[i] =  setFindChangeNotification(
	//		(LPCTSTR)pathnotified,
	//		notificationlist[ i ]
	//		);
	//	//dwChangeHandle[ i ] = FindFirstChangeNotification(
	//	//	(LPCTSTR)pathnotified,
	//	//	FALSE,
	//	//	notificationlist[ i ]
	//	//	);
	//	if ( dwChangeHandle[ i ] == NULL ) {
	//		cerr << "false set notify: " <<GetLastError()<< endl;
	//		return;
	//	}
	//	cout << dwChangeHandle[i] << endl;

	//}

	cout << "���óɹ�" << endl;

	LPDWORD tid = 0;

	// �����߳���Ҫ������
	HANDLESANDLENGTH hal;
	hal.hChangeHandles = dwChangeHandle;
	hal.length = length;

	// ��ʼ����
	CreateThread( NULL, 0,
		(LPTHREAD_START_ROUTINE)onListeningThread,
		(LPVOID)&hal,
		NULL,
		tid );

	// ����������
	// cout << "endding............." << endl;

}
// ���ü���
HANDLE* setFindChangeNotification(
	LPCTSTR	lpPathName,
	//BOOL	bWatchSubtree, 
	// true for ������Ŀ¼, 
	// false for ����ʱ��Ŀ¼
	DWORD	dwNotifycation
	) {

	HANDLE h = FindFirstChangeNotification(
		lpPathName,
		FALSE,
		dwNotifycation
		);
	return &h;
}

// �����߳���غ���
DWORD WINAPI onListeningThread(
	LPVOID arg
	) {
	HANDLESANDLENGTH* hal = ( struct HANDLESANDLENGTH* )arg;
	DWORD dwWaitStatus;
	int counter = 10;
	cout << "begin" << hal->hChangeHandles << endl;
	while ( TRUE ) {
		dwWaitStatus = WaitForMultipleObjects(
			hal->length,
			hal->hChangeHandles,
			FALSE,
			10000
			);

		FindNextChangeNotification( hal->hChangeHandles );

		cout << dwWaitStatus << endl;

		if ( counter <= 0 ) {
			break;
		}
		counter--;
	}

	closeFindChangeNotification( hal->hChangeHandles, hal->length );

	return GetLastError();
}

// �رռ��ӵĺ���
void closeFindChangeNotification(
	HANDLE* dwChangeHandle,
	int length
	) {
	for ( int i = 0; i > length; i++ ) {
		FindCloseChangeNotification( dwChangeHandle[i] );
		cout << "close ........" << endl;
	}
}