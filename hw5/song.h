/*

*/

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Song
{
public:
    Song(string a, string t, vector<string> l);
    int frequency(string word);
    void print(string word);
    vector<string> context(string word);

private:
    string title, artist;
    vector<string> lyrics;
};
