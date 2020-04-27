#pragma once
#include "Film.h"
#include <vector>
#include <string>

using namespace std;

class Repository
{
private:

	vector <Film> films;

public:

	/// <summary>	Gets the films. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <returns>	The films. </returns>
	vector <Film>& get_films() { return films; }

	/// <summary>	Print films. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	void print_films(vector <Film> films);

	/// <summary>	Adds a film. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="TITLE">  	The title. </param>
	/// <param name="GENRE">  	The genre. </param>
	/// <param name="YEAR">   	The year. </param>
	/// <param name="TRAILER">	The trailer. </param>
	/// <param name="ID">	  	The identifier. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	bool add_film(string title, string genre, string year, string trailer, int id);

	/// <summary>	Removes the film described by ID. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="ID">	The identifier. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	bool remove_film(int id);

	/// <summary>	Updates the film. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="ID">		  	The identifier. </param>
	/// <param name="NEW_TITLE">  	The new title. </param>
	/// <param name="NEW_GENRE">  	The new genre. </param>
	/// <param name="NEW_YEAR">   	The new year. </param>
	/// <param name="NEW_TRAILER">	The new trailer. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	bool update_film(int id, string new_title, string new_genre, string new_year, string new_trailer);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>    Shows all the films (with the given Genre) to the user.
	///                If Genre is not valid, the function returns the whole list of films.
	/// </summary>
	///
	/// <remarks>    Pinko, 4/25/2020. </remarks>
	///
	/// <param name="GENRE">    The genre given as a string(Case Insensitive). </param>
	///
	/// <returns>    A vector of the found results. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	vector <Film> show_films_to_user(string genre);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>    Opens a given link in the default browser. </summary>
	///
	/// <remarks>    Pinko, 4/25/2020. </remarks>
	///
	/// <param name="LINK">    The link as a string. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void open_link_in_browser(string link);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Checks if the films vector is empty. </summary>
	///
	/// <remarks>	Pinko, 4/26/2020. </remarks>
	///
	/// <returns>	True if empty, false if not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	bool isEmpty();

	/// <summary>	Searches for the first film by identifier. </summary>
	///
	/// <remarks>	Horatiu, 4/27/2020. </remarks>
	///
	/// <param name="id">	The identifier. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	bool find_film_by_id(int id);

	/// <summary>	Gets film by identifier. </summary>
	///
	/// <remarks>	Horatiu, 4/27/2020. </remarks>
	///
	/// <param name="id">	The identifier. </param>
	///
	/// <returns>	The film by identifier. </returns>
	Film get_film_by_id(int id);

	//reading and writing within a file
	void write_file(vector <Film> v, string filename);
	void read_file(vector <Film>& v, string file);

	Repository();
	~Repository();

};

