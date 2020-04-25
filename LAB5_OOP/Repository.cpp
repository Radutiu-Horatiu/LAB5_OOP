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
		v.validate_int(YEAR) == true and v.validate_uniqueness(ID,get_films()) == true))
		return false;

	Film new_film(TITLE, GENRE, YEAR, TRAILER, ID);

	films.push_back(new_film);

	return true;
}

bool Repository::remove_film(int ID)
{
	return false;
}

bool iequals(const string& a, const string& b)
{
    return equal(a.begin(), a.end(),
        b.begin(), b.end(),
        [](char a, char b) 
        {
            return tolower(a) == tolower(b);
        });
}

vector <Film> Repository::show_films_to_user(string GENRE)
{

    vector <Film> genreReturnVector;

    //Only do the search if FILMS Vector isn't empty.
    if (!get_films().empty())
    {

        if (iequals(GENRE, "none"))
        {
            //If GENRE is 'none', return WHOLE FILMS Vector.
            return get_films();
        }
        else
        {

            for (int i = 0; i < get_films().size(); i++)
            {
                if (iequals(GENRE, get_films()[i].get_genre()))
                {
                    //If film with given GENRE was found, add it to the FINAL RETURN VECTOR.
                    genreReturnVector.push_back(get_films()[i]);
                }
            }

            if (genreReturnVector.empty())
            {
                //If NO FILM found based on given GENRE, return WHOLE FILMS Vector.
                return get_films();
            }
            else
            {
                //If Films WERE FOUND with given GENRE, return the VECTOR CONTAINING them.
                return genreReturnVector;
            }

        }

    }
    else
    {
        return genreReturnVector; //If FILMS Vector is empty, return Empty Vector.
    }

}