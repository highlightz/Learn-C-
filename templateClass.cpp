// 演示含有具体类型参数的类模板定义和模板类实例化

#include <iostream>
using namespace std;

template < class T, int SIZE >
class test
{
public:
    void init( )
    {
        for ( int i = 0; i < SIZE; i++ )
        {
            arr[i] = i * i;
        }
    }
    void print( )
    {
        for ( int i = 0; i < SIZE; i++ )
        {
            cout << arr[i] << endl;
        }
    }
private:
    T arr[SIZE];
};

int main( )
{
    test< int, 15 > array;
    array.init( );
    array.print( );
    
    return 0;
}
