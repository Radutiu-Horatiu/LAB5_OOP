#pragma once
#include <string>
#include <vector>
#include "Film.h"
using namespace std;

class Validate
{
private:


public:
	Validate();
	~Validate();

	/// <summary>	Validates the string described by s. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="s">	The string. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>

	bool validate_string(string s);

	/// <summary>	Validates the int described by integer. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="integer">	The integer. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>

	bool validate_int(string s);

	/// <summary>	Validates the uniqueness described by id_to_validate. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="id_to_validate">	The identifier to validate. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>

	bool validate_uniqueness(int id_to_validate, vector <Film> films);

};

