// 内存串流演示

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main( )
{
	string szT;
	int nT;
	ofstream fout( "OutputFile.txt" );
	if ( fout.fail( ) ) 
	{
		return 0;
	}

	ifstream fin( "InputFile.txt" );
	if ( fin.fail( ) )
	{
		return -1;
	}

	ostringstream szOut;
	while ( fin >> nT )
	{
		szOut << nT << endl;
	}
	fout << szOut.str( ) << endl;
	fout.close( );
	fin.close( );
	
	return 0;
}
