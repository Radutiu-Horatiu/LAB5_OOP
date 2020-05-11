#include "WatchlistBuilder.h"
#include <fstream>

using namespace std;

void WatchlistBuilder::build_watchlist(vector<int> watchlist, Repository& repo)
{
}

void WatchlistBuilder::copy_line_by_line_from_and_store_into(string source, string destination)
{
	ofstream write;
	write.open(destination, ofstream::out | ofstream::trunc);

	ifstream file(source);
	string str;
	while (getline(file, str))
		write << str << '\n';
}