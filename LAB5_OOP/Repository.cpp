#include "Repository.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Repository::Repository()
{
}

Repository::~Repository()
{
}

void Repository::print_films(vector <Film> films)
{
    for (int i = 0; i < films.size(); i++)
        cout << "id: " << films[i].get_id() << " title: " << films[i].get_title() << " genre: " << films[i].get_genre() <<
        " year: " << films[i].get_year() << " Likes: " << films[i].get_number_likes() << "\n";
}

bool Repository::add_film(string title, string genre, string year, string trailer, int id)
{	
    //checking if everything is good to go
	if (!(v.validate_string(genre) == true and
		v.validate_int(year) == true and v.validate_uniqueness(id, get_films()) == true))
		return false;

	Film new_film(title, genre, year, trailer, id);

	films.push_back(new_film);

	return true;
}

bool Repository::remove_film(int id)
{
    //film doesn t exist
    if (v.validate_uniqueness(id, get_films()) == true)
        return false;

	for (int i = 0; i < films.size(); i++)
        if (films[i].get_id() == id)
        {
            films.erase(films.begin() + i);
            return true;
        }
}

bool Repository::update_film(int id, string new_title, string new_genre, string new_year, string new_trailer)
{
    //film doesn t exist
    if (v.validate_uniqueness(id, get_films()))
        return false;

    for (int i = 0; i < films.size(); i++)
        if (films[i].get_id() == id)
        {
            films[i].set_title(new_title);
            films[i].set_genre(new_genre);
            films[i].set_year(new_year);
            films[i].set_trailer(new_trailer);
            return true;
        }
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

vector <Film> Repository::show_films_to_user(string genre)
{

    vector <Film> genreReturnVector;

    //Only do the search if FILMS Vector isn't empty.
    if (!get_films().empty())
    {

        if (iequals(genre, "none"))
        {
            //If genre is 'none', return WHOLE FILMS Vector.
            return get_films();
        }
        else
        {

            for (int i = 0; i < get_films().size(); i++)
            {
                if (iequals(genre, get_films()[i].get_genre()))
                {

                    //If film with given genre was found, add it to the FINAL RETURN VECTOR.
                    genreReturnVector.push_back(get_films()[i]);
                }
            }

            if (genreReturnVector.empty())
            {
                //If NO FILM found based on given genre, return WHOLE FILMS Vector.
                return get_films();
            }
            else
            {
                //If Films WERE FOUND with given genre, return the VECTOR CONTAINING them.
                return genreReturnVector;
            }

        }

    }
    else
    {
        return genreReturnVector; //If FILMS Vector is empty, return Empty Vector.
    }

}

void Repository::write_file(vector <Film> v, string filename)
{
    ofstream fin;
    fin.open(filename, ofstream::out | ofstream::trunc);

    for (int i = 0; i < v.size(); i++)
        fin << v[i].get_id() << " " << v[i].get_title() << " " << v[i].get_genre() << " " << v[i].get_number_likes() << " " << v[i].get_year() << 
        " " << v[i].get_trailer() << '\n';

    fin.close();
}

void Repository::read_file(vector <Film>& v, string file)
{

    ifstream myReadFile;
    string filename = file;
    myReadFile.open(filename.c_str());

    string title;
    string genre;
    string year;
    int number_likes;
    string trailer;
    int id;

    string temp;

    string::size_type sz;

    while (!myReadFile.eof())
    {
        Film f;

        myReadFile >> temp;
        if (temp != "")
        {
            id = stoi(temp, &sz);
            f.set_id(id);
        }

        myReadFile >> title;
        if (title != "")
            f.set_title(title);

        myReadFile >> genre;
        if (genre != "")
            f.set_genre(genre);

        myReadFile >> temp;
        if (temp != "")
        {
            number_likes = stoi(temp, &sz);
            f.set_number_likes(number_likes);
        }

        myReadFile >> year;
        if (year != "")
            f.set_year(year);

        myReadFile >> trailer;
        if (trailer != "")
            f.set_trailer(trailer);

        if (title != "")
            v.push_back(f);

    }

    if (v.size() > 0)
        v.erase(v.end() - 1);

    myReadFile.close();
   
}

void Repository::open_link_in_browser(string link)
{
    system(string("cmd /c start " + link).c_str());

    //cout << link << " Was opened!" << endl;
}

bool Repository::isEmpty()
{
    if (films.empty()) 
    {
        return true;
    }
    else
    {
        return false;
    }
}
