#pragma once
#include "WatchlistBuilder.h"
#include <fstream>
using namespace std;

class htmlBuilder : public WatchlistBuilder
{
public:
	/// <summary>	Builds watchlist HTML. </summary>
	///
	/// <remarks>	Horatiu, 5/1/2020. </remarks>
	///
	/// <param name="filename"> 	Name of the file. </param>
	/// <param name="watchlist">	The watchlist to be written. </param>
	void build_watchlist(vector <int> watchlist, Repository& repo);
};

