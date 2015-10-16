#include <iostream>
using namespace std;

#define PRINT(STR, VAR) \
cout << STR << " = " << VAR << endl;

int main( )
{
    int j = 2;
    int i = 1;
    PRINT( "j + i", j + i );
    return 0;
}
