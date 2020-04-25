#pragma once
#include "Controller.h"
#include "Film.h"
#include "Validate.h"
#include <vector>
#include <string>

using namespace std;

class Repository
{
private:
	vector <Film> films;
	Validate v;

public:

	vector <Film> get_films() { return films; }

	/// <summary>	Adds a film to the repository. Returns true if the film was successfully added, otherwise false. </summary>
	///
	/// <remarks>	Horatiu, 4/25/2020. </remarks>
	///
	/// <param name="t">   	Film title. </param>
	/// <param name="g">   	Film genre. </param>
	/// <param name="y">   	Year of appearance. </param>
	/// <param name="tr">  	Trailer link. </param>
	
	bool add_film(string TITLE, string GENRE, string YEAR, string TRAILER, int ID);

	Repository();
	~Repository();

};

