// 左旋
unsigned char rol( unsigned char val )
{
  int high_bit;
  if ( val & 0x80 )
  {
    high_bit = 1;
  }
  else
  {
    high_bit = 0;
  }
  // 左移操作，最低位变为零
  val <<= 1;
  // 将最高位值送给最低位
  val |= high_bit;
  return val;
}
#include <iostream>
using namespace std;
int main( )
{
  unsigned char i = 0x80;
  cout << rol( i ) << endl;
  return 0;
}
