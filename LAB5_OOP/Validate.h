#pragma once
#include <string>
#include <vector>
#include "Film.h"
#include "WatchList.h"
#include "Repository.h"
using namespace std;

class Validate
{
private:


public:

	/// <summary>	Validates if the given string is actually a string and not a string of integers. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="s">	The string. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	bool validate_string(string s);



	/// <summary>	Validates if the given string is actually an int or not. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="s">	The string. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	bool validate_int(string s);



	/// <summary>	Checks whether the ID is already occupied by one of the films of the Repository container or not. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="id_to_validate">	The identifier to validate. </param>
	/// <param name="films">	The Vector in which to look for IDs. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	bool validate_uniqueness(int id_to_validate, Repository& repo);



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Checks whether the ID is already occupied by one of the films of the Watchlist container or not. </summary>
	///
	/// <remarks>	Pinko, 4/27/2020. </remarks>
	///
	/// <param name="id_to_validate">	The identifier to validate. </param>
	/// <param name="watchlist">	 	[in,out] The watchlist. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	bool validate_uniqueness(int id_to_validate, WatchList& watchlist);



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Pinko, 4/27/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Validate();



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Pinko, 4/27/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	~Validate();
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of Validate.h
////////////////////////////////////////////////////////////////////////////////////////////////////

