#include <iostream>
using namespace std;
class Automobile  // 抽象类
{
public:
    virtual void Display( ostream& os ) const = 0;  // 纯虚函数
};

class Car : public Automobile  // Car继承自Automobile
{
public:
    Car( const char* szP ) : szCar( szP ){}
    void Display( ostream& os ) const
    {
        os << szCar << endl;
    }
private:
    string szCar;
};

class Truck : public Automobile  // Truck继承自Automobile
{
public:
    Truck( const char* szP ) : szTruck( szP ){}
    void Display( ostream& os ) const
    {
        os << szTruck << endl;
    }
private:
    string szTruck;
};

// 插入运算符重载，参数是基类Automobile
ostream& operator<<( ostream& os, const Automobile& am )
{
    am.Display( os );
    return os;
}

int main( )
{
    Car car1( "Ford" );
    Truck truck1( "Forton" );
    operator<<( operator<<( cout, car1 ), truck1 );
    
    cout << endl;
    
    Car car2( "Land Rover" );
    Truck truck2( "Liberation" );
    cout << car2 << truck2;
    return 0;
}
