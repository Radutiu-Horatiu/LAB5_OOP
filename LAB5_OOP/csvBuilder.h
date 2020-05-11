#pragma once
#include "WatchlistBuilder.h"
class csvBuilder : public WatchlistBuilder
{
	public:
	/// <summary>	Builds watchlist CSV. </summary>
	///
	/// <remarks>	Horatiu, 5/10/2020. </remarks>
	///
	/// <param name="filename"> 	Filename of the file. </param>
	/// <param name="watchlist">	The watchlist. </param>
	/// <param name="repo">			[in,out] The repo. </param>
	void build_watchlist(vector <int> watchlist, Repository& repo);
};

