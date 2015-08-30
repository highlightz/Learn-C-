// Compile: 
// g++ main.cpp -o main -pthread -std=c++11

#include <thread>
#include <iostream>

void foo( )
{
    std::cout << "foo executed!\n";
}

void bar( int x )
{
    std::cout << "bar executed! " << x << " passed in!\n";
}

int main( )
{
    std::thread first( foo );  // Spawn new thread that calls foo()
    std::thread second( bar, 10 );  // Spawn new thread that calls bar()

    std::cout << "main, foo and bar now execute concurrently...\n";

    // Synchronize threads
    first.join( );  // Pause until first finishes
    second.join( );  // Pause until second finishes

    std::cout << "foo and bar completed.\n";

    return 0;
}
