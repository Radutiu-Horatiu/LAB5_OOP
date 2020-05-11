#pragma once
#include "Repository.h"
#include "WatchList.h"
#include <unordered_map>
#include "WatchlistBuilder.h"
using namespace std;

class Controller
{
private:

	Repository repo;
	WatchList watchlist;

	unordered_map <string, unique_ptr<WatchlistBuilder>> builderMap;


public:
	Controller();
	~Controller();

	/// <summary>	Admin add film to repository. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void admin_add_film_to_repository();

	/// <summary>	Admin delete film from repository. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void admin_delete_film_from_repository();

	/// <summary>	Admin update film from repository. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void admin_update_film_from_repository();

	/// <summary>	User show films by genres. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void user_show_films_by_genres();

	/// <summary>	User delete film from watchlist. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void user_delete_film_from_watchlist();

	/// <summary>	User show watchlist. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void user_show_watchlist();

	/// <summary>	User export to menu. </summary>
	///
	/// <remarks>	Horatiu, 5/11/2020. </remarks>

	void user_export_to_menu();
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of Controller.h
////////////////////////////////////////////////////////////////////////////////////////////////////

