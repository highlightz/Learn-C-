#include <iostream>
using namespace std;
class Box
{
public:
    Box( int l, int w, int h ) : length( l ), width( w ), height( h )
    {
    }
    double Volumn( )
    {
        return height * width * length;
    }
private:
    double length; double width; double height;
};

class Cube : public Box
{
public:
    Cube( int h ) : Box( h, h, h ), nH( h )
    {
    }
    int Area( )
    {
        return 6 * nH * nH;
    }
private:
    int nH;
};

int main( )
{
    Box box( 2, 3, 5 );
    cout << "box的体积是：" << box.Volumn( ) << endl;
    Cube cube( 3 );
    cout << "cube的体积是：" << cube.Volumn( ) << endl;
    cout << "cube的表面积是：" << cube.Area( ) << endl;
    return 0;
}
