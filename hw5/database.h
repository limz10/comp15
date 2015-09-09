/*

 */

#include "song.h"

class Database
{
public:
    Database();
    void read_file(string filename);
    string alphaOnly(string s);
    void addSong(Song *s);
    void searchWord(string word);
    void sortResults(string word);
    void printResults(string word);

private:
    vector<Song*> allSongs;
    unordered_multimap<string, Song**> results;
};
