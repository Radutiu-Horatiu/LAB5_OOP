#include "Validate.h"

using namespace std;

Validate::Validate()
{
}

Validate::~Validate()
{
}

bool Validate::validate_int(string s)
{
  
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

bool Validate::validate_string(string s)
{
    if (Validate::validate_int(s) == false)
        return true;

    return false;
}

bool Validate::validate_uniqueness(int id_to_validate, Repository& repo)
{
    //checks if the film already exists
    if (repo.find_film_by_id(id_to_validate) == true)
        return false;

    return true;
}

bool Validate::validate_uniqueness(int id_to_validate, WatchList& watchlist)
{
    //checks if the film already exists
    if (watchlist.find_film_by_id(id_to_validate) == true)
        return false;

    return true;
}