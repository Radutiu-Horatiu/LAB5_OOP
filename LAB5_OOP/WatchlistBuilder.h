#pragma once
#include <vector>
#include <string>
#include "Film.h"
#include "Repository.h"
#include <fstream>
using namespace std;

class WatchlistBuilder
{
public:
	
	virtual void build_watchlist(vector <int> watchlist, Repository& repo);
	void copy_line_by_line_from_and_store_into(string source, string destination);
};

