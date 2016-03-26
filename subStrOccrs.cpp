// 统计一个字符串在另一个字符串中出现的次数
#include <cstring>
#include <iostream>
using namespace std;

int findString( char const* s, char const* child )
{
	char* p = strstr( s, child );
	int lengthChild = strlen( child );
	
	return p ? 1 + findString( p + lengthChild, child ) : 0;
}

int main( )
{
	char* str = "hello worldd worlddddd is beautiful.";
	char* target = "dd";
	
	cout << findString( str,target) << endl;
	
}
