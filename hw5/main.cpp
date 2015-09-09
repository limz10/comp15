/*
    comp15 hw5 Song Search
    Created by : Mingzhe Li
 */

#include "database.h"

using namespace std;

void read_file(string filename, Database database, bool show_progress);
string alphaOnly(string s);
 
int main(int argc, char *argv[])
{
    Database database;
    string target;

    if (argc == 2) {
	//read from file and add songs to the database
	database.read_file(argv[1]);

	//reading queries
	cin >> target;

	//produce the top results and print
	database.searchWord(target);
	database.sortResults(target);
	database.printResults(target);

	cout << "END-OF-REPORT" << endl;
    }
    else 
	cout << "Usage: songsearch database.txt\n";

    return 0;
}



