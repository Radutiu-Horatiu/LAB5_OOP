#pragma once
#include <vector>
#include <string>
#include "Film.h"
#include "Repository.h"
using namespace std;

class WatchlistBuilder
{
public:
	/// <summary>	Builds watchlist HTML. </summary>
	///
	/// <remarks>	Horatiu, 5/1/2020. </remarks>
	///
	/// <param name="filename"> 	Name of the file. </param>
	/// <param name="watchlist">	The watchlist to be written. </param>
	void build_watchlist_html(string filename, vector <int> watchlist, Repository& repo);

	/// <summary>	Builds watchlist CSV. </summary>
	///
	/// <remarks>	Horatiu, 5/10/2020. </remarks>
	///
	/// <param name="filename"> 	Filename of the file. </param>
	/// <param name="watchlist">	The watchlist. </param>
	/// <param name="repo">			[in,out] The repo. </param>
	void build_watchlist_csv(string filename, vector <int> watchlist, Repository& repo);
};

