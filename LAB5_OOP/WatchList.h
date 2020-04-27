#pragma once
#include <vector>
#include "Film.h"
#include "Repository.h"
using namespace std;

class WatchList
{
private:

	vector <int> watchlist;

public:

    vector <int>& get_watchlist() { return watchlist; }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>    Removes the film from watchlist described by ID. </summary>
    ///
    /// <remarks>    Pinko, 4/25/2020. </remarks>
    ///
    /// <param name="ID">    The identifier of the film that is to be removed. </param>
    ///
    /// <returns>    True if it succeeds, false if it fails. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool remove_film_from_watchlist(int id);

    /// <summary>	Adds a film to watchlist. </summary>
    ///
    /// <remarks>	Horatiu, 4/27/2020. </remarks>
    ///
    /// <param name="id">	The identifier. </param>
    ///
    /// <returns>	True if it succeeds, false if it fails. </returns>
    bool add_film_to_watchlist(int id);

    /// <summary>	Searches for the first film by identifier. </summary>
    ///
    /// <remarks>	Horatiu, 4/27/2020. </remarks>
    ///
    /// <param name="id">	The identifier. </param>
    ///
    /// <returns>	True if it succeeds, false if it fails. </returns>
    bool find_film_by_id(int id);
};

