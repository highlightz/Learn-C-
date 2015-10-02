// 流文件操作演示

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main( )
{
	int nT;
	string szFileName;
	ifstream fin;
	while( true )
	{
		cout << "Input File Name." << endl;
		cin >> szFileName;

		fin.open( szFileName.c_str( ) );  // 文件对象与磁盘文件的绑定，可通过open成员函数滞后完成
		if ( !fin )
		{
			cout << "Can not open file" << endl;
			fin.clear( );  // 清除可能的错误状态
		}
		else
		{
			break;
		}
	}
	
	cout << "Output File Name." << endl;
	cin >> szFileName;
	ofstream fout( szFileName.c_str( ) );
	if ( !fout )
	{
		return -1;
	}

	while ( fin >> nT )
	{
		fout << nT << endl;
	}

	fout.close( );
	fin.close( );

	return 0;
}
