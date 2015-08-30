// Compile: 
// g++ main.cpp -o main -pthread -std=c++11

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // mutex for critical section

void print_block( int n, char c )
{
    // Critical section ( exclusive access to std::cout signaled by locking mutx):
    mtx.lock( );
    for ( int i = 0; i < n; i++ )
    {
        std::cout << c;
    }
    std::cout << '\n';
    mtx.unlock( );
}

int main( )
{
    std::thread th1( print_block, 50, '*' );
    std::thread th2( print_block, 50, '$' );

    th1.join( );
    th2.join( );

    return 0;
}
