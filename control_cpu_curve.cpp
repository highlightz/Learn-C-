/***********************
* 控制CPU占用曲线的形状
***********************/
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <cmath>

int main( )
{
	/*for ( ; ; )
	{
		for ( int i = 0; i < 9600000; i++ )
			;
		Sleep( 10 );
	}*/

	//int busyTime = 50;  // 10ms
	//int idleTime = 10;  // Same ratio will lead to 50% cpu usage
	//INT64 startTime = 0;
	//while ( true )
	//{
	//	startTime = GetTickCount( );
	//	// Busy loop
	//	while ( GetTickCount( ) - startTime <= busyTime )
	//		;
	//	// Idle loop
	//	Sleep( idleTime );
	//}

	const double SPLIT = 0.01;
	const int COUNT = 200;
	const double PI = 3.1415926;
	const int INTERVAL = 300;
	DWORD busySpan[COUNT];
	DWORD idleSpan[COUNT];
	int half = INTERVAL / 2;
	double radian = 0.0;
	for ( int i = 0; i < COUNT; i++ )
	{
		busySpan[i] = (DWORD)( half + ( sin( PI * radian ) * half ) );
		idleSpan[i] = INTERVAL - busySpan[i];
		radian += SPLIT;
	}

	DWORD startTime = 0;
	int j = 0;
	while ( true )
	{
		j = j % COUNT;
		startTime = GetTickCount( );
		while ( ( GetTickCount( ) - startTime ) <= busySpan[j] )
			;
		Sleep( idleSpan[j] );
		j++;
	}
	return 0;
}
