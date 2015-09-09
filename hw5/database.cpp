/*

*/

#include "database.h"

Database::Database()
{
}

/*
    read_lyics 
    purp: read in song data from a disk file
    args: the name of the file, bool to ask for progress status
    rets: nothing
    does: calls a function each time a word is found
*/
void Database::read_file(string filename)
{
    ifstream in(filename);		// creates an input stream
    string artist, title, word;		// data from the file

    // -- While more data to read...
    while (!in.eof())
    {
	// -- First line is the artist
	getline(in, artist);
	if (in.fail()) break;

	// -- Second line is the title
	getline(in, title);
	if (in.fail()) break;

	// -- Then read all words until we hit the 
	// -- special <BREAK> token
	vector<string> lyrics;
	while ( in >> word && word != "<BREAK>" ) 
	    lyrics.push_back(alphaOnly(word));
	
	Song *aSong = new Song(artist,title,lyrics);	
	addSong(aSong);

	// -- Important: skip the newline left behind
	in.ignore();
    }
}

// alphaOnly() strips off non-alphabetic and non-digit characters
// and returns a string with just the alphas and digits.
string Database::alphaOnly(string s) 
{
    ostringstream ss;

    for (size_t i=0;i<s.length();i++) 
	if (isalnum(s[i]))
	    ss << (char)(tolower(s[i]));

    return ss.str();
}

void Database::addSong(Song *s)
{
    allSongs.push_back(s);
}

void Database::searchWord(string word)
{
    Song *songs[10];
    for (int i = 0; i < 10; i ++)
	songs[i] = NULL;

    unsigned long i = 0;
    bool flag = true;
    while (i < allSongs.size()) {
	if (allSongs[i]->frequency(word) != 0) {
	    for (int k = 0; k < 10 && flag; k++)
		if (songs[k] == NULL) { 
		    songs[k] = allSongs[i];
		    flag = false;
		    cerr << "inserted" << endl;
		}
	    if (flag) {
		int min = songs[0]->frequency(word);
		unsigned long indexMin;
		for (unsigned long j = 1; j < 10; j++)
		    if (songs[j]->frequency(word) < min) {
			min = songs[j]->frequency(word);  
			indexMin = j;  
		    }
		if (allSongs[i]->frequency(word) > min) { 
		    songs[indexMin] = allSongs[i];	
		    cerr << "swapped" << endl;
		}
	    }	
	} 
	i++;	    
	flag = true;
    }

    pair<string, Song**> pair(word, songs);
    results.insert(pair);

    cerr << "inserted into results" << endl;
}

void Database::printResults(string word)
{
    for (int i = 0; results.find(word)->second[i] != NULL && i < 10; i++) {
	cerr << "printing #" << i << endl;
	results.find(word)->second[i]->print(word);
	cerr << "#" << i << " printed" << endl;
    }

    cerr << "all printed" << endl;
}

void Database::sortResults(string word)
{
    if (results.find(word)->second[1] == NULL)
	return;

    for (int i = 1; results.find(word)->second[i] != NULL; i++) {
	cerr << "begin sorting" << endl;
	int j = i;
	while (results.find(word)->second[j-1] > results.find(word)->second[j]
	       && j > 0) {
	    Song *temp = results.find(word)->second[j-1];
	    results.find(word)->second[j-1] = results.find(word)->second[j];
	    results.find(word)->second[j] = temp;
	    j--;
	}
    }
}
