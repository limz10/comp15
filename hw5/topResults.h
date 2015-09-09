/*

*/

#include "song.h"
#include<unordered_map>
#include<utility>

using namespace std;

class TopResult
{
public:
    TopResult();
    void addSong(Song *s);
    void print(string word);
    void setSongs(vector<Song*> s);

private:
    vector<Song*> songs;
};
