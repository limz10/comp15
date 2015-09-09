/*

*/

#include "topResults.h"

TopResult::TopResult()
{
    for (unsigned long i = 0; i < 10; i++)
	songs[i] = NULL;
}

void TopResult::addSong(Song *s)
{
    for (unsigned long i = 0; i < 10; i++)
	if (songs[i] == NULL) {
	    songs[i] = s;
	    return;
	}
}

void TopResult::print(string word)
{
    for (unsigned long i = 0; i < 10; i++)
	songs[i]->print(word);
}

void TopResult::setSongs(vector<Song*> s)
{
    songs = s;
}
