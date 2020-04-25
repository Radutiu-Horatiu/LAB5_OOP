#include "Repository.h"

using namespace std;

Repository::Repository()
{
}

Repository::~Repository()
{
}

bool Repository::add_film(string TITLE, string GENRE, string YEAR, string TRAILER, int ID)
{	
	if (!(v.validate_string(TITLE) == true and v.validate_string(GENRE) == true and
		v.validate_int(YEAR) == true and v.validate_uniqueness(ID) == true))
		return false;

	Film new_film(TITLE, GENRE, YEAR, TRAILER, ID);

	films.push_back(new_film);

	return true;
}