/*

 */

#include "song.h"

using namespace std;

Song::Song(string a, string t, vector<string> l)
{
    artist = a;
    title = t;
    lyrics = l;
}

int Song::frequency(string word)
{
    int count = 0;
    for (unsigned long i = 0; i < lyrics.size(); i++)
	if (lyrics[i] == word)
	    count++;

    return count;
}

void Song::print(string word)
{
    for (int i = 0; i < frequency(word); i++)
	cout << "Title: " << title << endl
	     << "Artist: " << artist << endl
	     << "Context: " << context(word)[i] << endl << endl;
}

vector<string> Song::context(string word)
{
    vector<string> contex(frequency(word));
    unsigned long count = 0;
    for (unsigned long i = 0; i < lyrics.size(); i++)
	if (lyrics[i] == word) {
	    if (i <= 5) {
		for (unsigned long j = 0; j < i+6; j++)
		    contex[count] = contex[count] + lyrics[j] + " ";
		contex[count].pop_back();
		count++;
	    }
	    else if (i+5 > lyrics.size()) {
		for (unsigned long j = i-5; j < lyrics.size(); j++)
		    contex[count] = contex[count] + lyrics[j] + " ";
		contex[count].pop_back();
		count++;
	    }
	    else {
		for (unsigned long j = i-5; j < i+6; j++)
		    contex[count] = contex[count] + lyrics[j] + " ";
		contex[count].pop_back();
		count++;
	    }
	}
    return contex;
}
