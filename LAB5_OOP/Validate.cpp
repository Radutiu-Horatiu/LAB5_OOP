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

bool Validate::validate_uniqueness(int id_to_validate, vector <Film> films)
{
    //checks if the film already exists
    for (int i = 0; i < films.size(); i++)
        if (films[i].get_id() == id_to_validate)
            return false;

    return true;
}