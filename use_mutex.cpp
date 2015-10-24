#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>

using std::vector;
using std::thread;
using std::atomic;
using std::mutex;
using std::cout;
using std::endl;

#include <opencv/cv.h>

#include <opencv/highgui.h>

using namespace cv;

Mat g_mat; 
mutex g_mat_mutex;

void thread1( Mat&  g_mat )
{
	g_mat_mutex.lock( );
	imshow( "origin", g_mat );
	cvWaitKey( 0 );
	g_mat = g_mat + 60;
	imshow( "th1", g_mat );
	cvWaitKey( 0 );

	g_mat_mutex.unlock( );
}

void thread2( Mat&  g_mat )
{
	g_mat_mutex.lock( );
	g_mat = g_mat - 60;
	imshow( "th2", g_mat );
	cvWaitKey( 0 );

	g_mat_mutex.unlock( );
}

int main( int argc, char** argv )
{
	g_mat = imread( argv[1] );
	thread th1( thread1, g_mat );
	thread th2( thread2, g_mat );

	th1.join( );
	th2.join( );
	return 0;
}
