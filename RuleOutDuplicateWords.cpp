// 剔除重复单词
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include <iostream>
using std::cout;

// 判断是否是字母
bool isLetter( char c )
{
	return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';
}

// 提取单词存至向量
typedef string WORD;
vector< WORD > extractWordsFromSentence( string sentence )
{
	vector< WORD > wordVec;

	int i = 0;
    for( ; sentence[i] != '\0'; ++i )
    {
    	WORD word;
    	// 华为机试时，把这里的while写成了if 
        while ( isLetter( sentence[i ])  && sentence[i] != '\0' )
        {
          	word.push_back(sentence[i]);
            ++i;
        }         
		wordVec.push_back( word );     
    }
    
    return wordVec;
}

int main( )
{
  string str = "Where there a will, there is a way.";
  
  vector< WORD > words;
  words = extractWordsFromSentence( str );          	
 	
 	map< WORD, int > wordsHashTable;
 	for ( int i = 0; i < words.size( ); ++i )
 	{
 		++wordsHashTable[words[i]];	
	}
	
	for ( map< WORD, int >::iterator it = wordsHashTable.begin( ); 
	       it != wordsHashTable.end( ); ++it )
 	{	 
 		if ( it->second >= 1 )
 		{
 			cout << it->first << " ";
 			result.insert( it->first );
		}
 	}
    
	return 0;
}
