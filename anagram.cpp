/*
	Finished project proposed at: http://www.cplusplus.com/forum/general/41558/
	Used Hardcore OOP like user wanted, although unnecessary.

*/

#ifndef my_ana
#define my_ana

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{


	string word;
	vector<string> anag;
	vector<string> dict;	
	string path = "dict.txt";

	ifstream is(path);

	if(!is.good())
	{
		cerr << "couldn't open dictionary...";
		exit(1);
	}

	while(is >> word)
	{
		dict.push_back(word);
		//cout << word << "\n";
	}

	word = ""; //reset it

	//Gets word from user
	cout << "Please enter some letters: ";
	cin >> word;
	cout << '\n';

	sort( word.begin(), word.end() );
	do
	{
		anag.push_back(word);
		//cout << word << "\n";
	}
	while( next_permutation( word.begin(), word.end() ) );


	//check anag with dict
	
	vector<string> ::iterator it;
	vector<string> ::iterator ait;
	

	for(it = anag.begin(); it != anag.end(); ++it)
	{
		for(ait = dict.begin(); ait != dict.end(); ++ait)
		{
			if(*ait == *it)
			cout << *ait << "\n";
		}

	}

	return 0;
}


#endif
