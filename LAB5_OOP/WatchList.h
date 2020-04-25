#pragma once
#include "Validate.h"
#include <vector>
#include "Film.h"
using namespace std;

class WatchList
{
private:

	vector<Film> watchlist;

public:

    vector<Film>& get_watchlist() { return watchlist; }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>    Removes the film from watchlist described by ID. </summary>
    ///
    /// <remarks>    Pinko, 4/25/2020. </remarks>
    ///
    /// <param name="ID">    The identifier of the film that is to be removed. </param>
    ///
    /// <returns>    True if it succeeds, false if it fails. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool remove_film_from_watchlist(int ID);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>    Adds a film to watchlist. </summary>
    ///
    /// <remarks>    Pinko, 4/25/2020. </remarks>
    ///
    /// <param name="filmToBeAdded">    The film to be added. </param>
    ///
    /// <returns>    True if it succeeds, false if it fails. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool add_film_to_watchlist(Film filmToBeAdded);

};

