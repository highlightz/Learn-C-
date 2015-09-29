#include <iostream>
using namespace std;
class Shape
{
public:
    virtual float Area( ) = 0;
};
class Circle : public Shape
{
public:
    Circle( float r ) : fR( r ){}
    float Area( ){return 3.14 * fR * fR;}
private:
    float fR;
};
class Rect : public Shape
{
public:
    Rect( float l, float w ) : fL( l ), fW( w ){}
    float Area( ){return fL * fW;}
private:
    float fL; float fW;
};
int main( )
{
    Shape* pShape = 0;
    pShape = new Circle( 10 );
    cout << "Circle的面积是：" << pShape->Area( ) << endl;
    delete pShape;
    pShape = 0;
    pShape = new Rect( 5, 6 );
    cout << "Rect的面积是：" << pShape->Area( ) << endl;
    delete pShape;
    return 0;
}
