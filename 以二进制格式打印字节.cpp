#include <iostream>
using namespace std;

/*
* 表达式(1 << i)在每一个相继位的位置产生一个1，例如：10000000,01000000等。
* 如果这一位和变量val按位与的结果不是零，就表明val的这一位为1。
* 一般来说，在使用字节进行工作时，并不希望用带符号数。
*/
void printBinary( const unsigned char val )
{
  for ( int i = 7; i >= 0; i-- )
  {
    if ( val & ( 1 << i ) )
    {
      cout << "1";
    }
    else
    {
      cout << "0";
    }
  }
}

int main( )
{
  printBinary( 8 );
  return 0;
}
