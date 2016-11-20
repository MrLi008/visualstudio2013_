#include "stdafx.h"
#include "selfarg.h"

void testselfargbythread() {
	struct ARG* arg;
	arg = ( struct ARG* )malloc( sizeof( struct ARG ) );// new ARG();
	arg->ch = 1;
	arg->num = 10;

	struct ARG arg1;
	arg1.ch = 10;
	arg1.num = 111;

	LPDWORD tid = 0;
	for ( int i = 0; i < 100; i++ ) {
		CreateThread( NULL, 0,
			(LPTHREAD_START_ROUTINE)WorkThread, 
			(LPVOID)&arg1,
			NULL,
			tid );
	}
}

DWORD WINAPI WorkThread( LPVOID arg ) {
	/*struct ARG info;
	info.ch = ((struct ARG*)&arg)->ch;
	info.num = ((struct ARG*)&arg)->num;*/


	/*cout << info.ch << "\t";;
	cout << info.num << endl;
*/
	// cout << ( ( struct ARG* )&arg )->ch << "\t" << ( ( struct ARG* )&arg )->num << endl;
	// printf( "%d, %d\n", ( ( struct ARG* )&arg )->ch, ( ( struct ARG* ) &arg )->num );
	struct ARG* a;
	a = ( struct ARG* )arg;
	cout << a->ch << ", " << a->num << "\t" << endl;
	a->ch++;
	a->num--;
	// free( arg );
	return 0;
}